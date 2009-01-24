using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace IronMan
{
    static class Log
    {
        static string LogFile = "log.txt";
        static Log()
        {
            if (File.Exists(LogFile))
            {
                File.Delete(LogFile);
                File.CreateText(LogFile).Close();
            }
        }

        public static void LogString(string s)
        {
            File.AppendAllText(LogFile, s);
            File.AppendAllText(LogFile, "\r\n");
        }
    }
}
