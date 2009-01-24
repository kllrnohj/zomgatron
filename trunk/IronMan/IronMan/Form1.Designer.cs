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
            this.lbCalls = new System.Windows.Forms.ListBox();
            this.lbAgents = new System.Windows.Forms.ListBox();
            this.lblAvgWait = new System.Windows.Forms.Label();
            this.gbCallInfo = new System.Windows.Forms.GroupBox();
            this.lblWaitTimeValue = new System.Windows.Forms.Label();
            this.lblCallDurationValue = new System.Windows.Forms.Label();
            this.lblCallAgentIDValue = new System.Windows.Forms.Label();
            this.lblCallStatusValue = new System.Windows.Forms.Label();
            this.lblCallWaitTime = new System.Windows.Forms.Label();
            this.lblDuration = new System.Windows.Forms.Label();
            this.lblCallAgent = new System.Windows.Forms.Label();
            this.lblCallStatus = new System.Windows.Forms.Label();
            this.lblAvgAgentDT = new System.Windows.Forms.Label();
            this.gbAgentInfo = new System.Windows.Forms.GroupBox();
            this.lblAgentIDValue = new System.Windows.Forms.Label();
            this.lblWorkTimeValue = new System.Windows.Forms.Label();
            this.lblAgentStatusValue = new System.Windows.Forms.Label();
            this.lblStatus = new System.Windows.Forms.Label();
            this.lbSkills = new System.Windows.Forms.ListBox();
            this.lblWorkTime = new System.Windows.Forms.Label();
            this.lblID = new System.Windows.Forms.Label();
            this.lblCallsPerHourValue = new System.Windows.Forms.Label();
            this.lblTotalCallsValue = new System.Windows.Forms.Label();
            this.lblTotalCalls = new System.Windows.Forms.Label();
            this.lblCallsPerHour = new System.Windows.Forms.Label();
            this.lblAvgWaitValue = new System.Windows.Forms.Label();
            this.lblAvgAgentDTValue = new System.Windows.Forms.Label();
            this.gbStats = new System.Windows.Forms.GroupBox();
            this.lblAvgCallTimeValue = new System.Windows.Forms.Label();
            this.lblAvgCallPerHourValue = new System.Windows.Forms.Label();
            this.dgvAvailableSkills = new System.Windows.Forms.DataGridView();
            this.Skill = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.High = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Medium = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Low = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.lblCallPerHour = new System.Windows.Forms.Label();
            this.lblAvgCallDuration = new System.Windows.Forms.Label();
            this.ProccessQueueTimer = new System.Windows.Forms.Timer(this.components);
            this.VisualizerPanel = new System.Windows.Forms.Panel();
            this.gbVisualizerControls = new System.Windows.Forms.GroupBox();
            this.cbEnableSound = new System.Windows.Forms.CheckBox();
            this.cbEnableVisualization = new System.Windows.Forms.CheckBox();
            this.gbCallInfo.SuspendLayout();
            this.gbAgentInfo.SuspendLayout();
            this.gbStats.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvAvailableSkills)).BeginInit();
            this.gbVisualizerControls.SuspendLayout();
            this.SuspendLayout();
            // 
            // lbCalls
            // 
            this.lbCalls.FormattingEnabled = true;
            this.lbCalls.Location = new System.Drawing.Point(3, 13);
            this.lbCalls.Name = "lbCalls";
            this.lbCalls.Size = new System.Drawing.Size(176, 524);
            this.lbCalls.TabIndex = 0;
            this.lbCalls.SelectedIndexChanged += new System.EventHandler(this.lbCalls_SelectedIndexChanged);
            // 
            // lbAgents
            // 
            this.lbAgents.FormattingEnabled = true;
            this.lbAgents.Location = new System.Drawing.Point(195, 13);
            this.lbAgents.Name = "lbAgents";
            this.lbAgents.Size = new System.Drawing.Size(183, 524);
            this.lbAgents.TabIndex = 1;
            // 
            // lblAvgWait
            // 
            this.lblAvgWait.AutoSize = true;
            this.lblAvgWait.Location = new System.Drawing.Point(6, 60);
            this.lblAvgWait.Name = "lblAvgWait";
            this.lblAvgWait.Size = new System.Drawing.Size(75, 13);
            this.lblAvgWait.TabIndex = 2;
            this.lblAvgWait.Text = "Average Wait:";
            // 
            // gbCallInfo
            // 
            this.gbCallInfo.Controls.Add(this.lblWaitTimeValue);
            this.gbCallInfo.Controls.Add(this.lblCallDurationValue);
            this.gbCallInfo.Controls.Add(this.lblCallAgentIDValue);
            this.gbCallInfo.Controls.Add(this.lblCallStatusValue);
            this.gbCallInfo.Controls.Add(this.lblCallWaitTime);
            this.gbCallInfo.Controls.Add(this.lblDuration);
            this.gbCallInfo.Controls.Add(this.lblCallAgent);
            this.gbCallInfo.Controls.Add(this.lblCallStatus);
            this.gbCallInfo.Location = new System.Drawing.Point(400, 107);
            this.gbCallInfo.Name = "gbCallInfo";
            this.gbCallInfo.Size = new System.Drawing.Size(469, 132);
            this.gbCallInfo.TabIndex = 3;
            this.gbCallInfo.TabStop = false;
            this.gbCallInfo.Text = "Call Info";
            // 
            // lblWaitTimeValue
            // 
            this.lblWaitTimeValue.AutoSize = true;
            this.lblWaitTimeValue.Location = new System.Drawing.Point(144, 98);
            this.lblWaitTimeValue.Name = "lblWaitTimeValue";
            this.lblWaitTimeValue.Size = new System.Drawing.Size(61, 13);
            this.lblWaitTimeValue.TabIndex = 7;
            this.lblWaitTimeValue.Text = "WAITTIME";
            // 
            // lblCallDurationValue
            // 
            this.lblCallDurationValue.AutoSize = true;
            this.lblCallDurationValue.Location = new System.Drawing.Point(147, 75);
            this.lblCallDurationValue.Name = "lblCallDurationValue";
            this.lblCallDurationValue.Size = new System.Drawing.Size(90, 13);
            this.lblCallDurationValue.TabIndex = 6;
            this.lblCallDurationValue.Text = "CALLDURATION";
            // 
            // lblCallAgentIDValue
            // 
            this.lblCallAgentIDValue.AutoSize = true;
            this.lblCallAgentIDValue.Location = new System.Drawing.Point(147, 50);
            this.lblCallAgentIDValue.Name = "lblCallAgentIDValue";
            this.lblCallAgentIDValue.Size = new System.Drawing.Size(55, 13);
            this.lblCallAgentIDValue.TabIndex = 5;
            this.lblCallAgentIDValue.Text = "AGENTID";
            // 
            // lblCallStatusValue
            // 
            this.lblCallStatusValue.AutoSize = true;
            this.lblCallStatusValue.Location = new System.Drawing.Point(147, 29);
            this.lblCallStatusValue.Name = "lblCallStatusValue";
            this.lblCallStatusValue.Size = new System.Drawing.Size(76, 13);
            this.lblCallStatusValue.TabIndex = 4;
            this.lblCallStatusValue.Text = "CALLSTATUS";
            // 
            // lblCallWaitTime
            // 
            this.lblCallWaitTime.AutoSize = true;
            this.lblCallWaitTime.Location = new System.Drawing.Point(6, 98);
            this.lblCallWaitTime.Name = "lblCallWaitTime";
            this.lblCallWaitTime.Size = new System.Drawing.Size(58, 13);
            this.lblCallWaitTime.TabIndex = 3;
            this.lblCallWaitTime.Text = "Wait Time:";
            // 
            // lblDuration
            // 
            this.lblDuration.AutoSize = true;
            this.lblDuration.Location = new System.Drawing.Point(6, 76);
            this.lblDuration.Name = "lblDuration";
            this.lblDuration.Size = new System.Drawing.Size(50, 13);
            this.lblDuration.TabIndex = 2;
            this.lblDuration.Text = "Duration:";
            // 
            // lblCallAgent
            // 
            this.lblCallAgent.AutoSize = true;
            this.lblCallAgent.Location = new System.Drawing.Point(6, 50);
            this.lblCallAgent.Name = "lblCallAgent";
            this.lblCallAgent.Size = new System.Drawing.Size(38, 13);
            this.lblCallAgent.TabIndex = 1;
            this.lblCallAgent.Text = "Agent:";
            // 
            // lblCallStatus
            // 
            this.lblCallStatus.AutoSize = true;
            this.lblCallStatus.Location = new System.Drawing.Point(6, 28);
            this.lblCallStatus.Name = "lblCallStatus";
            this.lblCallStatus.Size = new System.Drawing.Size(37, 13);
            this.lblCallStatus.TabIndex = 0;
            this.lblCallStatus.Text = "Satus:";
            // 
            // lblAvgAgentDT
            // 
            this.lblAvgAgentDT.AutoSize = true;
            this.lblAvgAgentDT.Location = new System.Drawing.Point(6, 82);
            this.lblAvgAgentDT.Name = "lblAvgAgentDT";
            this.lblAvgAgentDT.Size = new System.Drawing.Size(131, 13);
            this.lblAvgAgentDT.TabIndex = 3;
            this.lblAvgAgentDT.Text = "Average Agent Downtime:";
            // 
            // gbAgentInfo
            // 
            this.gbAgentInfo.Controls.Add(this.lblAgentIDValue);
            this.gbAgentInfo.Controls.Add(this.lblWorkTimeValue);
            this.gbAgentInfo.Controls.Add(this.lblAgentStatusValue);
            this.gbAgentInfo.Controls.Add(this.lblStatus);
            this.gbAgentInfo.Controls.Add(this.lbSkills);
            this.gbAgentInfo.Controls.Add(this.lblWorkTime);
            this.gbAgentInfo.Controls.Add(this.lblID);
            this.gbAgentInfo.Controls.Add(this.lblCallsPerHourValue);
            this.gbAgentInfo.Controls.Add(this.lblTotalCallsValue);
            this.gbAgentInfo.Controls.Add(this.lblTotalCalls);
            this.gbAgentInfo.Controls.Add(this.lblCallsPerHour);
            this.gbAgentInfo.Location = new System.Drawing.Point(875, 13);
            this.gbAgentInfo.Name = "gbAgentInfo";
            this.gbAgentInfo.Size = new System.Drawing.Size(384, 151);
            this.gbAgentInfo.TabIndex = 4;
            this.gbAgentInfo.TabStop = false;
            this.gbAgentInfo.Text = "Agent Info";
            // 
            // lblAgentIDValue
            // 
            this.lblAgentIDValue.AutoSize = true;
            this.lblAgentIDValue.Location = new System.Drawing.Point(76, 29);
            this.lblAgentIDValue.Name = "lblAgentIDValue";
            this.lblAgentIDValue.Size = new System.Drawing.Size(55, 13);
            this.lblAgentIDValue.TabIndex = 10;
            this.lblAgentIDValue.Text = "AGENTID";
            // 
            // lblWorkTimeValue
            // 
            this.lblWorkTimeValue.AutoSize = true;
            this.lblWorkTimeValue.Location = new System.Drawing.Point(76, 57);
            this.lblWorkTimeValue.Name = "lblWorkTimeValue";
            this.lblWorkTimeValue.Size = new System.Drawing.Size(67, 13);
            this.lblWorkTimeValue.TabIndex = 9;
            this.lblWorkTimeValue.Text = "WORKTIME";
            // 
            // lblAgentStatusValue
            // 
            this.lblAgentStatusValue.AutoSize = true;
            this.lblAgentStatusValue.Location = new System.Drawing.Point(76, 83);
            this.lblAgentStatusValue.Name = "lblAgentStatusValue";
            this.lblAgentStatusValue.Size = new System.Drawing.Size(90, 13);
            this.lblAgentStatusValue.TabIndex = 8;
            this.lblAgentStatusValue.Text = "AGENT STATUS";
            // 
            // lblStatus
            // 
            this.lblStatus.AutoSize = true;
            this.lblStatus.Location = new System.Drawing.Point(6, 83);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(40, 13);
            this.lblStatus.TabIndex = 7;
            this.lblStatus.Text = "Status:";
            // 
            // lbSkills
            // 
            this.lbSkills.FormattingEnabled = true;
            this.lbSkills.Location = new System.Drawing.Point(172, 9);
            this.lbSkills.Name = "lbSkills";
            this.lbSkills.Size = new System.Drawing.Size(206, 134);
            this.lbSkills.TabIndex = 6;
            // 
            // lblWorkTime
            // 
            this.lblWorkTime.AutoSize = true;
            this.lblWorkTime.Location = new System.Drawing.Point(6, 57);
            this.lblWorkTime.Name = "lblWorkTime";
            this.lblWorkTime.Size = new System.Drawing.Size(62, 13);
            this.lblWorkTime.TabIndex = 5;
            this.lblWorkTime.Text = "Work Time:";
            // 
            // lblID
            // 
            this.lblID.AutoSize = true;
            this.lblID.Location = new System.Drawing.Point(7, 29);
            this.lblID.Name = "lblID";
            this.lblID.Size = new System.Drawing.Size(21, 13);
            this.lblID.TabIndex = 4;
            this.lblID.Text = "ID:";
            // 
            // lblCallsPerHourValue
            // 
            this.lblCallsPerHourValue.AutoSize = true;
            this.lblCallsPerHourValue.Location = new System.Drawing.Point(78, 128);
            this.lblCallsPerHourValue.Name = "lblCallsPerHourValue";
            this.lblCallsPerHourValue.Size = new System.Drawing.Size(83, 13);
            this.lblCallsPerHourValue.TabIndex = 3;
            this.lblCallsPerHourValue.Text = "CALLS / HOUR";
            // 
            // lblTotalCallsValue
            // 
            this.lblTotalCallsValue.AutoSize = true;
            this.lblTotalCallsValue.Location = new System.Drawing.Point(76, 105);
            this.lblTotalCallsValue.Name = "lblTotalCallsValue";
            this.lblTotalCallsValue.Size = new System.Drawing.Size(75, 13);
            this.lblTotalCallsValue.TabIndex = 2;
            this.lblTotalCallsValue.Text = "TOTALCALLS";
            // 
            // lblTotalCalls
            // 
            this.lblTotalCalls.AutoSize = true;
            this.lblTotalCalls.Location = new System.Drawing.Point(6, 105);
            this.lblTotalCalls.Name = "lblTotalCalls";
            this.lblTotalCalls.Size = new System.Drawing.Size(59, 13);
            this.lblTotalCalls.TabIndex = 1;
            this.lblTotalCalls.Text = "Total Calls:";
            // 
            // lblCallsPerHour
            // 
            this.lblCallsPerHour.AutoSize = true;
            this.lblCallsPerHour.Location = new System.Drawing.Point(6, 128);
            this.lblCallsPerHour.Name = "lblCallsPerHour";
            this.lblCallsPerHour.Size = new System.Drawing.Size(66, 13);
            this.lblCallsPerHour.TabIndex = 0;
            this.lblCallsPerHour.Text = "Calls / Hour:";
            // 
            // lblAvgWaitValue
            // 
            this.lblAvgWaitValue.AutoSize = true;
            this.lblAvgWaitValue.Location = new System.Drawing.Point(144, 60);
            this.lblAvgWaitValue.Name = "lblAvgWaitValue";
            this.lblAvgWaitValue.Size = new System.Drawing.Size(57, 13);
            this.lblAvgWaitValue.TabIndex = 4;
            this.lblAvgWaitValue.Text = "AVGWAIT";
            // 
            // lblAvgAgentDTValue
            // 
            this.lblAvgAgentDTValue.AutoSize = true;
            this.lblAvgAgentDTValue.Location = new System.Drawing.Point(144, 82);
            this.lblAvgAgentDTValue.Name = "lblAvgAgentDTValue";
            this.lblAvgAgentDTValue.Size = new System.Drawing.Size(127, 13);
            this.lblAvgAgentDTValue.TabIndex = 5;
            this.lblAvgAgentDTValue.Text = "AVGAGENTDOWNTIME";
            // 
            // gbStats
            // 
            this.gbStats.Controls.Add(this.lblAvgCallTimeValue);
            this.gbStats.Controls.Add(this.lblAvgCallPerHourValue);
            this.gbStats.Controls.Add(this.dgvAvailableSkills);
            this.gbStats.Controls.Add(this.lblCallPerHour);
            this.gbStats.Controls.Add(this.lblAvgCallDuration);
            this.gbStats.Controls.Add(this.lblAvgAgentDTValue);
            this.gbStats.Controls.Add(this.lblAvgAgentDT);
            this.gbStats.Controls.Add(this.lblAvgWait);
            this.gbStats.Controls.Add(this.lblAvgWaitValue);
            this.gbStats.Location = new System.Drawing.Point(400, 245);
            this.gbStats.Name = "gbStats";
            this.gbStats.Size = new System.Drawing.Size(469, 292);
            this.gbStats.TabIndex = 5;
            this.gbStats.TabStop = false;
            this.gbStats.Text = "Stats";
            // 
            // lblAvgCallTimeValue
            // 
            this.lblAvgCallTimeValue.AutoSize = true;
            this.lblAvgCallTimeValue.Location = new System.Drawing.Point(144, 34);
            this.lblAvgCallTimeValue.Name = "lblAvgCallTimeValue";
            this.lblAvgCallTimeValue.Size = new System.Drawing.Size(81, 13);
            this.lblAvgCallTimeValue.TabIndex = 10;
            this.lblAvgCallTimeValue.Text = "AVGCALLTIME";
            // 
            // lblAvgCallPerHourValue
            // 
            this.lblAvgCallPerHourValue.AutoSize = true;
            this.lblAvgCallPerHourValue.Location = new System.Drawing.Point(144, 112);
            this.lblAvgCallPerHourValue.Name = "lblAvgCallPerHourValue";
            this.lblAvgCallPerHourValue.Size = new System.Drawing.Size(109, 13);
            this.lblAvgCallPerHourValue.TabIndex = 9;
            this.lblAvgCallPerHourValue.Text = "AVGCALLPERHOUR";
            // 
            // dgvAvailableSkills
            // 
            this.dgvAvailableSkills.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvAvailableSkills.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Skill,
            this.High,
            this.Medium,
            this.Low});
            this.dgvAvailableSkills.Location = new System.Drawing.Point(9, 151);
            this.dgvAvailableSkills.Name = "dgvAvailableSkills";
            this.dgvAvailableSkills.Size = new System.Drawing.Size(443, 123);
            this.dgvAvailableSkills.TabIndex = 8;
            // 
            // Skill
            // 
            this.Skill.HeaderText = "Skill";
            this.Skill.Name = "Skill";
            // 
            // High
            // 
            this.High.HeaderText = "High";
            this.High.Name = "High";
            // 
            // Medium
            // 
            this.Medium.HeaderText = "Medium";
            this.Medium.Name = "Medium";
            // 
            // Low
            // 
            this.Low.HeaderText = "Low";
            this.Low.Name = "Low";
            // 
            // lblCallPerHour
            // 
            this.lblCallPerHour.AutoSize = true;
            this.lblCallPerHour.Location = new System.Drawing.Point(6, 112);
            this.lblCallPerHour.Name = "lblCallPerHour";
            this.lblCallPerHour.Size = new System.Drawing.Size(104, 13);
            this.lblCallPerHour.TabIndex = 7;
            this.lblCallPerHour.Text = "Average Call / Hour:";
            // 
            // lblAvgCallDuration
            // 
            this.lblAvgCallDuration.AutoSize = true;
            this.lblAvgCallDuration.Location = new System.Drawing.Point(6, 34);
            this.lblAvgCallDuration.Name = "lblAvgCallDuration";
            this.lblAvgCallDuration.Size = new System.Drawing.Size(96, 13);
            this.lblAvgCallDuration.TabIndex = 6;
            this.lblAvgCallDuration.Text = "Average Call Time:";
            // 
            // ProccessQueueTimer
            // 
            this.ProccessQueueTimer.Enabled = true;
            this.ProccessQueueTimer.Interval = 10;
            this.ProccessQueueTimer.Tick += new System.EventHandler(this.ProccessQueueTimer_Tick);
            // 
            // VisualizerPanel
            // 
            this.VisualizerPanel.Location = new System.Drawing.Point(875, 170);
            this.VisualizerPanel.Name = "VisualizerPanel";
            this.VisualizerPanel.Size = new System.Drawing.Size(384, 367);
            this.VisualizerPanel.TabIndex = 6;
            // 
            // gbVisualizerControls
            // 
            this.gbVisualizerControls.Controls.Add(this.cbEnableVisualization);
            this.gbVisualizerControls.Controls.Add(this.cbEnableSound);
            this.gbVisualizerControls.Location = new System.Drawing.Point(400, 22);
            this.gbVisualizerControls.Name = "gbVisualizerControls";
            this.gbVisualizerControls.Size = new System.Drawing.Size(469, 69);
            this.gbVisualizerControls.TabIndex = 7;
            this.gbVisualizerControls.TabStop = false;
            this.gbVisualizerControls.Text = "Visualizer Controls";
            // 
            // cbEnableSound
            // 
            this.cbEnableSound.AutoSize = true;
            this.cbEnableSound.Location = new System.Drawing.Point(9, 42);
            this.cbEnableSound.Name = "cbEnableSound";
            this.cbEnableSound.Size = new System.Drawing.Size(90, 17);
            this.cbEnableSound.TabIndex = 0;
            this.cbEnableSound.Text = "EnableSound";
            this.cbEnableSound.UseVisualStyleBackColor = true;
            // 
            // cbEnableVisualization
            // 
            this.cbEnableVisualization.AutoSize = true;
            this.cbEnableVisualization.Location = new System.Drawing.Point(9, 19);
            this.cbEnableVisualization.Name = "cbEnableVisualization";
            this.cbEnableVisualization.Size = new System.Drawing.Size(120, 17);
            this.cbEnableVisualization.TabIndex = 1;
            this.cbEnableVisualization.Text = "Enable Visualization";
            this.cbEnableVisualization.UseVisualStyleBackColor = true;
            // 
            // NUIronManForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1271, 545);
            this.Controls.Add(this.gbVisualizerControls);
            this.Controls.Add(this.VisualizerPanel);
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
            this.gbStats.ResumeLayout(false);
            this.gbStats.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvAvailableSkills)).EndInit();
            this.gbVisualizerControls.ResumeLayout(false);
            this.gbVisualizerControls.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox lbCalls;
        private System.Windows.Forms.ListBox lbAgents;
        private System.Windows.Forms.Label lblAvgWait;
        private System.Windows.Forms.GroupBox gbCallInfo;
        private System.Windows.Forms.Label lblAvgAgentDT;
        private System.Windows.Forms.GroupBox gbAgentInfo;
        private System.Windows.Forms.Label lblTotalCalls;
        private System.Windows.Forms.Label lblCallsPerHour;
        private System.Windows.Forms.Label lblAvgAgentDTValue;
        private System.Windows.Forms.Label lblAvgWaitValue;
        private System.Windows.Forms.Label lblCallsPerHourValue;
        private System.Windows.Forms.Label lblTotalCallsValue;
        private System.Windows.Forms.ListBox lbSkills;
        private System.Windows.Forms.Label lblWorkTime;
        private System.Windows.Forms.Label lblID;
        private System.Windows.Forms.GroupBox gbStats;
        private System.Windows.Forms.Timer ProccessQueueTimer;
        private System.Windows.Forms.Label lblStatus;
        private System.Windows.Forms.Label lblDuration;
        private System.Windows.Forms.Label lblCallAgent;
        private System.Windows.Forms.Label lblCallStatus;
        private System.Windows.Forms.Label lblCallPerHour;
        private System.Windows.Forms.Label lblAvgCallDuration;
        private System.Windows.Forms.Label lblCallWaitTime;
        private System.Windows.Forms.Label lblAgentIDValue;
        private System.Windows.Forms.Label lblWorkTimeValue;
        private System.Windows.Forms.Label lblAgentStatusValue;
        private System.Windows.Forms.DataGridView dgvAvailableSkills;
        private System.Windows.Forms.DataGridViewTextBoxColumn Skill;
        private System.Windows.Forms.DataGridViewTextBoxColumn High;
        private System.Windows.Forms.DataGridViewTextBoxColumn Medium;
        private System.Windows.Forms.DataGridViewTextBoxColumn Low;
        private System.Windows.Forms.Label lblWaitTimeValue;
        private System.Windows.Forms.Label lblCallDurationValue;
        private System.Windows.Forms.Label lblCallAgentIDValue;
        private System.Windows.Forms.Label lblCallStatusValue;
        private System.Windows.Forms.Panel VisualizerPanel;
        private System.Windows.Forms.Label lblAvgCallTimeValue;
        private System.Windows.Forms.Label lblAvgCallPerHourValue;
        private System.Windows.Forms.GroupBox gbVisualizerControls;
        private System.Windows.Forms.CheckBox cbEnableVisualization;
        private System.Windows.Forms.CheckBox cbEnableSound;
    }
}

