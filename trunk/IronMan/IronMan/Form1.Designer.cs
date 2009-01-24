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
            this.lblCallsPerHour = new System.Windows.Forms.Label();
            this.lblTotalCalls = new System.Windows.Forms.Label();
            this.lblAvgWaitValue = new System.Windows.Forms.Label();
            this.lblAvgAgentDTValue = new System.Windows.Forms.Label();
            this.lblTotalCallsValue = new System.Windows.Forms.Label();
            this.lblCallsPerHourValue = new System.Windows.Forms.Label();
            this.gbStats = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lbSkills = new System.Windows.Forms.ListBox();
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
            this.gbAgentInfo.Controls.Add(this.lbSkills);
            this.gbAgentInfo.Controls.Add(this.label2);
            this.gbAgentInfo.Controls.Add(this.label1);
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
            // lblCallsPerHour
            // 
            this.lblCallsPerHour.AutoSize = true;
            this.lblCallsPerHour.Location = new System.Drawing.Point(6, 118);
            this.lblCallsPerHour.Name = "lblCallsPerHour";
            this.lblCallsPerHour.Size = new System.Drawing.Size(66, 13);
            this.lblCallsPerHour.TabIndex = 0;
            this.lblCallsPerHour.Text = "Calls / Hour:";
            // 
            // lblTotalCalls
            // 
            this.lblTotalCalls.AutoSize = true;
            this.lblTotalCalls.Location = new System.Drawing.Point(6, 87);
            this.lblTotalCalls.Name = "lblTotalCalls";
            this.lblTotalCalls.Size = new System.Drawing.Size(59, 13);
            this.lblTotalCalls.TabIndex = 1;
            this.lblTotalCalls.Text = "Total Calls:";
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
            // lblTotalCallsValue
            // 
            this.lblTotalCallsValue.AutoSize = true;
            this.lblTotalCallsValue.Location = new System.Drawing.Point(111, 87);
            this.lblTotalCallsValue.Name = "lblTotalCallsValue";
            this.lblTotalCallsValue.Size = new System.Drawing.Size(35, 13);
            this.lblTotalCallsValue.TabIndex = 2;
            this.lblTotalCallsValue.Text = "label1";
            // 
            // lblCallsPerHourValue
            // 
            this.lblCallsPerHourValue.AutoSize = true;
            this.lblCallsPerHourValue.Location = new System.Drawing.Point(111, 118);
            this.lblCallsPerHourValue.Name = "lblCallsPerHourValue";
            this.lblCallsPerHourValue.Size = new System.Drawing.Size(35, 13);
            this.lblCallsPerHourValue.TabIndex = 3;
            this.lblCallsPerHourValue.Text = "label1";
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
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "label1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 53);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "label2";
            // 
            // lbSkills
            // 
            this.lbSkills.FormattingEnabled = true;
            this.lbSkills.Location = new System.Drawing.Point(9, 161);
            this.lbSkills.Name = "lbSkills";
            this.lbSkills.Size = new System.Drawing.Size(93, 160);
            this.lbSkills.TabIndex = 6;
            // 
            // ProccessQueueTimer
            // 
            this.ProccessQueueTimer.Enabled = true;
            this.ProccessQueueTimer.Interval = 10;
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
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox gbStats;
        private System.Windows.Forms.Timer ProccessQueueTimer;
    }
}

