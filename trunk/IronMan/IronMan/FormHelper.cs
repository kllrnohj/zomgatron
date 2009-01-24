using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using AgentsAPI;
using System.Windows.Forms.DataVisualization.Charting;
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

                dgvAgentSkills.DataSource = agent.Skills;

                lblAgentIDValue.Text = agent.AgentID.ToString();
                lblAgentStatusValue.Text = agent.AgentStatusType.ToString();
            }
        }
        /// <summary>
        /// Extract the phone call info from call and updates the labels.
        /// </summary>
        /// <param name="call"></param>
        private void BindCall(PhoneCallEvent call)
        {
            if (call != null)
            {
                TimeSpan t;
                //clear the required skills listbox and then populate the fields
                lbRequiredSkills.Items.Clear();
                foreach (SkillType s in call.SkillsNeeded)
                    lbRequiredSkills.Items.Add(s);

                lblCallIDValue.Text = call.PhoneCallID.ToString();
                lblCallAgentIDValue.Text = call.AgentID.ToString();


                lblCallDurationValue.Text = FormatMSToTime(call.PhoneCallLength);

                lblWaitTimeValue.Text = FormatMSToTime(call.WaitTimeLength);
            }
        }
        /// <summary>
        /// Convert the milliseconds from the API to a common format
        /// </summary>
        /// <param name="ms"></param>
        /// <returns></returns>
        public string FormatMSToTime(long ms)
        {
            TimeSpan t = TimeSpan.FromMilliseconds((double)ms);

            return string.Format("{0:D2}h:{1:D2}m:{2:D2}s", t.Hours, t.Minutes, t.Seconds);
        }

        private void UpdateAgent()
        {

        }
        /// <summary>
        /// Generate the data based on what string was passed in.
        /// </summary>
        /// <param name="dataToGenerate"></param>
        private void UpdateData(string dataToGenerate)
        {
           // MessageBox.Show(dataToGenerate);
            switch (dataToGenerate)
            {
                case "AvgWaitTime":
                    GenerateWaitTimeDataPoints();
                    
                    break;
                case "AvgCallTime":
                    GenerateCallTimeDataPoints();
                    break;
            }
        }
        /// <summary>
        /// Generate the datapoints for the average waittime.
        /// </summary>
        /// <returns></returns>
        private List<DataPoint> GenerateWaitTimeDataPoints()
        {
            List<PhoneCallEvent> meList = new List<PhoneCallEvent>();
            List<DataPoint> dataPoints = new List<DataPoint>();
            
            foreach (object o in lbCalls.Items)
                meList.Add(o as PhoneCallEvent);
            meList.ToArray<PhoneCallEvent>();
            double i = 0.0;
            foreach (PhoneCallEvent pce in meList)
                series1.Points.Add(new DataPoint(i++, (double)pce.WaitTimeLength));
           
            return dataPoints;
        }
        /// <summary>
        /// Generate all of the datapoints for the average calltime
        /// </summary>
        /// <returns></returns>
        private List<DataPoint> GenerateCallTimeDataPoints()
        {
            List<PhoneCallEvent> meList = new List<PhoneCallEvent>();
            List<DataPoint> dataPoints = new List<DataPoint>();

            foreach (object o in lbCalls.Items)
                meList.Add(o as PhoneCallEvent);
            meList.ToArray<PhoneCallEvent>();
            double i = 0.0;
            foreach (PhoneCallEvent pce in meList)
                series1.Points.Add(new DataPoint(i++, (double)pce.PhoneCallLength));

            return dataPoints;
        }
    }
}
