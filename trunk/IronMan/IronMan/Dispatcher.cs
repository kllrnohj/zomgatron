using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgentsAPI;

namespace IronMan
{
    static class Dispatcher
    {
        static private List<PhoneCallEvent> calls = new List<PhoneCallEvent>();
        static private List<Agent> availableAgents = new List<Agent>();
        static private List<Agent> allAgents = new List<Agent>();
        static public CallCenter CallCenter { get; set; }
        static private byte haveAvgsPlus = 0xF;
        static private byte SA = 0x8;
        static private byte SU = 0x4;
        static private byte B = 0x2;
        static private byte SP = 0x1;

        static public bool NeedsProcessing()
        {
            return (calls.Count > 0 && availableAgents.Count > 0);
        }

        static public void AddPhoneCall(PhoneCallEvent call)
        {
            calls.Add(call);
        }

        static public void RemoveAvailableAgent(Agent unavailable)
        {
            if (availableAgents.Contains(unavailable))
            {
                availableAgents.Remove(unavailable);
                haveAvgsPlus = 0xF;

                foreach (Agent agent in availableAgents)
                {
                    foreach (Skill s in agent.Skills)
                    {
                        if (s.ProficiencyLevel == ProficiencyLevel.Average || s.ProficiencyLevel == ProficiencyLevel.High)
                        {
                            switch (s.SkillType)
                            {
                                case SkillType.Billing:
                                    haveAvgsPlus &= (byte)(~B);
                                    break;
                                case SkillType.Sales:
                                    haveAvgsPlus &= (byte)(~SA);
                                    break;
                                case SkillType.Spanish:
                                    haveAvgsPlus &= (byte)(~SP);
                                    break;
                                case SkillType.Support:
                                    haveAvgsPlus &= (byte)(~SU);
                                    break;
                            }
                        }
                    }
                    if (haveAvgsPlus == 0)
                        break;
                }
            }
        }

        static public void AddAvailableAgent(Agent available)
        {
            availableAgents.Add(available);
            if (haveAvgsPlus != 0)
            {
                foreach (Skill s in available.Skills)
                {
                    if (s.ProficiencyLevel == ProficiencyLevel.Average || s.ProficiencyLevel == ProficiencyLevel.High)
                    {
                        switch (s.SkillType)
                        {
                            case SkillType.Billing:
                                haveAvgsPlus &= (byte)(~B);
                                break;
                            case SkillType.Sales:
                                haveAvgsPlus &= (byte)(~SA);
                                break;
                            case SkillType.Spanish:
                                haveAvgsPlus &= (byte)(~SP);
                                break;
                            case SkillType.Support:
                                haveAvgsPlus &= (byte)(~SU);
                                break;
                        }
                    }
                }
            }
        }

        static private int RateAgentOverall(Agent rated)
        {
            int result = 0;
            foreach (Skill s in rated.Skills)
            {
                result += HEnumToHInt(s.ProficiencyLevel);
            }
            return result;
        }

        static private bool HOneBetterThanHTwo(int one, int two, Agent a1, Agent a2)
        {
            if (one == two)
            {
                return RateAgentOverall(a1) < RateAgentOverall(a2) ? true : false;
            }
            if (one == 0)
                return true;
            if (two == 0)
                return false;

            if (two > 0 && one > 0)
            {
                return RateAgentOverall(a1) < RateAgentOverall(a2) ? true : false;
            }
            if (one > 0 && two < 0)
                return true;
            if (two > 0 && one < 0)
                return false;

            if (one < 0 && two < 0)
                return one > two;

            throw new Exception("Should not get here.");
            
        }

        static public void ProcessQueue()
        {
            int bestCallVal = int.MaxValue;
            int bestCallIndex = -1;
            Agent bestCallsAgent = null;
            for(int x = 0; x < calls.Count; x++)
            {
                int thisCallChoice;
                Agent temp = RouteCall(x, out thisCallChoice);
                if (bestCallsAgent == null)
                {
                    bestCallsAgent = temp;
                    bestCallVal = thisCallChoice;
                    bestCallIndex = x;
                }
                else if (HOneBetterThanHTwo(thisCallChoice, bestCallVal, temp, bestCallsAgent))
                {
                    bestCallsAgent = temp;
                    bestCallVal = thisCallChoice;
                    bestCallIndex = x;
                }
            }

            if (bestCallVal <= -3)
            {
                if (haveAvgsPlus == 0)
                    return;

                foreach (SkillType st in calls[bestCallIndex].SkillsNeeded)
                {
                    switch (st)
                    {
                        case SkillType.Billing:
                            if ((haveAvgsPlus & B) == B)
                                return;
                            break;
                        case SkillType.Sales:
                            if ((haveAvgsPlus & SA) == SA)
                                return;
                            break;
                        case SkillType.Spanish:
                            if ((haveAvgsPlus & SP) == SP)
                                return;
                            break;
                        case SkillType.Support:
                            if ((haveAvgsPlus & SU) == SU)
                                return;
                            break;
                    }
                }
            }
            if (bestCallsAgent != null)
            {
                Log.LogString(String.Format("Transferring AgentID:{0} to CallID:{1}", bestCallsAgent.AgentID, calls[bestCallIndex].PhoneCallID));
                PhoneCallEvent pce = calls[bestCallIndex];
                calls.RemoveAt(bestCallIndex);
                availableAgents.Remove(bestCallsAgent);
                CallCenter.TransferCall(pce.PhoneCallID, bestCallsAgent.AgentID);

                if (NeedsProcessing())
                    ProcessQueue();
            }
        }

        static private int HEnumToHInt(ProficiencyLevel pl)
        {
            switch (pl)
            {
                case ProficiencyLevel.Average:
                    return 2;
                case ProficiencyLevel.High:
                    return 4;
                case ProficiencyLevel.Low:
                    return 1;
                default:
                    return 1;
            }
        }
        static private int HRateAgent(int callIndex, int agentIndex)
        {
            int awesomeness = 1;

            foreach (SkillType s in calls[callIndex].SkillsNeeded)
            {
                bool found = false;
                for (int x = 0; x < availableAgents[agentIndex].Skills.Count; x++)
                {
                    if (availableAgents[agentIndex].Skills[x].SkillType == s)
                    {
                        awesomeness *= HEnumToHInt(availableAgents[agentIndex].Skills[x].ProficiencyLevel);
                        found = true;
                    }
                }
                if (!found)
                    return -1;
            }

            return (awesomeness - 4);
        }

        static private Agent RouteCall(int callIndex, out int agentStrength)
        {
            int curBest = int.MinValue;
            agentStrength = int.MinValue;
            Agent best = null;
            for(int x = 0; x < availableAgents.Count; x++)
            {
                int val = HRateAgent(callIndex, x);
                if (val == -1)
                    continue;
                if (best == null)
                {
                    best = availableAgents[x];
                    agentStrength = val;
                    curBest = val;
                }
                else
                {
                    if (HOneBetterThanHTwo(val, curBest, availableAgents[x], best))
                    {
                        best = availableAgents[x];
                        agentStrength = val;
                        curBest = val;
                    }
                }
            }

            return best;
        }
    }
}