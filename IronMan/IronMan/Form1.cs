using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using AgentsAPI;
namespace IronMan
{
    public partial class NUIronManForm : Form
    {
        private AgentsAPIEventHandler AgentsEventHandler { get; set; }
        private AgentsAPI.CallCenter CallCenter { get; set; }
        bool done = false;

        public NUIronManForm()
        {
            InitializeComponent();
        }



        private void ProccessQueueTimer_Tick(object sender, EventArgs e)
        {
            if (done) return;
            if (CallCenter.CallsCompleted == CallCenter.TotalCalls)
            {
                Log.LogString(String.Format("Calls: {0}, Score: {1}, Penalty: {2}", CallCenter.TotalCalls, CallCenter.TotalScore, CallCenter.TotalPenaltyTime));
                System.Windows.Forms.MessageBox.Show("Done!");
                ProccessQueueTimer.Enabled = false;
                done = true;
            }
            if (Dispatcher.NeedsProcessing())
            {
                ProccessQueueTimer.Enabled = false;
                Dispatcher.ProcessQueue();
                ProccessQueueTimer.Enabled = true;
            }
        }

        private void NUIronManForm_Load(object sender, EventArgs e)
        {
            CallCenter = new AgentsAPI.CallCenter();
            AgentsEventHandler = new AgentsAPIEventHandler(CallCenter);
            AgentsEventHandler.OnAgentStatusChanged += new EventHandler<AgentStatusChangedEventArguments>(AgentsEventHandler_OnAgentStatusChanged);
            AgentsEventHandler.OnPhoneCall += new EventHandler<PhoneCallEventArguments>(AgentsEventHandler_OnPhoneCall);

            CallCenter.StartSimulator();
        }

        void AgentsEventHandler_OnPhoneCall(object sender, PhoneCallEventArguments e)
        {
            if (!lbCalls.Items.Contains(e.PhoneCallEvent))
                lbCalls.Items.Add(e.PhoneCallEvent);
            lbCalls.DisplayMember = "PhoneCallID";

            //var List<int> agentIDs  = from avg in lbCalls.Items
            //        where avg.

            //update the Stats GroupBox
            // lblPendingCallsValue.Text =
        }

        void AgentsEventHandler_OnAgentStatusChanged(object sender, AgentStatusChangedEventArguments e)
        {
            if (!lbAgents.Items.Contains(e.Agent))
                lbAgents.Items.Add(e.Agent);
            lbAgents.DisplayMember = "AgentID";

            //update anything that relies on the agent

        }

        private void lbAgents_SelectedIndexChanged(object sender, EventArgs e)
        {
            Agent agent = lbAgents.SelectedItem as Agent;
            List<PhoneCallEvent> meList = new List<PhoneCallEvent>();

            foreach (object o in lbCalls.Items)
                meList.Add(o as PhoneCallEvent);

            //get the total number of calls 

            int totalCalls = (from tc in meList
                                       where tc.AgentID == agent.AgentID
                                       select tc).Count();
           /* int totalTime = (from tc in meList
                             where tc.AgentID == agent.AgentID
                             select meList.Sum(n =>  = tc.AgentID);*/

            lblTotalCallsValue.Text = totalCalls.ToString();
            BindAgent(agent);
        }

        private void lbCalls_SelectedIndexChanged(object sender, EventArgs e)
        {
            PhoneCallEvent call = lbCalls.SelectedItem as PhoneCallEvent;
            BindCall(call);
        }






    }
}
