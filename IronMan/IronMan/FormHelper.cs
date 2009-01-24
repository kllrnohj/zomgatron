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
                //reset the listbox and then update the info
                lbSkills.Items.Clear();
                if (agent.Skills != null)
                    foreach (Skill s in agent.Skills)
                        lbSkills.Items.Add(s);

                dgvAvailableSkills.DataSource = agent.Skills;
                // dgvAvailableSkills.
                lblAgentIDValue.Text = agent.AgentID.ToString();
                //lblAgentStatusValue = agent.AgentStatusType;

            }
        }
        /// <summary>
        /// Extract the phone call info from call and updates the labels.
        /// </summary>
        /// <param name="call"></param>
        private void BindCall(PhoneCallEvent call)
        {

        }

    }
}
