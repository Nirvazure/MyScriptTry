using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OS_段页式存储
{
    public partial class Form1 : Form
    {
        List<Process> processList;
        public static int pageSize=1;

        int[] memory;   //模拟主存
        //8个驻留集
        int[] Linger1;
        int[] Linger2;
        int[] Linger3;
        int[] Linger4;
        int[] Linger5; 
        int[] Linger6;
        int[] Linger7;
        int[] Linger8;

        List<Process> ProcessListCanPutInMemory;
 
        private void distributeMemory(Process tempProcess)
        {
            if (ProcessListCanPutInMemory != null&&ProcessListCanPutInMemory.Count<4)
            {
                ProcessListCanPutInMemory.Add(tempProcess);
            }
            else
            {
            }
            for (int i = 0; i < ProcessListCanPutInMemory.Count; i++)
            {
                for (int j = 0; j < ProcessListCanPutInMemory[i].duans.Count; j++)
                {
                    for (int k = 0; k < ProcessListCanPutInMemory[i].duans[j].length; k++)
                    {
                        if(i<4&&j<2&&k<8){
                            ProcessListCanPutInMemory[i].duans[j].pageTable[k] = 9;
                        }else{

                        }
                    }
                }
            }
            try
            {
                Linger1 = ProcessListCanPutInMemory[0].duans[0].pageTable;
                Linger2 = ProcessListCanPutInMemory[0].duans[1].pageTable;
                Linger3 = ProcessListCanPutInMemory[1].duans[0].pageTable;
                Linger4 = ProcessListCanPutInMemory[1].duans[1].pageTable;
                Linger5 = ProcessListCanPutInMemory[2].duans[0].pageTable;
                Linger6 = ProcessListCanPutInMemory[2].duans[1].pageTable;
                Linger7 = ProcessListCanPutInMemory[3].duans[0].pageTable;
                Linger8 = ProcessListCanPutInMemory[3].duans[1].pageTable;
            }
            catch { }
        }
        private void lb_seg_SelectedIndexChanged(object sender, EventArgs e)
        {
            isLackPage.Checked = false;
            lb_page.Items.Clear();
            Process temp = (Process)cb_ProcessList.SelectedItem;
            string tempStr="";
            for (int i = 0; i < temp.duans[lb_seg.SelectedIndex].pageTable.Length; i++)
            {
                tempStr = tempStr + (i + 1) + "  " + temp.duans[lb_seg.SelectedIndex].pageTable[i];
                lb_page.Items.Add(tempStr);
                tempStr="";
            }
            if (lb_seg.SelectedIndex < 2)
            {
                isLackSeg.Checked = false;
                SegPlace.Visible = false;
            }
            else
            {
                isLackSeg.Checked = true;
                SegPlace.Visible = true;
            }
            showData();
        }
        private void releaseProcess_Click(object sender, EventArgs e)
        {
            if (cb_ProcessList.SelectedItem != null)
            {
                if (cb_ProcessList.SelectedIndex < 4)
                {
                    int temp = cb_ProcessList.SelectedIndex;
                    cb_ProcessList.Items.RemoveAt(cb_ProcessList.SelectedIndex);
                    switch (temp)
                    {
                        case 0:
                            for (int i = 0; i < ProcessListCanPutInMemory[1].duans.Count; i++)
                            {
                                for (int j = 0; j < ProcessListCanPutInMemory[1].duans[i].pageTable.Length; j++)
                                {
                                    ProcessListCanPutInMemory[1].duans[i].pageTable[j] = 0;
                                }
                            }
                            break;
                        case 1:
                            for (int i = 0; i < ProcessListCanPutInMemory[1].duans.Count; i++)
                            {
                                for (int j = 0; j < ProcessListCanPutInMemory[1].duans[i].pageTable.Length; j++)
                                {
                                    ProcessListCanPutInMemory[1].duans[i].pageTable[j] = 0;
                                }
                            }
                            break;
                        case 2:
                            for (int i = 0; i < ProcessListCanPutInMemory[2].duans.Count; i++)
                            {
                                for (int j = 0; j < ProcessListCanPutInMemory[2].duans[i].pageTable.Length; j++)
                                {
                                    ProcessListCanPutInMemory[2].duans[i].pageTable[j] = 0;
                                }
                            }
                            break;
                        case 3:
                            for (int i = 0; i < ProcessListCanPutInMemory[3].duans.Count; i++)
                            {
                                for (int j = 0; j < ProcessListCanPutInMemory[3].duans[i].pageTable.Length; j++)
                                {
                                    ProcessListCanPutInMemory[3].duans[i].pageTable[j] = 0;
                                }
                            }
                            break;
                    }
                    ProcessListCanPutInMemory.RemoveAt(temp);
                    showData();
                }
            }
        }
        private void lb_page_SelectedIndexChanged(object sender, EventArgs e)
        {
            physicalPosition.Text = "";
            if (lb_page.SelectedItem != null && lb_seg.SelectedItem != null)
            {
                if (lb_page.SelectedIndex > 7)
                {
                    isLackPage.Checked = true;
                    isReplacePage.Visible = true;
                }
                else
                {
                    isLackPage.Checked = false;
                    isReplacePage.Visible = false;
                }
                //如果不缺页不缺段打印物理地址
                if (isLackPage.Checked == false && isLackSeg.Checked == false)
                {
                    int tempInt=cb_ProcessList.SelectedIndex * 20 + (lb_seg.SelectedIndex+1) * 10 + (lb_page.SelectedIndex+1);
                    physicalPosition.Text = tempInt.ToString();
                }
            }
            showData();
        }
        private void SegPlace_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < ProcessListCanPutInMemory[cb_ProcessList.SelectedIndex].duans[lb_seg.SelectedIndex].pageTable.Length; i++)
            {
                ProcessListCanPutInMemory[cb_ProcessList.SelectedIndex].duans[lb_seg.SelectedIndex].pageTable[i] = 9;
            }
            for (int i = 0; i < ProcessListCanPutInMemory[cb_ProcessList.SelectedIndex].duans[0].pageTable.Length; i++)
			{
			    ProcessListCanPutInMemory[cb_ProcessList.SelectedIndex].duans[0].pageTable[i]=0;
			}
            Linger1 = ProcessListCanPutInMemory[cb_ProcessList.SelectedIndex].duans[lb_seg.SelectedIndex].pageTable;
            showData();
        }
        private void isReplacePage_Click(object sender, EventArgs e)
        {
            if (ProcessListCanPutInMemory[cb_ProcessList.SelectedIndex].duans[lb_seg.SelectedIndex].pageTable[0] == 9)
            {
                ProcessListCanPutInMemory[cb_ProcessList.SelectedIndex].duans[lb_seg.SelectedIndex].pageTable[0] = 2;
            }
            else if(ProcessListCanPutInMemory[cb_ProcessList.SelectedIndex].duans[lb_seg.SelectedIndex].pageTable[0] == 2)
            {
                ProcessListCanPutInMemory[cb_ProcessList.SelectedIndex].duans[lb_seg.SelectedIndex].pageTable[0] = 9;
            }              
            showData();
        }


        //UI界面组
        private void button1_Click(object sender, EventArgs e)
        {
            int[] temp = new int[16];
            process_Info.Text = "";
            if (tb_PID.Text != null)
            {
                try
                {
                    temp[0] = Convert.ToInt32(seg1.Text);
                    temp[1] = Convert.ToInt32(seg2.Text);
                    temp[2] = Convert.ToInt32(seg3.Text);
                    temp[3] = Convert.ToInt32(seg4.Text);
                    temp[4] = Convert.ToInt32(seg5.Text);
                    temp[5] = Convert.ToInt32(seg6.Text);
                    temp[6] = Convert.ToInt32(seg7.Text);
                    temp[7] = Convert.ToInt32(seg8.Text);
                    temp[8] = Convert.ToInt32(seg9.Text);
                    temp[9] = Convert.ToInt32(seg10.Text);
                    temp[10] = Convert.ToInt32(seg11.Text);
                    temp[11] = Convert.ToInt32(seg12.Text);
                    temp[12] = Convert.ToInt32(seg13.Text);
                    temp[13] = Convert.ToInt32(seg14.Text);
                    temp[14] = Convert.ToInt32(seg15.Text);
                    temp[15] = Convert.ToInt32(seg16.Text);
                }
                catch { }
                if (!isSomeDuanOver64Seg(temp))
                {
                    List<Duan> tempDuans = new List<Duan>();

                    for (int i = 0; i < temp.Length; i++)
                    {
                        int j = 0;
                        if (temp[i] > 0)
                        {
                            Duan tempDuan = new Duan(temp[i]);
                            tempDuans.Add(tempDuan);
                            j++;
                        }
                    }
                    Process tempProcess = new Process(tb_PID.Text, tempDuans);
                    processList.Add(tempProcess);
                    cb_ProcessList.Items.Add(tempProcess);
                    clearUI();
                    distributeMemory(tempProcess);
                    showData();
                }
                else
                {
                    process_Info.Text = "有块大于64k";
                    clearUI();
                }
            }
        }
        public Form1()
        {
            InitializeComponent();
            init();
        }
        private void init()
        {
            processList = new List<Process>();
            pageSize = 1;
            memory = new int[64];
            for (int i = 0; i < memory.Length; i++)
            {
                memory[i] = 0;
            }
            showMemory();
            Linger1 = new int[8];
            Linger2 = new int[8];
            Linger3 = new int[8];
            Linger4 = new int[8];
            Linger5 = new int[8];
            Linger6 = new int[8];
            Linger7 = new int[8];
            Linger8 = new int[8];
            //四个可以允许在内存中放的进程
            ProcessListCanPutInMemory = new List<Process>();
        }
        private void cb_pageSize_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cb_pageSize.SelectedItem != null)
            {
                try
                {
                    pageSize = Convert.ToInt32(cb_pageSize.SelectedItem.ToString());
                }
                catch { }
            }
        }
        private bool isSomeDuanOver64Seg(int[] temp)
        {
            for (int i = 0; i < temp.Length; i++)
            {
                if (temp[i] > 64)
                {
                    return true;
                }
            }
            return false;
        }
        private void cb_ProcessList_SelectedIndexChanged(object sender, EventArgs e)
        {
            Process temp = null;
            int duanNum = 0;
            if (cb_ProcessList.SelectedItem != null)
            {
                temp = (Process)cb_ProcessList.SelectedItem;
                lb_seg.Items.Clear();
                for (int i = 0; i < temp.duans.Count; i++)
                {
                    if (temp.duans[i].length > 0)
                    {
                        string tempString = "seg" + (i + 1) + "\t" + temp.duans[i].length;
                        lb_seg.Items.Add(tempString);
                        duanNum++;
                    }
                }
            }
            process_Info.Text = "进程" + temp.name + "有" + duanNum + "个段";
        }
        private void clearUI()
        {
            tb_PID.Text = "";
            seg1.Text = "";
            seg2.Text = "";
            seg3.Text = "";
            seg4.Text = "";
            seg5.Text = "";
            seg6.Text = "";
            seg7.Text = "";
            seg8.Text = "";
            seg9.Text = "";
            seg10.Text = "";
            seg11.Text = "";
            seg12.Text = "";
            seg13.Text = "";
            seg14.Text = "";
            seg15.Text = "";
            seg16.Text = "";
        }
        private void showMemory()
        {
            m11.Text = memory[0].ToString();
            m12.Text = memory[1].ToString();
            m13.Text = memory[2].ToString();
            m14.Text = memory[3].ToString();
            m15.Text = memory[4].ToString();
            m16.Text = memory[5].ToString();
            m17.Text = memory[6].ToString();
            m18.Text = memory[7].ToString();
            m21.Text = memory[8].ToString();
            m22.Text = memory[9].ToString();
            m23.Text = memory[10].ToString();
            m24.Text = memory[11].ToString();
            m25.Text = memory[12].ToString();
            m26.Text = memory[13].ToString();
            m27.Text = memory[14].ToString();
            m28.Text = memory[15].ToString();
            m31.Text = memory[16].ToString();
            m32.Text = memory[17].ToString();
            m33.Text = memory[18].ToString();
            m34.Text = memory[19].ToString();
            m35.Text = memory[20].ToString();
            m36.Text = memory[21].ToString();
            m37.Text = memory[22].ToString();
            m38.Text = memory[23].ToString();
            m41.Text = memory[24].ToString();
            m42.Text = memory[25].ToString();
            m43.Text = memory[26].ToString();
            m44.Text = memory[27].ToString();
            m45.Text = memory[28].ToString();
            m46.Text = memory[29].ToString();
            m47.Text = memory[30].ToString();
            m48.Text = memory[31].ToString();
            m51.Text = memory[32].ToString();
            m52.Text = memory[33].ToString();
            m53.Text = memory[34].ToString();
            m54.Text = memory[35].ToString();
            m55.Text = memory[36].ToString();
            m56.Text = memory[37].ToString();
            m57.Text = memory[38].ToString();
            m58.Text = memory[39].ToString();
            m61.Text = memory[40].ToString();
            m62.Text = memory[41].ToString();
            m63.Text = memory[42].ToString();
            m64.Text = memory[43].ToString();
            m65.Text = memory[44].ToString();
            m66.Text = memory[45].ToString();
            m67.Text = memory[46].ToString();
            m68.Text = memory[47].ToString();
            m71.Text = memory[48].ToString();
            m72.Text = memory[49].ToString();
            m73.Text = memory[50].ToString();
            m74.Text = memory[51].ToString();
            m75.Text = memory[52].ToString();
            m76.Text = memory[53].ToString();
            m77.Text = memory[54].ToString();
            m78.Text = memory[55].ToString();
            m81.Text = memory[56].ToString();
            m82.Text = memory[57].ToString();
            m83.Text = memory[58].ToString();
            m84.Text = memory[59].ToString();
            m85.Text = memory[60].ToString();
            m86.Text = memory[61].ToString();
            m87.Text = memory[62].ToString();
            m88.Text = memory[63].ToString();
        }
        public void showData()
        {
            try
            {
                m11.Text = Linger1[0].ToString();
                m12.Text = Linger1[1].ToString();
                m13.Text = Linger1[2].ToString();
                m14.Text = Linger1[3].ToString();
                m15.Text = Linger1[4].ToString();
                m16.Text = Linger1[5].ToString();
                m17.Text = Linger1[6].ToString();
                m18.Text = Linger1[7].ToString();
            }
            catch { }
            try
            {
                m21.Text = Linger2[0].ToString();
                m22.Text = Linger2[1].ToString();
                m23.Text = Linger2[2].ToString();
                m24.Text = Linger2[3].ToString();
                m25.Text = Linger2[4].ToString();
                m26.Text = Linger2[5].ToString();
                m27.Text = Linger2[6].ToString();
                m28.Text = Linger2[7].ToString();
            }
            catch { }
            try
            {
                m31.Text = Linger3[0].ToString();
                m32.Text = Linger3[1].ToString();
                m33.Text = Linger3[2].ToString();
                m34.Text = Linger3[3].ToString();
                m35.Text = Linger3[4].ToString();
                m36.Text = Linger3[5].ToString();
                m37.Text = Linger3[6].ToString();
                m38.Text = Linger3[7].ToString();
            }
            catch { }
            try
            {
                m41.Text = Linger4[0].ToString();
                m42.Text = Linger4[1].ToString();
                m43.Text = Linger4[2].ToString();
                m44.Text = Linger4[3].ToString();
                m45.Text = Linger4[4].ToString();
                m46.Text = Linger4[5].ToString();
                m47.Text = Linger4[6].ToString();
                m48.Text = Linger4[7].ToString();
            }
            catch { }
            try
            {
                m51.Text = Linger5[0].ToString();
                m52.Text = Linger5[1].ToString();
                m53.Text = Linger5[2].ToString();
                m54.Text = Linger5[3].ToString();
                m55.Text = Linger5[4].ToString();
                m56.Text = Linger5[5].ToString();
                m57.Text = Linger5[6].ToString();
                m58.Text = Linger5[7].ToString();
            }
            catch { }
            try
            {
                m61.Text = Linger6[0].ToString();
                m62.Text = Linger6[1].ToString();
                m63.Text = Linger6[2].ToString();
                m64.Text = Linger6[3].ToString();
                m65.Text = Linger6[4].ToString();
                m66.Text = Linger6[5].ToString();
                m67.Text = Linger6[6].ToString();
                m68.Text = Linger6[7].ToString();
            }
            catch { }
            try
            {
                m71.Text = Linger7[0].ToString();
                m72.Text = Linger7[1].ToString();
                m73.Text = Linger7[2].ToString();
                m74.Text = Linger7[3].ToString();
                m75.Text = Linger7[4].ToString();
                m76.Text = Linger7[5].ToString();
                m77.Text = Linger7[6].ToString();
                m78.Text = Linger7[7].ToString();
            }
            catch { }
            try
            {
                m81.Text = Linger8[0].ToString();
                m82.Text = Linger8[1].ToString();
                m83.Text = Linger8[2].ToString();
                m84.Text = Linger8[3].ToString();
                m85.Text = Linger8[4].ToString();
                m86.Text = Linger8[5].ToString();
                m87.Text = Linger8[6].ToString();
                m88.Text = Linger8[7].ToString();
            }
            catch { }
        }

    }
}
