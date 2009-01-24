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
    public class AgentContainer
    {
        public Agent Agent { get; set; }
        public override string ToString()
        {
            return String.Format("{0}: {1}", Agent.AgentID, Agent.AgentStatusType);
        }

        public override bool Equals(object obj)
        {
            try
            {
                var other = (AgentContainer)obj;
                return Agent.AgentID == other.Agent.AgentID;
            }
            catch (Exception)
            {
                return false;
            }
        }
    }

    public partial class NUIronManForm : Form
    {
        private AgentsAPIEventHandler AgentsEventHandler { get; set; }
        private AgentsAPI.CallCenter CallCenter { get; set; }

        public NUIronManForm()
        {
            InitializeComponent();
        }



        private void ProccessQueueTimer_Tick(object sender, EventArgs e)
        {
            if (!ProccessQueueTimer.Enabled)
                return;
            if (CallCenter.CallsCompleted == (CallCenter.TotalCalls - 1))
            {
                ProccessQueueTimer.Enabled = false;
                string message = String.Format("Completed: {0} calls in {1} ms with {2} penalty", CallCenter.TotalCalls, CallCenter.TotalScore, CallCenter.TotalPenaltyTime);
                Log.LogString(message);
                MessageBox.Show(message);
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

            if (lbAgents.SelectedValue == null) return;
            //update the stats
            Agent agent = (lbAgents.SelectedItem as AgentContainer).Agent;
            long totalTime = 0, totalWait = 0;

            List<PhoneCallEvent> meList = new List<PhoneCallEvent>();

            foreach (object o in lbCalls.Items)
                meList.Add(o as PhoneCallEvent);


            //get the total number of calls 
            int totalCalls = (from tc in meList select tc).Count();
            
            //get the total time for and the total wait time
            totalTime = (from tc in meList select meList.Sum(n => tc.PhoneCallLength)).FirstOrDefault<long>();
            totalWait = (from tc in meList select meList.Sum(n => tc.WaitTimeLength)).FirstOrDefault<long>();

            //find out if there are any unassigned phone calls

            lblPendingCallsValue.Text = (from tc in meList where tc.AgentID == 0 select tc).Count().ToString();

            //now assign the variables
            if (totalCalls > 0) {
                lblAvgCallTimeValue.Text = FormatMSToTime(totalTime / totalCalls);
                lblAvgWaitValue.Text = FormatMSToTime(totalWait / totalCalls);
            }
            else
                lblAvgCallTimeValue.Text = "N/A";

        }

        void AgentsEventHandler_OnAgentStatusChanged(object sender, AgentStatusChangedEventArguments e)
        {
            if (!lbAgents.Items.Contains(e.Agent))
                lbAgents.Items.Add(e.Agent);
            else
            {
                int indx = lbAgents.Items.IndexOf(e.Agent);
                lbAgents.Items[indx] = lbAgents.Items[indx];
            }
        }

        private void lbAgents_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (lbAgents.SelectedItem == null) return;
            Agent agent = (lbAgents.SelectedItem as AgentContainer).Agent;
            List<PhoneCallEvent> meList = new List<PhoneCallEvent>();

            foreach (object o in lbCalls.Items)
                meList.Add(o as PhoneCallEvent);

            //get the total number of calls 
            int totalCalls = (from tc in meList
                              where tc.AgentID == agent.AgentID
                              select tc).Count();
            long totalTime = 0;

            totalTime = (from tc in meList
                         where tc.AgentID == agent.AgentID
                         select meList.Sum(n => tc.PhoneCallLength)).FirstOrDefault<long>();

            if (totalCalls > 0)
                lblAvgAgentCallTimeValue.Text = FormatMSToTime(totalTime / totalCalls);
            else
                lblAvgAgentCallTimeValue.Text = "N/A";

            lblTotalCallsValue.Text = totalCalls.ToString();
            BindAgent(agent);
        }

        private void lbCalls_SelectedIndexChanged(object sender, EventArgs e)
        {
            PhoneCallEvent call = lbCalls.SelectedItem as PhoneCallEvent;
            BindCall(call);
        }

        private void dgvAvailableSkills_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }






    }
}
