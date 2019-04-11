using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OS_段页式存储
{
    public class Duan
    {
        public int[] pageTable{get;set;}
        public int length { get; set; }

        public Duan(int length)
        {
            this.length = length;
            pageTable = new int[pageTableSize(length)];
        }

        public int pageTableSize(int length)
        {
            int total = 0;
                if (length % Form1.pageSize == 0)
                {
                    total = total + length / Form1.pageSize;
                }
                else
                {
                    total = total + (int)length / Form1.pageSize + 1;
                }
            return total;
        }
    }
}
