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
            string skills = "";
            foreach (var s in callDetails.SkillsNeeded)
                skills += s + ",";
            Log.LogString(String.Format("Receiving Call: {0}, {1}, {2}", callDetails.PhoneCallID, callDetails.IsTransfered, skills));
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
            string skills = "";
            foreach (var s in agent.Skills)
                skills += String.Format("{0}:{1} ", s.SkillType, s.ProficiencyLevel);
            Log.LogString(String.Format("Agent Status Changed: {0}, {1}, {2}", agent.AgentID, agent.AgentStatusType, skills));
            if (agent.AgentStatusType == AgentStatusType.Available)
                Dispatcher.AddAvailableAgent(agent);
            OnAgentStatusChanged(this, new AgentStatusChangedEventArguments() { Agent = agent });
            
            if (Dispatcher.NeedsProcessing())
                Dispatcher.ProcessQueue();

            if (CallCenter.CallsCompleted == CallCenter.TotalCalls)
            {
                Log.LogString(String.Format("Calls: {0}, Score: {1}, Penalty: {2}", CallCenter.TotalCalls, CallCenter.TotalScore, CallCenter.TotalPenaltyTime));
                System.Windows.Forms.MessageBox.Show("Done!");
            }
        }

        #endregion
    }
}
