using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgentsAPI;

namespace IronMan
{
    static class Dispatcher
    {
        static int HRateAgent(PhoneCallEvent call, Agent agent)
        {
            return -1;
        }

        static void RouteCall(PhoneCallEvent call, List<Agent> agents)
        {
            foreach (Agent agent in agents)
            {
                
            }
        }
    }
}
