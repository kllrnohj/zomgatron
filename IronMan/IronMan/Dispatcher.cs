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

        static public bool NeedsProcessing()
        {
            return (calls.Count > 0 && availableAgents.Count > 0);
        }

        static public void AddPhoneCall(PhoneCallEvent call)
        {
            calls.Add(call);
        }

        static public void AddAvailableAgent(Agent available)
        {
            availableAgents.Add(available);
        }

        static public void ProcessQueue()
        {
            int bestCallVal = 0;
            int bestCallIndex = -1;
            for(int x = 0; x < calls.Count; x++)
            {
                int thisCallChoice;
            }
        }

        static public int HEnumToHInt(ProficiencyLevel pl)
        {
            switch (pl)
            {
                case ProficiencyLevel.Average:
                    return 4;
                    break;
                case ProficiencyLevel.High:
                    return 8;
                    break;
                case ProficiencyLevel.Low:
                    return 2;
                    break;
                default:
                    return 1;
            }
        }
        static public int HRateAgent(int callIndex, int agentIndex)
        {
            int awesomeness = (availableAgents[agentIndex].AgentStatusType == AgentStatusType.Unavailable || availableAgents[agentIndex].AgentStatusType == AgentStatusType.OnCall) ? 0 : 1;

            foreach (Skill s in calls[callIndex].SkillsNeeded)
            {
                if(availableAgents[agentIndex].Skills.Contains(s)){
                    awesomeness *= HEnumToHInt(availableAgents[agentIndex].Skills[availableAgents[agentIndex].Skills.IndexOf(s)].ProficiencyLevel);
                }
            }

            return awesomeness;
        }

        static public Agent RouteCall(CallCenter callcenter, int callIndex, out int agentStrength)
        {
            int highest = 0;
            Agent best = null;
            for(int x = 0; x < availableAgents.Count; x++)
            {
                int val = HRateAgent(callIndex, x); 
                if (val > highest || best == null)
                {
                    best = availableAgents[x];
                    highest = val;
                }

            }

            agentStrength = highest;
            return best;
        }
    }
}