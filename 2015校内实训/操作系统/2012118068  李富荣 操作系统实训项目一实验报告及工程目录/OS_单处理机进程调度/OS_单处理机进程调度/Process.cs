using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OS_单处理机进程调度
{

    public class Process
    {
        public const int NEW = 0;
        public const int READY = 1;
        public const int RUNNING = 2;
        public const int BLOCK = 3;
        public const int RELEASE = 4;
        public const int WAITBLOCK = 5;


        //无IO的时候引用
        public Process(string _name,int _duration)
        {
            name = _name;
            duration = _duration;
            isIO = false;
            io_start = -1;
            io_end = -1;
            state = NEW;
        }
        //IO的时候引用
        public Process(string _name,int _duration,int _io_start,int _io_end)
        {
            name = _name;
            duration = _duration;
            io_start = _io_start;
            io_end = _io_end;
            isIO = true;
            state = NEW;
        }
        public string name { get; set; }
        public bool isIO { get; set; }
        public int duration { get; set;}
        public int io_start { get; set; }
        public int io_end { get; set; }
        public int state { get; set; }
        public string stateString(int _state)
        {
            string stateString;
            switch (_state)
            {
                case 0: stateString = "NEW"; break;
                case 1: stateString = "READY"; break;
                case 2: stateString = "EXECU"; break;
                case 3: stateString = "BLOCK"; break;
                case 4: stateString = "RELEASE"; break;
                default: stateString = "NOT EXIST\t"; break;
            }
            return stateString;
        }

        public int p_run()
        {
            state = RUNNING;
            if (duration > 0)
            {
                duration = duration - 1;
            }
            else
            {
                duration = 0;
            }
            if (duration == io_end)
            {
                return WAITBLOCK;
            }
            else
            {
                return RUNNING;
            }
        }

        public int p_block_wait()
        {
            if (io_start < io_end)
            {
                io_start++;
            }
            if (io_start == io_end)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        public void p_block()
        {
            state = BLOCK;
        }

        public void p_ready()
        {
            state = READY;
        }

        public void p_release()
        {
            state = RELEASE;
        }

        public override string ToString()
        {
            return name+"\tis "+stateString(state)+"  timeLeft:   "+duration+"  IO "+isIO;
        }

    }
}
