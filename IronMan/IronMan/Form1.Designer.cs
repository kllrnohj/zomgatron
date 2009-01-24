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
            this.ProccessQueueTimer = new System.Windows.Forms.Timer(this.components);
            this.gbAgentInfo.SuspendLayout();
            this.gbStats.SuspendLayout();
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
            this.lblAvgWait.Location = new System.Drawing.Point(6, 28);
            this.lblAvgWait.Name = "lblAvgWait";
            this.lblAvgWait.Size = new System.Drawing.Size(75, 13);
            this.lblAvgWait.TabIndex = 2;
            this.lblAvgWait.Text = "Average Wait:";
            // 
            // gbCallInfo
            // 
            this.gbCallInfo.Location = new System.Drawing.Point(400, 13);
            this.gbCallInfo.Name = "gbCallInfo";
            this.gbCallInfo.Size = new System.Drawing.Size(469, 196);
            this.gbCallInfo.TabIndex = 3;
            this.gbCallInfo.TabStop = false;
            this.gbCallInfo.Text = "Call Info";
            // 
            // lblAvgAgentDT
            // 
            this.lblAvgAgentDT.AutoSize = true;
            this.lblAvgAgentDT.Location = new System.Drawing.Point(6, 50);
            this.lblAvgAgentDT.Name = "lblAvgAgentDT";
            this.lblAvgAgentDT.Size = new System.Drawing.Size(131, 13);
            this.lblAvgAgentDT.TabIndex = 3;
            this.lblAvgAgentDT.Text = "Average Agent Downtime:";
            // 
            // gbAgentInfo
            // 
            this.gbAgentInfo.Controls.Add(this.lblStatus);
            this.gbAgentInfo.Controls.Add(this.lbSkills);
            this.gbAgentInfo.Controls.Add(this.lblWorkTime);
            this.gbAgentInfo.Controls.Add(this.lblID);
            this.gbAgentInfo.Controls.Add(this.lblCallsPerHourValue);
            this.gbAgentInfo.Controls.Add(this.lblTotalCallsValue);
            this.gbAgentInfo.Controls.Add(this.lblTotalCalls);
            this.gbAgentInfo.Controls.Add(this.lblCallsPerHour);
            this.gbAgentInfo.Location = new System.Drawing.Point(400, 250);
            this.gbAgentInfo.Name = "gbAgentInfo";
            this.gbAgentInfo.Size = new System.Drawing.Size(469, 332);
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
            this.lbSkills.Size = new System.Drawing.Size(93, 160);
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
            this.lblAvgWaitValue.Location = new System.Drawing.Point(144, 28);
            this.lblAvgWaitValue.Name = "lblAvgWaitValue";
            this.lblAvgWaitValue.Size = new System.Drawing.Size(35, 13);
            this.lblAvgWaitValue.TabIndex = 4;
            this.lblAvgWaitValue.Text = "label1";
            // 
            // lblAvgAgentDTValue
            // 
            this.lblAvgAgentDTValue.AutoSize = true;
            this.lblAvgAgentDTValue.Location = new System.Drawing.Point(144, 50);
            this.lblAvgAgentDTValue.Name = "lblAvgAgentDTValue";
            this.lblAvgAgentDTValue.Size = new System.Drawing.Size(35, 13);
            this.lblAvgAgentDTValue.TabIndex = 5;
            this.lblAvgAgentDTValue.Text = "label1";
            // 
            // gbStats
            // 
            this.gbStats.Controls.Add(this.lblAvgAgentDTValue);
            this.gbStats.Controls.Add(this.lblAvgAgentDT);
            this.gbStats.Controls.Add(this.lblAvgWait);
            this.gbStats.Controls.Add(this.lblAvgWaitValue);
            this.gbStats.Location = new System.Drawing.Point(876, 13);
            this.gbStats.Name = "gbStats";
            this.gbStats.Size = new System.Drawing.Size(383, 576);
            this.gbStats.TabIndex = 5;
            this.gbStats.TabStop = false;
            this.gbStats.Text = "Stats";
            // 
            // ProccessQueueTimer
            // 
            this.ProccessQueueTimer.Enabled = true;
            this.ProccessQueueTimer.Interval = 10;
            this.ProccessQueueTimer.Tick += new System.EventHandler(this.ProccessQueueTimer_Tick);
            // 
            // NUIronManForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1271, 594);
            this.Controls.Add(this.gbStats);
            this.Controls.Add(this.gbAgentInfo);
            this.Controls.Add(this.gbCallInfo);
            this.Controls.Add(this.lbAgents);
            this.Controls.Add(this.lbCalls);
            this.Name = "NUIronManForm";
            this.Text = "NUIronMan";
            this.gbAgentInfo.ResumeLayout(false);
            this.gbAgentInfo.PerformLayout();
            this.gbStats.ResumeLayout(false);
            this.gbStats.PerformLayout();
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
    }
}

