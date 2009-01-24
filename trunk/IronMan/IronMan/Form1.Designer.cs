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
            this.lbCalls = new System.Windows.Forms.ListBox();
            this.lbAgents = new System.Windows.Forms.ListBox();
            this.lblAvgWait = new System.Windows.Forms.Label();
            this.gbCallInfo = new System.Windows.Forms.GroupBox();
            this.lblAvgAgentDT = new System.Windows.Forms.Label();
            this.gbCallInfo.SuspendLayout();
            this.SuspendLayout();
            // 
            // lbCalls
            // 
            this.lbCalls.FormattingEnabled = true;
            this.lbCalls.Location = new System.Drawing.Point(3, 13);
            this.lbCalls.Name = "lbCalls";
            this.lbCalls.Size = new System.Drawing.Size(192, 576);
            this.lbCalls.TabIndex = 0;
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
            this.lblAvgWait.Location = new System.Drawing.Point(6, 25);
            this.lblAvgWait.Name = "lblAvgWait";
            this.lblAvgWait.Size = new System.Drawing.Size(75, 13);
            this.lblAvgWait.TabIndex = 2;
            this.lblAvgWait.Text = "Average Wait:";
            // 
            // gbCallInfo
            // 
            this.gbCallInfo.Controls.Add(this.lblAvgAgentDT);
            this.gbCallInfo.Controls.Add(this.lblAvgWait);
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
            this.lblAvgAgentDT.Location = new System.Drawing.Point(7, 42);
            this.lblAvgAgentDT.Name = "lblAvgAgentDT";
            this.lblAvgAgentDT.Size = new System.Drawing.Size(131, 13);
            this.lblAvgAgentDT.TabIndex = 3;
            this.lblAvgAgentDT.Text = "Average Agent Downtime:";
            // 
            // NUIronManForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1271, 594);
            this.Controls.Add(this.gbCallInfo);
            this.Controls.Add(this.lbAgents);
            this.Controls.Add(this.lbCalls);
            this.Name = "NUIronManForm";
            this.Text = "NUIronMan";
            this.gbCallInfo.ResumeLayout(false);
            this.gbCallInfo.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox lbCalls;
        private System.Windows.Forms.ListBox lbAgents;
        private System.Windows.Forms.Label lblAvgWait;
        private System.Windows.Forms.GroupBox gbCallInfo;
        private System.Windows.Forms.Label lblAvgAgentDT;
    }
}

