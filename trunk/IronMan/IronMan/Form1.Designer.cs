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
            this.lblDuration = new System.Windows.Forms.Label();
            this.lblCallAgent = new System.Windows.Forms.Label();
            this.lblCallStatus = new System.Windows.Forms.Label();
            this.lblAvgAgentDT = new System.Windows.Forms.Label();
            this.gbAgentInfo = new System.Windows.Forms.GroupBox();
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
            this.lblCallPerHour = new System.Windows.Forms.Label();
            this.lblAvgCallTime = new System.Windows.Forms.Label();
            this.ProccessQueueTimer = new System.Windows.Forms.Timer(this.components);
            this.lblCallWaitTime = new System.Windows.Forms.Label();
            this.dgvAvailableSkills = new System.Windows.Forms.DataGridView();
            this.Skill = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.High = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Medium = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Low = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.VisualizerPanel = new System.Windows.Forms.Panel();
            this.gbCallInfo.SuspendLayout();
            this.gbAgentInfo.SuspendLayout();
            this.gbStats.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvAvailableSkills)).BeginInit();
            this.SuspendLayout();
            // 
            // lbCalls
            // 
            this.lbCalls.FormattingEnabled = true;
            this.lbCalls.Location = new System.Drawing.Point(3, 13);
            this.lbCalls.Name = "lbCalls";
            this.lbCalls.Size = new System.Drawing.Size(192, 576);
            this.lbCalls.TabIndex = 0;
            this.lbCalls.SelectedIndexChanged += new System.EventHandler(this.lbCalls_SelectedIndexChanged);
            // 
            // lbAgents
            // 
            this.lbAgents.FormattingEnabled = true;
            this.lbAgents.Location = new System.Drawing.Point(201, 13);
            this.lbAgents.Name = "lbAgents";
            this.lbAgents.Size = new System.Drawing.Size(183, 576);
            this.lbAgents.TabIndex = 1;
            // 
            // lblAvgWait
            // 
            this.lblAvgWait.AutoSize = true;
            this.lblAvgWait.Location = new System.Drawing.Point(6, 51);
            this.lblAvgWait.Name = "lblAvgWait";
            this.lblAvgWait.Size = new System.Drawing.Size(75, 13);
            this.lblAvgWait.TabIndex = 2;
            this.lblAvgWait.Text = "Average Wait:";
            // 
            // gbCallInfo
            // 
            this.gbCallInfo.Controls.Add(this.label7);
            this.gbCallInfo.Controls.Add(this.label6);
            this.gbCallInfo.Controls.Add(this.label5);
            this.gbCallInfo.Controls.Add(this.label4);
            this.gbCallInfo.Controls.Add(this.lblCallWaitTime);
            this.gbCallInfo.Controls.Add(this.lblDuration);
            this.gbCallInfo.Controls.Add(this.lblCallAgent);
            this.gbCallInfo.Controls.Add(this.lblCallStatus);
            this.gbCallInfo.Location = new System.Drawing.Point(400, 13);
            this.gbCallInfo.Name = "gbCallInfo";
            this.gbCallInfo.Size = new System.Drawing.Size(469, 196);
            this.gbCallInfo.TabIndex = 3;
            this.gbCallInfo.TabStop = false;
            this.gbCallInfo.Text = "Call Info";
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
            this.lblAvgAgentDT.Location = new System.Drawing.Point(6, 73);
            this.lblAvgAgentDT.Name = "lblAvgAgentDT";
            this.lblAvgAgentDT.Size = new System.Drawing.Size(131, 13);
            this.lblAvgAgentDT.TabIndex = 3;
            this.lblAvgAgentDT.Text = "Average Agent Downtime:";
            // 
            // gbAgentInfo
            // 
            this.gbAgentInfo.Controls.Add(this.label3);
            this.gbAgentInfo.Controls.Add(this.label2);
            this.gbAgentInfo.Controls.Add(this.label1);
            this.gbAgentInfo.Controls.Add(this.lblStatus);
            this.gbAgentInfo.Controls.Add(this.lbSkills);
            this.gbAgentInfo.Controls.Add(this.lblWorkTime);
            this.gbAgentInfo.Controls.Add(this.lblID);
            this.gbAgentInfo.Controls.Add(this.lblCallsPerHourValue);
            this.gbAgentInfo.Controls.Add(this.lblTotalCallsValue);
            this.gbAgentInfo.Controls.Add(this.lblTotalCalls);
            this.gbAgentInfo.Controls.Add(this.lblCallsPerHour);
            this.gbAgentInfo.Location = new System.Drawing.Point(921, 13);
            this.gbAgentInfo.Name = "gbAgentInfo";
            this.gbAgentInfo.Size = new System.Drawing.Size(192, 332);
            this.gbAgentInfo.TabIndex = 4;
            this.gbAgentInfo.TabStop = false;
            this.gbAgentInfo.Text = "Agent Info";
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
            this.lbSkills.Location = new System.Drawing.Point(9, 161);
            this.lbSkills.Name = "lbSkills";
            this.lbSkills.Size = new System.Drawing.Size(177, 147);
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
            this.lblCallsPerHourValue.Location = new System.Drawing.Point(111, 128);
            this.lblCallsPerHourValue.Name = "lblCallsPerHourValue";
            this.lblCallsPerHourValue.Size = new System.Drawing.Size(35, 13);
            this.lblCallsPerHourValue.TabIndex = 3;
            this.lblCallsPerHourValue.Text = "label1";
            // 
            // lblTotalCallsValue
            // 
            this.lblTotalCallsValue.AutoSize = true;
            this.lblTotalCallsValue.Location = new System.Drawing.Point(111, 105);
            this.lblTotalCallsValue.Name = "lblTotalCallsValue";
            this.lblTotalCallsValue.Size = new System.Drawing.Size(35, 13);
            this.lblTotalCallsValue.TabIndex = 2;
            this.lblTotalCallsValue.Text = "label1";
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
            this.lblAvgWaitValue.Location = new System.Drawing.Point(144, 51);
            this.lblAvgWaitValue.Name = "lblAvgWaitValue";
            this.lblAvgWaitValue.Size = new System.Drawing.Size(35, 13);
            this.lblAvgWaitValue.TabIndex = 4;
            this.lblAvgWaitValue.Text = "label1";
            // 
            // lblAvgAgentDTValue
            // 
            this.lblAvgAgentDTValue.AutoSize = true;
            this.lblAvgAgentDTValue.Location = new System.Drawing.Point(144, 73);
            this.lblAvgAgentDTValue.Name = "lblAvgAgentDTValue";
            this.lblAvgAgentDTValue.Size = new System.Drawing.Size(35, 13);
            this.lblAvgAgentDTValue.TabIndex = 5;
            this.lblAvgAgentDTValue.Text = "label1";
            // 
            // gbStats
            // 
            this.gbStats.Controls.Add(this.dgvAvailableSkills);
            this.gbStats.Controls.Add(this.lblCallPerHour);
            this.gbStats.Controls.Add(this.lblAvgCallTime);
            this.gbStats.Controls.Add(this.lblAvgAgentDTValue);
            this.gbStats.Controls.Add(this.lblAvgAgentDT);
            this.gbStats.Controls.Add(this.lblAvgWait);
            this.gbStats.Controls.Add(this.lblAvgWaitValue);
            this.gbStats.Location = new System.Drawing.Point(400, 238);
            this.gbStats.Name = "gbStats";
            this.gbStats.Size = new System.Drawing.Size(469, 412);
            this.gbStats.TabIndex = 5;
            this.gbStats.TabStop = false;
            this.gbStats.Text = "Stats";
            // 
            // lblCallPerHour
            // 
            this.lblCallPerHour.AutoSize = true;
            this.lblCallPerHour.Location = new System.Drawing.Point(9, 103);
            this.lblCallPerHour.Name = "lblCallPerHour";
            this.lblCallPerHour.Size = new System.Drawing.Size(104, 13);
            this.lblCallPerHour.TabIndex = 7;
            this.lblCallPerHour.Text = "Average Call / Hour:";
            // 
            // lblAvgCallTime
            // 
            this.lblAvgCallTime.AutoSize = true;
            this.lblAvgCallTime.Location = new System.Drawing.Point(6, 25);
            this.lblAvgCallTime.Name = "lblAvgCallTime";
            this.lblAvgCallTime.Size = new System.Drawing.Size(96, 13);
            this.lblAvgCallTime.TabIndex = 6;
            this.lblAvgCallTime.Text = "Average Call Time:";
            // 
            // ProccessQueueTimer
            // 
            this.ProccessQueueTimer.Enabled = true;
            this.ProccessQueueTimer.Interval = 10;
            this.ProccessQueueTimer.Tick += new System.EventHandler(this.ProccessQueueTimer_Tick);
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
            // dgvAvailableSkills
            // 
            this.dgvAvailableSkills.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvAvailableSkills.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Skill,
            this.High,
            this.Medium,
            this.Low});
            this.dgvAvailableSkills.Location = new System.Drawing.Point(6, 132);
            this.dgvAvailableSkills.Name = "dgvAvailableSkills";
            this.dgvAvailableSkills.Size = new System.Drawing.Size(443, 230);
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
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(114, 82);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "label1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(111, 57);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "label2";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(111, 29);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(35, 13);
            this.label3.TabIndex = 10;
            this.label3.Text = "label3";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(147, 29);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 13);
            this.label4.TabIndex = 4;
            this.label4.Text = "label4";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(147, 49);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(35, 13);
            this.label5.TabIndex = 5;
            this.label5.Text = "label5";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(147, 75);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(35, 13);
            this.label6.TabIndex = 6;
            this.label6.Text = "label6";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(144, 98);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(35, 13);
            this.label7.TabIndex = 7;
            this.label7.Text = "label7";
            // 
            // VisualizerPanel
            // 
            this.VisualizerPanel.Location = new System.Drawing.Point(875, 370);
            this.VisualizerPanel.Name = "VisualizerPanel";
            this.VisualizerPanel.Size = new System.Drawing.Size(384, 262);
            this.VisualizerPanel.TabIndex = 6;
            // 
            // NUIronManForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1271, 644);
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
        private System.Windows.Forms.Label lblAvgCallTime;
        private System.Windows.Forms.Label lblCallWaitTime;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dgvAvailableSkills;
        private System.Windows.Forms.DataGridViewTextBoxColumn Skill;
        private System.Windows.Forms.DataGridViewTextBoxColumn High;
        private System.Windows.Forms.DataGridViewTextBoxColumn Medium;
        private System.Windows.Forms.DataGridViewTextBoxColumn Low;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Panel VisualizerPanel;
    }
}

