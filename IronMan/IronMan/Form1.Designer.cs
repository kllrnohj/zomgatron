namespace IronMan
{
    partial class NUIronManForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea4 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend4 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series4 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.lbCalls = new System.Windows.Forms.ListBox();
            this.lbAgents = new System.Windows.Forms.ListBox();
            this.lblAvgWait = new System.Windows.Forms.Label();
            this.gbCallInfo = new System.Windows.Forms.GroupBox();
            this.lbRequiredSkills = new System.Windows.Forms.ListBox();
            this.lblCallIDValue = new System.Windows.Forms.Label();
            this.lblCallID = new System.Windows.Forms.Label();
            this.lblWaitTimeValue = new System.Windows.Forms.Label();
            this.lblCallDurationValue = new System.Windows.Forms.Label();
            this.lblCallAgentIDValue = new System.Windows.Forms.Label();
            this.lblCallWaitTime = new System.Windows.Forms.Label();
            this.lblDuration = new System.Windows.Forms.Label();
            this.lblCallAgent = new System.Windows.Forms.Label();
            this.gbAgentInfo = new System.Windows.Forms.GroupBox();
            this.lblAvgAgentCallTimeValue = new System.Windows.Forms.Label();
            this.lblAvgCallTime = new System.Windows.Forms.Label();
            this.dgvAgentSkills = new System.Windows.Forms.DataGridView();
            this.lblAgentIDValue = new System.Windows.Forms.Label();
            this.lblAgentStatusValue = new System.Windows.Forms.Label();
            this.lblStatus = new System.Windows.Forms.Label();
            this.lblID = new System.Windows.Forms.Label();
            this.lblTotalCallsValue = new System.Windows.Forms.Label();
            this.lblTotalCalls = new System.Windows.Forms.Label();
            this.lblAvgWaitValue = new System.Windows.Forms.Label();
            this.gbStats = new System.Windows.Forms.GroupBox();
            this.lblPendingCallsValue = new System.Windows.Forms.Label();
            this.lblPendingCalls = new System.Windows.Forms.Label();
            this.lblAvgCallTimeValue = new System.Windows.Forms.Label();
            this.lblAvgCallDuration = new System.Windows.Forms.Label();
            this.ProccessQueueTimer = new System.Windows.Forms.Timer(this.components);
            this.gbVisualizer = new System.Windows.Forms.GroupBox();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.gpGraphSettings = new System.Windows.Forms.GroupBox();
            this.checkBEnable3D = new System.Windows.Forms.CheckBox();
            this.cbData = new System.Windows.Forms.ComboBox();
            this.lblData = new System.Windows.Forms.Label();
            this.checkBMarkers = new System.Windows.Forms.CheckBox();
            this.cbLighting = new System.Windows.Forms.ComboBox();
            this.lblLighting = new System.Windows.Forms.Label();
            this.lblPhoneID = new System.Windows.Forms.Label();
            this.lblAgentID = new System.Windows.Forms.Label();
            this.gbCallInfo.SuspendLayout();
            this.gbAgentInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvAgentSkills)).BeginInit();
            this.gbStats.SuspendLayout();
            this.gbVisualizer.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            this.gpGraphSettings.SuspendLayout();
            this.SuspendLayout();
            // 
            // lbCalls
            // 
            this.lbCalls.FormattingEnabled = true;
            this.lbCalls.Location = new System.Drawing.Point(3, 39);
            this.lbCalls.Name = "lbCalls";
            this.lbCalls.Size = new System.Drawing.Size(176, 498);
            this.lbCalls.TabIndex = 0;
            this.lbCalls.SelectedIndexChanged += new System.EventHandler(this.lbCalls_SelectedIndexChanged);
            // 
            // lbAgents
            // 
            this.lbAgents.FormattingEnabled = true;
            this.lbAgents.Location = new System.Drawing.Point(195, 39);
            this.lbAgents.Name = "lbAgents";
            this.lbAgents.Size = new System.Drawing.Size(183, 498);
            this.lbAgents.TabIndex = 1;
            this.lbAgents.SelectedIndexChanged += new System.EventHandler(this.lbAgents_SelectedIndexChanged);
            // 
            // lblAvgWait
            // 
            this.lblAvgWait.AutoSize = true;
            this.lblAvgWait.Location = new System.Drawing.Point(6, 51);
            this.lblAvgWait.Name = "lblAvgWait";
            this.lblAvgWait.Size = new System.Drawing.Size(54, 13);
            this.lblAvgWait.TabIndex = 2;
            this.lblAvgWait.Text = "Avg Wait:";
            // 
            // gbCallInfo
            // 
            this.gbCallInfo.Controls.Add(this.lbRequiredSkills);
            this.gbCallInfo.Controls.Add(this.lblCallIDValue);
            this.gbCallInfo.Controls.Add(this.lblCallID);
            this.gbCallInfo.Controls.Add(this.lblWaitTimeValue);
            this.gbCallInfo.Controls.Add(this.lblCallDurationValue);
            this.gbCallInfo.Controls.Add(this.lblCallAgentIDValue);
            this.gbCallInfo.Controls.Add(this.lblCallWaitTime);
            this.gbCallInfo.Controls.Add(this.lblDuration);
            this.gbCallInfo.Controls.Add(this.lblCallAgent);
            this.gbCallInfo.Location = new System.Drawing.Point(897, 13);
            this.gbCallInfo.Name = "gbCallInfo";
            this.gbCallInfo.Size = new System.Drawing.Size(338, 118);
            this.gbCallInfo.TabIndex = 3;
            this.gbCallInfo.TabStop = false;
            this.gbCallInfo.Text = "Call Info";
            // 
            // lbRequiredSkills
            // 
            this.lbRequiredSkills.FormattingEnabled = true;
            this.lbRequiredSkills.Location = new System.Drawing.Point(147, 26);
            this.lbRequiredSkills.Name = "lbRequiredSkills";
            this.lbRequiredSkills.Size = new System.Drawing.Size(180, 82);
            this.lbRequiredSkills.TabIndex = 10;
            // 
            // lblCallIDValue
            // 
            this.lblCallIDValue.AutoSize = true;
            this.lblCallIDValue.Location = new System.Drawing.Point(75, 30);
            this.lblCallIDValue.Name = "lblCallIDValue";
            this.lblCallIDValue.Size = new System.Drawing.Size(27, 13);
            this.lblCallIDValue.TabIndex = 9;
            this.lblCallIDValue.Text = "N/A";
            // 
            // lblCallID
            // 
            this.lblCallID.AutoSize = true;
            this.lblCallID.Location = new System.Drawing.Point(6, 30);
            this.lblCallID.Name = "lblCallID";
            this.lblCallID.Size = new System.Drawing.Size(41, 13);
            this.lblCallID.TabIndex = 8;
            this.lblCallID.Text = "Call ID:";
            // 
            // lblWaitTimeValue
            // 
            this.lblWaitTimeValue.AutoSize = true;
            this.lblWaitTimeValue.Location = new System.Drawing.Point(75, 95);
            this.lblWaitTimeValue.Name = "lblWaitTimeValue";
            this.lblWaitTimeValue.Size = new System.Drawing.Size(27, 13);
            this.lblWaitTimeValue.TabIndex = 7;
            this.lblWaitTimeValue.Text = "N/A";
            // 
            // lblCallDurationValue
            // 
            this.lblCallDurationValue.AutoSize = true;
            this.lblCallDurationValue.Location = new System.Drawing.Point(75, 73);
            this.lblCallDurationValue.Name = "lblCallDurationValue";
            this.lblCallDurationValue.Size = new System.Drawing.Size(27, 13);
            this.lblCallDurationValue.TabIndex = 6;
            this.lblCallDurationValue.Text = "N/A";
            // 
            // lblCallAgentIDValue
            // 
            this.lblCallAgentIDValue.AutoSize = true;
            this.lblCallAgentIDValue.Location = new System.Drawing.Point(75, 52);
            this.lblCallAgentIDValue.Name = "lblCallAgentIDValue";
            this.lblCallAgentIDValue.Size = new System.Drawing.Size(27, 13);
            this.lblCallAgentIDValue.TabIndex = 5;
            this.lblCallAgentIDValue.Text = "N/A";
            // 
            // lblCallWaitTime
            // 
            this.lblCallWaitTime.AutoSize = true;
            this.lblCallWaitTime.Location = new System.Drawing.Point(6, 95);
            this.lblCallWaitTime.Name = "lblCallWaitTime";
            this.lblCallWaitTime.Size = new System.Drawing.Size(58, 13);
            this.lblCallWaitTime.TabIndex = 3;
            this.lblCallWaitTime.Text = "Wait Time:";
            // 
            // lblDuration
            // 
            this.lblDuration.AutoSize = true;
            this.lblDuration.Location = new System.Drawing.Point(6, 73);
            this.lblDuration.Name = "lblDuration";
            this.lblDuration.Size = new System.Drawing.Size(50, 13);
            this.lblDuration.TabIndex = 2;
            this.lblDuration.Text = "Duration:";
            // 
            // lblCallAgent
            // 
            this.lblCallAgent.AutoSize = true;
            this.lblCallAgent.Location = new System.Drawing.Point(6, 52);
            this.lblCallAgent.Name = "lblCallAgent";
            this.lblCallAgent.Size = new System.Drawing.Size(52, 13);
            this.lblCallAgent.TabIndex = 1;
            this.lblCallAgent.Text = "Agent ID:";
            // 
            // gbAgentInfo
            // 
            this.gbAgentInfo.Controls.Add(this.lblAvgAgentCallTimeValue);
            this.gbAgentInfo.Controls.Add(this.lblAvgCallTime);
            this.gbAgentInfo.Controls.Add(this.dgvAgentSkills);
            this.gbAgentInfo.Controls.Add(this.lblAgentIDValue);
            this.gbAgentInfo.Controls.Add(this.lblAgentStatusValue);
            this.gbAgentInfo.Controls.Add(this.lblStatus);
            this.gbAgentInfo.Controls.Add(this.lblID);
            this.gbAgentInfo.Controls.Add(this.lblTotalCallsValue);
            this.gbAgentInfo.Controls.Add(this.lblTotalCalls);
            this.gbAgentInfo.Location = new System.Drawing.Point(393, 12);
            this.gbAgentInfo.Name = "gbAgentInfo";
            this.gbAgentInfo.Size = new System.Drawing.Size(469, 149);
            this.gbAgentInfo.TabIndex = 4;
            this.gbAgentInfo.TabStop = false;
            this.gbAgentInfo.Text = "Agent Info";
            // 
            // lblAvgAgentCallTimeValue
            // 
            this.lblAvgAgentCallTimeValue.AutoSize = true;
            this.lblAvgAgentCallTimeValue.Location = new System.Drawing.Point(81, 102);
            this.lblAvgAgentCallTimeValue.Name = "lblAvgAgentCallTimeValue";
            this.lblAvgAgentCallTimeValue.Size = new System.Drawing.Size(27, 13);
            this.lblAvgAgentCallTimeValue.TabIndex = 13;
            this.lblAvgAgentCallTimeValue.Text = "N/A";
            // 
            // lblAvgCallTime
            // 
            this.lblAvgCallTime.AutoSize = true;
            this.lblAvgCallTime.Location = new System.Drawing.Point(7, 102);
            this.lblAvgCallTime.Name = "lblAvgCallTime";
            this.lblAvgCallTime.Size = new System.Drawing.Size(71, 13);
            this.lblAvgCallTime.TabIndex = 12;
            this.lblAvgCallTime.Text = "Avg Call time:";
            // 
            // dgvAgentSkills
            // 
            this.dgvAgentSkills.AllowUserToDeleteRows = false;
            this.dgvAgentSkills.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgvAgentSkills.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvAgentSkills.Dock = System.Windows.Forms.DockStyle.Right;
            this.dgvAgentSkills.Location = new System.Drawing.Point(217, 16);
            this.dgvAgentSkills.Name = "dgvAgentSkills";
            this.dgvAgentSkills.ReadOnly = true;
            this.dgvAgentSkills.Size = new System.Drawing.Size(249, 130);
            this.dgvAgentSkills.TabIndex = 11;
            // 
            // lblAgentIDValue
            // 
            this.lblAgentIDValue.AutoSize = true;
            this.lblAgentIDValue.Location = new System.Drawing.Point(81, 37);
            this.lblAgentIDValue.Name = "lblAgentIDValue";
            this.lblAgentIDValue.Size = new System.Drawing.Size(27, 13);
            this.lblAgentIDValue.TabIndex = 10;
            this.lblAgentIDValue.Text = "N/A";
            // 
            // lblAgentStatusValue
            // 
            this.lblAgentStatusValue.AutoSize = true;
            this.lblAgentStatusValue.Location = new System.Drawing.Point(81, 59);
            this.lblAgentStatusValue.Name = "lblAgentStatusValue";
            this.lblAgentStatusValue.Size = new System.Drawing.Size(27, 13);
            this.lblAgentStatusValue.TabIndex = 8;
            this.lblAgentStatusValue.Text = "N/A";
            // 
            // lblStatus
            // 
            this.lblStatus.AutoSize = true;
            this.lblStatus.Location = new System.Drawing.Point(6, 59);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(40, 13);
            this.lblStatus.TabIndex = 7;
            this.lblStatus.Text = "Status:";
            // 
            // lblID
            // 
            this.lblID.AutoSize = true;
            this.lblID.Location = new System.Drawing.Point(7, 37);
            this.lblID.Name = "lblID";
            this.lblID.Size = new System.Drawing.Size(21, 13);
            this.lblID.TabIndex = 4;
            this.lblID.Text = "ID:";
            // 
            // lblTotalCallsValue
            // 
            this.lblTotalCallsValue.AutoSize = true;
            this.lblTotalCallsValue.Location = new System.Drawing.Point(81, 80);
            this.lblTotalCallsValue.Name = "lblTotalCallsValue";
            this.lblTotalCallsValue.Size = new System.Drawing.Size(27, 13);
            this.lblTotalCallsValue.TabIndex = 2;
            this.lblTotalCallsValue.Text = "N/A";
            // 
            // lblTotalCalls
            // 
            this.lblTotalCalls.AutoSize = true;
            this.lblTotalCalls.Location = new System.Drawing.Point(6, 80);
            this.lblTotalCalls.Name = "lblTotalCalls";
            this.lblTotalCalls.Size = new System.Drawing.Size(59, 13);
            this.lblTotalCalls.TabIndex = 1;
            this.lblTotalCalls.Text = "Total Calls:";
            // 
            // lblAvgWaitValue
            // 
            this.lblAvgWaitValue.AutoSize = true;
            this.lblAvgWaitValue.Location = new System.Drawing.Point(144, 51);
            this.lblAvgWaitValue.Name = "lblAvgWaitValue";
            this.lblAvgWaitValue.Size = new System.Drawing.Size(27, 13);
            this.lblAvgWaitValue.TabIndex = 4;
            this.lblAvgWaitValue.Text = "N/A";
            // 
            // gbStats
            // 
            this.gbStats.Controls.Add(this.lblPendingCallsValue);
            this.gbStats.Controls.Add(this.lblPendingCalls);
            this.gbStats.Controls.Add(this.lblAvgCallTimeValue);
            this.gbStats.Controls.Add(this.lblAvgCallDuration);
            this.gbStats.Controls.Add(this.lblAvgWait);
            this.gbStats.Controls.Add(this.lblAvgWaitValue);
            this.gbStats.Location = new System.Drawing.Point(393, 167);
            this.gbStats.Name = "gbStats";
            this.gbStats.Size = new System.Drawing.Size(268, 130);
            this.gbStats.TabIndex = 5;
            this.gbStats.TabStop = false;
            this.gbStats.Text = "Stats";
            // 
            // lblPendingCallsValue
            // 
            this.lblPendingCallsValue.AutoSize = true;
            this.lblPendingCallsValue.Location = new System.Drawing.Point(144, 81);
            this.lblPendingCallsValue.Name = "lblPendingCallsValue";
            this.lblPendingCallsValue.Size = new System.Drawing.Size(27, 13);
            this.lblPendingCallsValue.TabIndex = 12;
            this.lblPendingCallsValue.Text = "N/A";
            // 
            // lblPendingCalls
            // 
            this.lblPendingCalls.AutoSize = true;
            this.lblPendingCalls.Location = new System.Drawing.Point(6, 81);
            this.lblPendingCalls.Name = "lblPendingCalls";
            this.lblPendingCalls.Size = new System.Drawing.Size(74, 13);
            this.lblPendingCalls.TabIndex = 11;
            this.lblPendingCalls.Text = "Pending Calls:";
            // 
            // lblAvgCallTimeValue
            // 
            this.lblAvgCallTimeValue.AutoSize = true;
            this.lblAvgCallTimeValue.Location = new System.Drawing.Point(144, 25);
            this.lblAvgCallTimeValue.Name = "lblAvgCallTimeValue";
            this.lblAvgCallTimeValue.Size = new System.Drawing.Size(27, 13);
            this.lblAvgCallTimeValue.TabIndex = 10;
            this.lblAvgCallTimeValue.Text = "N/A";
            // 
            // lblAvgCallDuration
            // 
            this.lblAvgCallDuration.AutoSize = true;
            this.lblAvgCallDuration.Location = new System.Drawing.Point(6, 25);
            this.lblAvgCallDuration.Name = "lblAvgCallDuration";
            this.lblAvgCallDuration.Size = new System.Drawing.Size(75, 13);
            this.lblAvgCallDuration.TabIndex = 6;
            this.lblAvgCallDuration.Text = "Avg Call Time:";
            // 
            // ProccessQueueTimer
            // 
            this.ProccessQueueTimer.Interval = 10;
            this.ProccessQueueTimer.Tick += new System.EventHandler(this.ProccessQueueTimer_Tick);
            // 
            // gbVisualizer
            // 
            this.gbVisualizer.Controls.Add(this.chart1);
            this.gbVisualizer.Location = new System.Drawing.Point(667, 167);
            this.gbVisualizer.Name = "gbVisualizer";
            this.gbVisualizer.Size = new System.Drawing.Size(592, 370);
            this.gbVisualizer.TabIndex = 8;
            this.gbVisualizer.TabStop = false;
            this.gbVisualizer.Text = "Visualizer";
            // 
            // chart1
            // 
            chartArea4.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea4);
            this.chart1.Dock = System.Windows.Forms.DockStyle.Fill;
            legend4.Name = "Legend1";
            this.chart1.Legends.Add(legend4);
            this.chart1.Location = new System.Drawing.Point(3, 16);
            this.chart1.Name = "chart1";
            series4.ChartArea = "ChartArea1";
            series4.Legend = "Legend1";
            series4.Name = "Series1";
            this.chart1.Series.Add(series4);
            this.chart1.Size = new System.Drawing.Size(586, 351);
            this.chart1.TabIndex = 0;
            this.chart1.Text = "DataVisualiztion";
            // 
            // gpGraphSettings
            // 
            this.gpGraphSettings.Controls.Add(this.checkBEnable3D);
            this.gpGraphSettings.Controls.Add(this.cbData);
            this.gpGraphSettings.Controls.Add(this.lblData);
            this.gpGraphSettings.Controls.Add(this.checkBMarkers);
            this.gpGraphSettings.Controls.Add(this.cbLighting);
            this.gpGraphSettings.Controls.Add(this.lblLighting);
            this.gpGraphSettings.Location = new System.Drawing.Point(393, 304);
            this.gpGraphSettings.Name = "gpGraphSettings";
            this.gpGraphSettings.Size = new System.Drawing.Size(268, 229);
            this.gpGraphSettings.TabIndex = 9;
            this.gpGraphSettings.TabStop = false;
            this.gpGraphSettings.Text = "Graph Settings";
            // 
            // checkBEnable3D
            // 
            this.checkBEnable3D.AutoSize = true;
            this.checkBEnable3D.Checked = true;
            this.checkBEnable3D.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBEnable3D.Location = new System.Drawing.Point(10, 115);
            this.checkBEnable3D.Name = "checkBEnable3D";
            this.checkBEnable3D.Size = new System.Drawing.Size(76, 17);
            this.checkBEnable3D.TabIndex = 7;
            this.checkBEnable3D.Text = "Enable 3D";
            this.checkBEnable3D.UseVisualStyleBackColor = true;
            this.checkBEnable3D.CheckedChanged += new System.EventHandler(this.checkBEnable3D_CheckedChanged);
            // 
            // cbData
            // 
            this.cbData.FormattingEnabled = true;
            this.cbData.Location = new System.Drawing.Point(9, 86);
            this.cbData.Name = "cbData";
            this.cbData.Size = new System.Drawing.Size(121, 21);
            this.cbData.TabIndex = 6;
            this.cbData.SelectedIndexChanged += new System.EventHandler(this.cbData_SelectedIndexChanged);
            // 
            // lblData
            // 
            this.lblData.AutoSize = true;
            this.lblData.Location = new System.Drawing.Point(9, 69);
            this.lblData.Name = "lblData";
            this.lblData.Size = new System.Drawing.Size(30, 13);
            this.lblData.TabIndex = 5;
            this.lblData.Text = "Data";
            // 
            // checkBMarkers
            // 
            this.checkBMarkers.AutoSize = true;
            this.checkBMarkers.Checked = true;
            this.checkBMarkers.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBMarkers.Location = new System.Drawing.Point(10, 138);
            this.checkBMarkers.Name = "checkBMarkers";
            this.checkBMarkers.Size = new System.Drawing.Size(94, 17);
            this.checkBMarkers.TabIndex = 4;
            this.checkBMarkers.Text = "Show Markers";
            this.checkBMarkers.UseVisualStyleBackColor = true;
            this.checkBMarkers.CheckedChanged += new System.EventHandler(this.checkBMarkers_CheckedChanged);
            // 
            // cbLighting
            // 
            this.cbLighting.FormattingEnabled = true;
            this.cbLighting.Location = new System.Drawing.Point(12, 36);
            this.cbLighting.Name = "cbLighting";
            this.cbLighting.Size = new System.Drawing.Size(121, 21);
            this.cbLighting.TabIndex = 1;
            this.cbLighting.SelectedIndexChanged += new System.EventHandler(this.cbLighting_SelectedIndexChanged);
            // 
            // lblLighting
            // 
            this.lblLighting.AutoSize = true;
            this.lblLighting.Location = new System.Drawing.Point(9, 20);
            this.lblLighting.Name = "lblLighting";
            this.lblLighting.Size = new System.Drawing.Size(44, 13);
            this.lblLighting.TabIndex = 0;
            this.lblLighting.Text = "Lighting";
            // 
            // lblPhoneID
            // 
            this.lblPhoneID.AutoSize = true;
            this.lblPhoneID.Location = new System.Drawing.Point(0, 23);
            this.lblPhoneID.Name = "lblPhoneID";
            this.lblPhoneID.Size = new System.Drawing.Size(38, 13);
            this.lblPhoneID.TabIndex = 10;
            this.lblPhoneID.Text = "Call ID";
            // 
            // lblAgentID
            // 
            this.lblAgentID.AutoSize = true;
            this.lblAgentID.Location = new System.Drawing.Point(192, 23);
            this.lblAgentID.Name = "lblAgentID";
            this.lblAgentID.Size = new System.Drawing.Size(49, 13);
            this.lblAgentID.TabIndex = 11;
            this.lblAgentID.Text = "Agent ID";
            // 
            // NUIronManForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1271, 545);
            this.Controls.Add(this.lblAgentID);
            this.Controls.Add(this.lblPhoneID);
            this.Controls.Add(this.gpGraphSettings);
            this.Controls.Add(this.gbVisualizer);
            this.Controls.Add(this.gbStats);
            this.Controls.Add(this.gbAgentInfo);
            this.Controls.Add(this.gbCallInfo);
            this.Controls.Add(this.lbAgents);
            this.Controls.Add(this.lbCalls);
            this.Name = "NUIronManForm";
            this.Text = "NUIronMan";
            this.Load += new System.EventHandler(this.NUIronManForm_Load);
            this.gbCallInfo.ResumeLayout(false);
            this.gbCallInfo.PerformLayout();
            this.gbAgentInfo.ResumeLayout(false);
            this.gbAgentInfo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvAgentSkills)).EndInit();
            this.gbStats.ResumeLayout(false);
            this.gbStats.PerformLayout();
            this.gbVisualizer.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            this.gpGraphSettings.ResumeLayout(false);
            this.gpGraphSettings.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox lbCalls;
        private System.Windows.Forms.ListBox lbAgents;
        private System.Windows.Forms.Label lblAvgWait;
        private System.Windows.Forms.GroupBox gbCallInfo;
        private System.Windows.Forms.GroupBox gbAgentInfo;
        private System.Windows.Forms.Label lblTotalCalls;
        private System.Windows.Forms.Label lblAvgWaitValue;
        private System.Windows.Forms.Label lblTotalCallsValue;
        private System.Windows.Forms.Label lblID;
        private System.Windows.Forms.GroupBox gbStats;
        private System.Windows.Forms.Timer ProccessQueueTimer;
        private System.Windows.Forms.Label lblStatus;
        private System.Windows.Forms.Label lblDuration;
        private System.Windows.Forms.Label lblCallAgent;
        private System.Windows.Forms.Label lblAvgCallDuration;
        private System.Windows.Forms.Label lblCallWaitTime;
        private System.Windows.Forms.Label lblAgentIDValue;
        private System.Windows.Forms.Label lblAgentStatusValue;
        private System.Windows.Forms.Label lblWaitTimeValue;
        private System.Windows.Forms.Label lblCallDurationValue;
        private System.Windows.Forms.Label lblCallAgentIDValue;
        private System.Windows.Forms.Label lblAvgCallTimeValue;
        private System.Windows.Forms.DataGridView dgvAgentSkills;
        private System.Windows.Forms.Label lblPendingCallsValue;
        private System.Windows.Forms.Label lblPendingCalls;
        private System.Windows.Forms.GroupBox gbVisualizer;
        private System.Windows.Forms.Label lblCallIDValue;
        private System.Windows.Forms.Label lblCallID;
        private System.Windows.Forms.ListBox lbRequiredSkills;
        private System.Windows.Forms.Label lblAvgAgentCallTimeValue;
        private System.Windows.Forms.Label lblAvgCallTime;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.GroupBox gpGraphSettings;
        private System.Windows.Forms.ComboBox cbLighting;
        private System.Windows.Forms.Label lblLighting;
        private System.Windows.Forms.CheckBox checkBMarkers;
        private System.Windows.Forms.ComboBox cbData;
        private System.Windows.Forms.Label lblData;
        private System.Windows.Forms.CheckBox checkBEnable3D;
        private System.Windows.Forms.Label lblPhoneID;
        private System.Windows.Forms.Label lblAgentID;
    }
}

