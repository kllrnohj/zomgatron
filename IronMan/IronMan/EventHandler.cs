using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgentsAPI;

namespace IronMan
{
    class EventHandler : IAgentStatusObserver, IPhoneCallObserver
    {


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
