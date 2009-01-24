using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgentsAPI;
using System.Reflection;

namespace IronMan
{
    class PhoneCallEventArguments : EventArgs
    {
        public PhoneCallEvent PhoneCallEvent { get; set; }
    }

    class AgentStatusChangedEventArguments : EventArgs
    {
        public AgentContainer Agent { get; set; }
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
            int len = (int)callDetails.GetType().GetProperty("MaxCallLength", BindingFlags.Instance | BindingFlags.NonPublic).GetValue(callDetails, null);
            string skills = "";
            foreach (var s in callDetails.SkillsNeeded)
                skills += s + ",";
            Log.LogString(String.Format("Receiving Call: {0}, {1}, {2}", callDetails.PhoneCallID, callDetails.IsTransfered, skills));
            if (!callDetails.IsTransfered)
                Dispatcher.AddPhoneCall(callDetails);

            if (Dispatcher.NeedsProcessing())
                Dispatcher.ProcessQueue();

            OnPhoneCall(this, new PhoneCallEventArguments() { PhoneCallEvent = callDetails });
        }

        #endregion

        #region IAgentStatusObserver Members

        public void AgentStatusChanged(Agent agent)
        {
            string skills = "";
            foreach (var s in agent.Skills)
                skills += String.Format("{0}:{1} ", s.SkillType, s.ProficiencyLevel);
            Log.LogString(String.Format("Agent Status Changed: {0}, {1}, {2}", agent.AgentID, agent.AgentStatusType, skills));
            if (agent.AgentStatusType == AgentStatusType.Available)
                Dispatcher.AddAvailableAgent(agent);
            if (agent.AgentStatusType == AgentStatusType.Unavailable)
                Dispatcher.RemoveAvailableAgent(agent);
            
            if (Dispatcher.NeedsProcessing())
                Dispatcher.ProcessQueue();

            OnAgentStatusChanged(this, new AgentStatusChangedEventArguments() { Agent = new AgentContainer() { Agent = agent } });
        }

        #endregion
    }
}
