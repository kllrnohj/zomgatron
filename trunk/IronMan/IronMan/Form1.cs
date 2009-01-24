using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace IronMan
{
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
            //lbAgent.

        }

        void AgentsEventHandler_OnPhoneCall(object sender, PhoneCallEventArguments e)
        {
            if (lbCalls.Items.Contains(e.PhoneCallEvent))
                lbCalls.Items.Add(e.PhoneCallEvent);
        }

        void AgentsEventHandler_OnAgentStatusChanged(object sender, AgentStatusChangedEventArguments e)
        {
            if (!lbAgents.Items.Contains(e.Agent))
                lbAgents.Items.Add(e.Agent);
            lbAgents.DisplayMember = "AgentID";

        }

        private void lbAgents_SelectedIndexChanged(object sender, EventArgs e)
        {
            //BindAgent();
        }
        private void lbCalls_SelectedIndexChanged(object sender, EventArgs e)
        {
            //BindCall();
        }



    }
}
