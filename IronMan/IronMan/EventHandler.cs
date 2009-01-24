﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgentsAPI;

namespace IronMan
{
    class EventHandler : IAgentStatusObserver, IPhoneCallObserver
    {
        public CallCenter CallCenter { get; set; }
        private Dictionary<int, Agent> agents;

        public EventHandler(CallCenter callCenter)
        {
            CallCenter = callCenter;
            agents = new Dictionary<int, Agent>();
            CallCenter.RegisterAgentStatusObserver(this);
            CallCenter.RegisterPhoneCallObserver(this);
        }

        #region IPhoneCallObserver Members

        public void PhoneCallReceived(PhoneCallEvent callDetails)
        {
            throw new NotImplementedException();
        }

        #endregion

        #region IAgentStatusObserver Members

        public void AgentStatusChanged(Agent agent)
        {
            throw new NotImplementedException();
        }

        #endregion
    }
}
