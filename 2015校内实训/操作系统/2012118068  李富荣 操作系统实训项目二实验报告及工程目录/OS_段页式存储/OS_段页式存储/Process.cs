using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OS_段页式存储
{
    public class Process
    {
        public string name { set; get; }

        public int[] duan=new int[16];

        public List<Duan> duans;


        public Process(string name, List<Duan> duans)
        {
            this.name = name;
            this.duans = duans;
        }

        public override string ToString(){
            return this.name;
        }

    }
}
