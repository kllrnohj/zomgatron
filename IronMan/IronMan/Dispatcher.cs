using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgentsAPI;

namespace IronMan
{
    class AgentNotFoundException : Exception { }

    static class Dispatcher
    {
        static int HEnumToHInt(ProficiencyLevel pl)
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
        static int HRateAgent(PhoneCallEvent call, Agent agent)
        {
            int awesomeness = (agent.AgentStatusType == AgentStatusType.Unavailable || agent.AgentStatusType == AgentStatusType.OnCall) ? 0 : 1;

            foreach (Skill s in call.SkillsNeeded)
            {
                if(agent.Skills.Contains(s)){
                    awesomeness *= HEnumToHInt(agent.Skills[agent.Skills.IndexOf(s)].ProficiencyLevel);
                }
            }

            return awesomeness;
        }

        static void RouteCall(CallCenter callcenter, PhoneCallEvent call, List<Agent> agents)
        {
            int highest = 0;
            Agent best = null;
            foreach (Agent agent in agents)
            {
                if (HRateAgent(call, agent) > highest || best == null)
                    best = agent;

            }

            if (best == null)
                throw new AgentNotFoundException("Could not find appropriate Agent for call routing.");

            callcenter.TransferCall(call.PhoneCallID, best.AgentID);
        }
    }
}
