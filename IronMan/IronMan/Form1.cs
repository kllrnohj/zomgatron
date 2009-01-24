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

        private void lbCalls_SelectedIndexChanged(object sender, EventArgs e)
        {

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
            //AgentsEventHandler.On
        }


        
    }
}
