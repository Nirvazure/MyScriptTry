using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using System.Timers;

namespace OS_单处理机进程调度
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        DataTable dt;
        Core core;
        private DispatcherTimer timer;

        public MainWindow()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(MainWindow_loaded);
        }

        //界面方法组
        public void init()
        {
            core = new Core();
            //建立表
            dt = new DataTable();
            DataColumn dc = new DataColumn("Process_Name", typeof(string));
            dt.Columns.Add(dc);
            dc = new DataColumn("Duration", typeof(string));
            dt.Columns.Add(dc);
            dc = new DataColumn("IO_Require", typeof(string));
            dt.Columns.Add(dc);
            dc = new DataColumn("IO_start", typeof(string));
            dt.Columns.Add(dc);
            dc = new DataColumn("IO_end", typeof(string));
            dt.Columns.Add(dc);


            //设置datdagrid样式，显示刚才的数据表
            dgShow.CanUserResizeColumns = false;
            dgShow.ColumnWidth = ((dgShow.Width) / 5);
            showData(dt);
        }
        public void showData(DataTable _dt)
        {
            _dt.Clear();
            listbox_ready.Items.Clear();
            listbox_block.Items.Clear();

            for (int i = 0; i < core.newList.Count; i++)
            {
                dt.Rows.Add(core.newList[i].name, core.newList[i].duration, core.newList[i].isIO, core.newList[i].io_start, core.newList[i].io_end);
            }
            dgShow.ItemsSource = _dt.DefaultView;
            for (int i = 0; i < core.readyList.Count; i++)
            {
                listbox_ready.Items.Add(core.readyList[i]);
            }
            for (int i = 0; i < core.blockList.Count; i++)
            {
                listbox_block.Items.Add(core.blockList[i]);
            }
        }
        private void bt_new_Click(object sender, RoutedEventArgs e)
        {
            if (tb_p_name.Text != "" && tb_duration.Text != "")
            {
                string tempName = tb_p_name.Text.ToString();
                int tempDuration = Convert.ToInt32(tb_duration.Text.ToString());
                bool tempIsIO = (bool)checkbox_IO.IsChecked;

                Process temp;
                if (tempIsIO && cb_from1.SelectedItem != null && cb_to.SelectedItem != null)
                {
                    int tempIoStart = Convert.ToInt32(cb_from1.SelectedItem.ToString());
                    int tempIoEnd = Convert.ToInt32(cb_to.SelectedItem.ToString());
                    temp = new Process(tempName, tempDuration, tempIoStart, tempIoEnd);
                }
                else
                {
                    temp = new Process(tempName, tempDuration);
                }
                core.newList.Add(temp);
                showData(dt);
            }
        }
        private void checkbox_IO_Click(object sender, RoutedEventArgs e)
        {
            if (checkbox_IO.IsChecked == true)
            {
                cb_from1.Visibility = Visibility.Visible;
                cb_to.Visibility = Visibility.Visible;
                label_from.Visibility = Visibility.Visible;
                label_to.Visibility = Visibility.Visible;
            }
            else if (checkbox_IO.IsChecked == false)
            {
                cb_from1.Visibility = Visibility.Hidden;
                cb_to.Visibility = Visibility.Hidden;
                label_from.Visibility = Visibility.Hidden;
                label_to.Visibility = Visibility.Hidden;
            }
        }
        private void tb_duration_TextChanged(object sender, TextChangedEventArgs e)
        {
            int temp = Convert.ToInt32(tb_duration.Text.ToString());
            cb_from1.Items.Clear();
            cb_to.Items.Clear();
            if (temp > 0)
            {
                for (int i = 0; i < temp; i++)
                {
                    cb_from1.Items.Add(i);
                }
            }
            if (!cb_from1.Items.IsEmpty)
            {
                for (int i = 0; i < temp; i++)
                {
                    cb_to.Items.Add(i);
                }
            }
        }
        private void cb_from1_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (cb_from1.SelectedItem != null)
            {
                int length = Convert.ToInt32(tb_duration.Text.ToString());
                int temp = Convert.ToInt32(cb_from1.SelectedItem.ToString());
                cb_to.Items.Clear();
                for (int i = temp; i < length - 1; i++)
                {
                    cb_to.Items.Add(i + 1);
                }
            }
        }
        private void bt_break_Click(object sender, RoutedEventArgs e)
        {
            core.readyList.Remove(core.runProcess);
            core.blockList.Add(core.runProcess);
            core.runProcess.p_block();
            showData(dt);
        }
        private void bt_release_Click(object sender, RoutedEventArgs e)
        {
            if (core.blockList != null)
            {
                Process temp = core.blockList[0];
                core.blockList.RemoveAt(0);
                core.readyList.Add(temp);
                temp.p_ready();
                showData(dt);
            }
        }

        //时间方法组
        void MainWindow_loaded(Object sender,RoutedEventArgs e)
        {
            init();
            timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromSeconds(1);
            timer.Tick+=timer2_Tick;
            timer.Tick += timer1_Tick;
            timer.Start();
        }
        public void timer1_Tick(Object sender, EventArgs e)
        {
            core.round(this,dt);
        }
        public void timer2_Tick(Object sender, EventArgs e)
        {
            core.newToReady();
        }


    }


}
