using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Data;

namespace OS_单处理机进程调度
{
    public class Core
    {
        public List<Process> newList;
        public List<Process> readyList;
        public List<Process> blockList;
        public Process runProcess=null;
        const int timePiece = 3;
        int timePieceCounter = 0;

        public Core()
        {
            newList = new List<Process>();
            readyList = new List<Process>();
            blockList = new List<Process>();
            init();
        }

        public void init()
        {
            newList.Add(new Process("apple", 10,2,8));
            newList.Add(new Process("pear", 10));
            newList.Add(new Process("orange", 10));
        }

        public void newToReady()
        {
            for (int i = 0; i < newList.Count; i++)
            {
                if (newList[i].state == 0)
                {
                    newList[i].p_ready();
                    readyList.Add(newList[i]);
                    newList.RemoveAt(i);
                }
            }
        }

        public void round(MainWindow main, DataTable dt)
        {
            if (readyList.Count > 0)
            {
                runProcess = readyList[0];
                readyList.Remove(runProcess);
                if (runProcess.duration > 0)
                {
                    runProcess.p_run();
                    main.tb_run_process.Text = runProcess.name;
                    main.tb_run_process_duration.Text = runProcess.duration.ToString();
                    main.showData(dt);

                    timePieceCounter++;
                    if (runProcess.state == 2&&timePieceCounter<=timePiece)
                    {
                        readyList.Insert(0, runProcess);
                    }
                    else
                    {
                        timePieceCounter = 0;
                        runProcess.p_ready();
                        readyList.Add(runProcess);
                    }
                }
            }
            else
            {
                main.showData(dt);
                main.tb_run_process.Text = "";
                main.tb_run_process_duration.Text = "";
            }
        }

        public void fifo(MainWindow main,DataTable dt)
        {
            if (readyList.Count > 0)
            {
                runProcess = readyList[0];
                readyList.Remove(runProcess);
                if (runProcess.duration > 0)
                {
                    int flag = runProcess.p_run();
                    main.tb_run_process.Text = runProcess.name;
                    main.tb_run_process_duration.Text = runProcess.duration.ToString();
                    if (flag == 5)
                    {
                        runProcess.p_block();
                        blockList.Add(runProcess);
                    }
                    else
                    {
                        if (runProcess.state == 2)
                        {
                            readyList.Insert(0, runProcess);
                        }
                    }
                }
                //如果组赛队列不为空，等待io，完毕后挂入就绪队列
                if (blockList.Count > 0)
                {
                    Process temp2 = blockList[0];
                    int tempN = temp2.io_end;
                    temp2.io_end--;
                    if (temp2.io_start == temp2.io_end)
                    {
                        temp2.p_ready();
                        //temp2.duration = temp2.io_start;
                        readyList.Add(temp2);
                        blockList.Remove(temp2);
                    }
                }
            }
            main.showData(dt);
        }

    }
}
