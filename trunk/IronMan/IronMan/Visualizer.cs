using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing;
namespace IronMan
{
    public partial class NUIronManForm : Form
    {
        protected override void OnPaint(PaintEventArgs e)
        {
            /*Graphics g = e.Graphics;
            Pen pen = (Pen)new Pen(Color.Green, 1.0f).Clone();
            g.Clear(Color.Black);
            for (int x = 7; x > 3; x--)
            {
                pen.Color = Color.FromArgb(255 - ((x-4) * 0), Color.Green);
                Rectangle ellipse = new Rectangle(30, 30, x, x);
                g.DrawEllipse(pen, ellipse);
            }
            base.OnPaint(e);*/
        }
    }
}
