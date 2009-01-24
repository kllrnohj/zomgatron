using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgentsAPI;

namespace IronMan
{
    class AgentContainer
    {
        public Agent Agent { get; set; }
        public override string ToString()
        {
            return String.Format("{0}: {1}", Agent.AgentID, Agent.AgentStatusType);
        }

        public override bool Equals(object obj)
        {
            try
            {
                var other = (AgentContainer)obj;
                return Agent.AgentID == other.Agent.AgentID;
            }
            catch (Exception)
            {
                return false;
            }
        }
    }
}
