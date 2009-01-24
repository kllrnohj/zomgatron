using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgentsAPI;

namespace IronMan
{
    class PhoneCallEventArguments : EventArgs
    {
        public PhoneCallEvent PhoneCallEvent { get; set; }
    }

    class AgentStatusChangedEventArguments : EventArgs
    {
        public Agent Agent { get; set; }
    }

    class AgentsAPIEventHandler : IAgentStatusObserver, IPhoneCallObserver
    {
        public CallCenter CallCenter { get; set; }
        public event EventHandler<PhoneCallEventArguments> OnPhoneCall;
        public event EventHandler<AgentStatusChangedEventArguments> OnAgentStatusChanged;

        public AgentsAPIEventHandler(CallCenter callCenter)
        {
            CallCenter = callCenter;
            Dispatcher.CallCenter = callCenter;
            CallCenter.RegisterAgentStatusObserver(this);
            CallCenter.RegisterPhoneCallObserver(this);
        }

        #region IPhoneCallObserver Members

        public void PhoneCallReceived(PhoneCallEvent callDetails)
        {
            if (!callDetails.IsTransfered)
                Dispatcher.AddPhoneCall(callDetails);
            OnPhoneCall(this, new PhoneCallEventArguments() { PhoneCallEvent = callDetails });

            if (Dispatcher.NeedsProcessing())
                Dispatcher.ProcessQueue();
        }

        #endregion

        #region IAgentStatusObserver Members

        public void AgentStatusChanged(Agent agent)
        {
            if (agent.AgentStatusType == AgentStatusType.Available)
                Dispatcher.AddAvailableAgent(agent);
            OnAgentStatusChanged(this, new AgentStatusChangedEventArguments() { Agent = agent });
            
            if (Dispatcher.NeedsProcessing())
                Dispatcher.ProcessQueue();
        }

        #endregion
    }
}
