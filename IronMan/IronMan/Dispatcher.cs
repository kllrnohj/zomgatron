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
        static int HRateAgent(PhoneCallEvent call, Agent agent)
        {

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
