using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using AgentsAPI;

namespace IronMan
{
    partial class NUIronManForm : Form
    {
        /// <summary>
        /// Extracts the data from the agent and updates the labels
        /// </summary>
        /// <param name="agent"></param>
        private void BindAgent(Agent agent)
        {
            if (agent != null)
            {
                lbSkills.Items.Clear();

                dgvAgentSkills.DataSource = agent.Skills;
              
                lblAgentIDValue.Text = agent.AgentID.ToString();
                lblAgentStatusValue.Text = agent.AgentStatusType.ToString() ;
            }
        }
        /// <summary>
        /// Extract the phone call info from call and updates the labels.
        /// </summary>
        /// <param name="call"></param>
        private void BindCall(PhoneCallEvent call)
        {

            //clear the required skills listbox and then populate the fields
            lbRequiredSkills.Items.Clear();
            foreach (SkillType s in call.SkillsNeeded)
                lbRequiredSkills.Items.Add(s);
            lblCallIDValue.Text = call.PhoneCallID.ToString();
            lblCallAgentIDValue.Text = call.AgentID.ToString();
            lblCallDurationValue.Text = call.PhoneCallLength.ToString();
            lblWaitTimeValue.Text = call.WaitTimeLength.ToString();

           
        }

    }
}
