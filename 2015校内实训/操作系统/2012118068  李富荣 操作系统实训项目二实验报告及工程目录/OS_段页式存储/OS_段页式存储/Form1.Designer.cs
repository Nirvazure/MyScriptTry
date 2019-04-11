namespace OS_段页式存储
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.进程信息 = new System.Windows.Forms.GroupBox();
            this.seg16 = new System.Windows.Forms.TextBox();
            this.seg15 = new System.Windows.Forms.TextBox();
            this.seg14 = new System.Windows.Forms.TextBox();
            this.seg13 = new System.Windows.Forms.TextBox();
            this.seg12 = new System.Windows.Forms.TextBox();
            this.seg11 = new System.Windows.Forms.TextBox();
            this.seg10 = new System.Windows.Forms.TextBox();
            this.seg9 = new System.Windows.Forms.TextBox();
            this.seg8 = new System.Windows.Forms.TextBox();
            this.seg7 = new System.Windows.Forms.TextBox();
            this.seg6 = new System.Windows.Forms.TextBox();
            this.seg5 = new System.Windows.Forms.TextBox();
            this.seg4 = new System.Windows.Forms.TextBox();
            this.seg3 = new System.Windows.Forms.TextBox();
            this.generator = new System.Windows.Forms.Button();
            this.seg2 = new System.Windows.Forms.TextBox();
            this.seg1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tb_PID = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.lb_seg = new System.Windows.Forms.ListBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.lb_page = new System.Windows.Forms.ListBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.SegPlace = new System.Windows.Forms.Button();
            this.isReplacePage = new System.Windows.Forms.Button();
            this.breakInfo = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.physicalPosition = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.m88 = new System.Windows.Forms.TextBox();
            this.m86 = new System.Windows.Forms.TextBox();
            this.m87 = new System.Windows.Forms.TextBox();
            this.m85 = new System.Windows.Forms.TextBox();
            this.m84 = new System.Windows.Forms.TextBox();
            this.m82 = new System.Windows.Forms.TextBox();
            this.m83 = new System.Windows.Forms.TextBox();
            this.m81 = new System.Windows.Forms.TextBox();
            this.m78 = new System.Windows.Forms.TextBox();
            this.m76 = new System.Windows.Forms.TextBox();
            this.m77 = new System.Windows.Forms.TextBox();
            this.m75 = new System.Windows.Forms.TextBox();
            this.m74 = new System.Windows.Forms.TextBox();
            this.m72 = new System.Windows.Forms.TextBox();
            this.m73 = new System.Windows.Forms.TextBox();
            this.m71 = new System.Windows.Forms.TextBox();
            this.m68 = new System.Windows.Forms.TextBox();
            this.m66 = new System.Windows.Forms.TextBox();
            this.m67 = new System.Windows.Forms.TextBox();
            this.m65 = new System.Windows.Forms.TextBox();
            this.m64 = new System.Windows.Forms.TextBox();
            this.m62 = new System.Windows.Forms.TextBox();
            this.m63 = new System.Windows.Forms.TextBox();
            this.m61 = new System.Windows.Forms.TextBox();
            this.m58 = new System.Windows.Forms.TextBox();
            this.m56 = new System.Windows.Forms.TextBox();
            this.m57 = new System.Windows.Forms.TextBox();
            this.m55 = new System.Windows.Forms.TextBox();
            this.m54 = new System.Windows.Forms.TextBox();
            this.m52 = new System.Windows.Forms.TextBox();
            this.m53 = new System.Windows.Forms.TextBox();
            this.m51 = new System.Windows.Forms.TextBox();
            this.m48 = new System.Windows.Forms.TextBox();
            this.m46 = new System.Windows.Forms.TextBox();
            this.m47 = new System.Windows.Forms.TextBox();
            this.m45 = new System.Windows.Forms.TextBox();
            this.m44 = new System.Windows.Forms.TextBox();
            this.m42 = new System.Windows.Forms.TextBox();
            this.m43 = new System.Windows.Forms.TextBox();
            this.m41 = new System.Windows.Forms.TextBox();
            this.m38 = new System.Windows.Forms.TextBox();
            this.m36 = new System.Windows.Forms.TextBox();
            this.m37 = new System.Windows.Forms.TextBox();
            this.m35 = new System.Windows.Forms.TextBox();
            this.m34 = new System.Windows.Forms.TextBox();
            this.m32 = new System.Windows.Forms.TextBox();
            this.m33 = new System.Windows.Forms.TextBox();
            this.m31 = new System.Windows.Forms.TextBox();
            this.m28 = new System.Windows.Forms.TextBox();
            this.m26 = new System.Windows.Forms.TextBox();
            this.m27 = new System.Windows.Forms.TextBox();
            this.m25 = new System.Windows.Forms.TextBox();
            this.m24 = new System.Windows.Forms.TextBox();
            this.m22 = new System.Windows.Forms.TextBox();
            this.m23 = new System.Windows.Forms.TextBox();
            this.m21 = new System.Windows.Forms.TextBox();
            this.m18 = new System.Windows.Forms.TextBox();
            this.m16 = new System.Windows.Forms.TextBox();
            this.m17 = new System.Windows.Forms.TextBox();
            this.m15 = new System.Windows.Forms.TextBox();
            this.m14 = new System.Windows.Forms.TextBox();
            this.m12 = new System.Windows.Forms.TextBox();
            this.m13 = new System.Windows.Forms.TextBox();
            this.m11 = new System.Windows.Forms.TextBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.cb_pageSize = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.releaseProcess = new System.Windows.Forms.Button();
            this.process_Info = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.cb_ProcessList = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.isLackPage = new System.Windows.Forms.CheckBox();
            this.isLackSeg = new System.Windows.Forms.CheckBox();
            this.进程信息.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.SuspendLayout();
            // 
            // 进程信息
            // 
            this.进程信息.Controls.Add(this.seg16);
            this.进程信息.Controls.Add(this.seg15);
            this.进程信息.Controls.Add(this.seg14);
            this.进程信息.Controls.Add(this.seg13);
            this.进程信息.Controls.Add(this.seg12);
            this.进程信息.Controls.Add(this.seg11);
            this.进程信息.Controls.Add(this.seg10);
            this.进程信息.Controls.Add(this.seg9);
            this.进程信息.Controls.Add(this.seg8);
            this.进程信息.Controls.Add(this.seg7);
            this.进程信息.Controls.Add(this.seg6);
            this.进程信息.Controls.Add(this.seg5);
            this.进程信息.Controls.Add(this.seg4);
            this.进程信息.Controls.Add(this.seg3);
            this.进程信息.Controls.Add(this.generator);
            this.进程信息.Controls.Add(this.seg2);
            this.进程信息.Controls.Add(this.seg1);
            this.进程信息.Controls.Add(this.label1);
            this.进程信息.Controls.Add(this.tb_PID);
            this.进程信息.Location = new System.Drawing.Point(12, 23);
            this.进程信息.Name = "进程信息";
            this.进程信息.Size = new System.Drawing.Size(313, 184);
            this.进程信息.TabIndex = 0;
            this.进程信息.TabStop = false;
            this.进程信息.Text = "进程信息";
            // 
            // seg16
            // 
            this.seg16.Location = new System.Drawing.Point(227, 145);
            this.seg16.Name = "seg16";
            this.seg16.Size = new System.Drawing.Size(49, 21);
            this.seg16.TabIndex = 23;
            // 
            // seg15
            // 
            this.seg15.Location = new System.Drawing.Point(162, 145);
            this.seg15.Name = "seg15";
            this.seg15.Size = new System.Drawing.Size(49, 21);
            this.seg15.TabIndex = 22;
            // 
            // seg14
            // 
            this.seg14.Location = new System.Drawing.Point(95, 145);
            this.seg14.Name = "seg14";
            this.seg14.Size = new System.Drawing.Size(49, 21);
            this.seg14.TabIndex = 21;
            // 
            // seg13
            // 
            this.seg13.Location = new System.Drawing.Point(30, 145);
            this.seg13.Name = "seg13";
            this.seg13.Size = new System.Drawing.Size(49, 21);
            this.seg13.TabIndex = 20;
            // 
            // seg12
            // 
            this.seg12.Location = new System.Drawing.Point(227, 118);
            this.seg12.Name = "seg12";
            this.seg12.Size = new System.Drawing.Size(49, 21);
            this.seg12.TabIndex = 19;
            // 
            // seg11
            // 
            this.seg11.Location = new System.Drawing.Point(162, 118);
            this.seg11.Name = "seg11";
            this.seg11.Size = new System.Drawing.Size(49, 21);
            this.seg11.TabIndex = 18;
            // 
            // seg10
            // 
            this.seg10.Location = new System.Drawing.Point(95, 118);
            this.seg10.Name = "seg10";
            this.seg10.Size = new System.Drawing.Size(49, 21);
            this.seg10.TabIndex = 17;
            // 
            // seg9
            // 
            this.seg9.Location = new System.Drawing.Point(30, 118);
            this.seg9.Name = "seg9";
            this.seg9.Size = new System.Drawing.Size(49, 21);
            this.seg9.TabIndex = 16;
            // 
            // seg8
            // 
            this.seg8.Location = new System.Drawing.Point(227, 91);
            this.seg8.Name = "seg8";
            this.seg8.Size = new System.Drawing.Size(49, 21);
            this.seg8.TabIndex = 15;
            // 
            // seg7
            // 
            this.seg7.Location = new System.Drawing.Point(162, 91);
            this.seg7.Name = "seg7";
            this.seg7.Size = new System.Drawing.Size(49, 21);
            this.seg7.TabIndex = 14;
            // 
            // seg6
            // 
            this.seg6.Location = new System.Drawing.Point(95, 91);
            this.seg6.Name = "seg6";
            this.seg6.Size = new System.Drawing.Size(49, 21);
            this.seg6.TabIndex = 13;
            // 
            // seg5
            // 
            this.seg5.Location = new System.Drawing.Point(30, 91);
            this.seg5.Name = "seg5";
            this.seg5.Size = new System.Drawing.Size(49, 21);
            this.seg5.TabIndex = 12;
            // 
            // seg4
            // 
            this.seg4.Location = new System.Drawing.Point(227, 64);
            this.seg4.Name = "seg4";
            this.seg4.Size = new System.Drawing.Size(49, 21);
            this.seg4.TabIndex = 11;
            // 
            // seg3
            // 
            this.seg3.Location = new System.Drawing.Point(162, 64);
            this.seg3.Name = "seg3";
            this.seg3.Size = new System.Drawing.Size(49, 21);
            this.seg3.TabIndex = 10;
            // 
            // generator
            // 
            this.generator.Location = new System.Drawing.Point(225, 30);
            this.generator.Name = "generator";
            this.generator.Size = new System.Drawing.Size(54, 23);
            this.generator.TabIndex = 9;
            this.generator.Text = "生成";
            this.generator.UseVisualStyleBackColor = true;
            this.generator.Click += new System.EventHandler(this.button1_Click);
            // 
            // seg2
            // 
            this.seg2.Location = new System.Drawing.Point(95, 64);
            this.seg2.Name = "seg2";
            this.seg2.Size = new System.Drawing.Size(49, 21);
            this.seg2.TabIndex = 6;
            // 
            // seg1
            // 
            this.seg1.Location = new System.Drawing.Point(30, 64);
            this.seg1.Name = "seg1";
            this.seg1.Size = new System.Drawing.Size(49, 21);
            this.seg1.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(22, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "进程名";
            // 
            // tb_PID
            // 
            this.tb_PID.Location = new System.Drawing.Point(85, 32);
            this.tb_PID.Name = "tb_PID";
            this.tb_PID.Size = new System.Drawing.Size(123, 21);
            this.tb_PID.TabIndex = 0;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.lb_seg);
            this.groupBox2.Location = new System.Drawing.Point(20, 64);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(124, 188);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "段表信息";
            // 
            // lb_seg
            // 
            this.lb_seg.FormattingEnabled = true;
            this.lb_seg.ItemHeight = 12;
            this.lb_seg.Location = new System.Drawing.Point(14, 32);
            this.lb_seg.Name = "lb_seg";
            this.lb_seg.Size = new System.Drawing.Size(97, 136);
            this.lb_seg.TabIndex = 0;
            this.lb_seg.SelectedIndexChanged += new System.EventHandler(this.lb_seg_SelectedIndexChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.lb_page);
            this.groupBox1.Location = new System.Drawing.Point(155, 64);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(124, 188);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "页表信息";
            // 
            // lb_page
            // 
            this.lb_page.FormattingEnabled = true;
            this.lb_page.ItemHeight = 12;
            this.lb_page.Location = new System.Drawing.Point(14, 32);
            this.lb_page.Name = "lb_page";
            this.lb_page.Size = new System.Drawing.Size(97, 136);
            this.lb_page.TabIndex = 1;
            this.lb_page.SelectedIndexChanged += new System.EventHandler(this.lb_page_SelectedIndexChanged);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.isLackSeg);
            this.groupBox3.Controls.Add(this.isLackPage);
            this.groupBox3.Controls.Add(this.label3);
            this.groupBox3.Controls.Add(this.SegPlace);
            this.groupBox3.Controls.Add(this.isReplacePage);
            this.groupBox3.Controls.Add(this.breakInfo);
            this.groupBox3.Controls.Add(this.label7);
            this.groupBox3.Controls.Add(this.physicalPosition);
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Location = new System.Drawing.Point(350, 23);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(311, 184);
            this.groupBox3.TabIndex = 3;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "groupBox3";
            // 
            // SegPlace
            // 
            this.SegPlace.Location = new System.Drawing.Point(137, 144);
            this.SegPlace.Name = "SegPlace";
            this.SegPlace.Size = new System.Drawing.Size(81, 21);
            this.SegPlace.TabIndex = 17;
            this.SegPlace.Text = "SegRepalce";
            this.SegPlace.UseVisualStyleBackColor = true;
            this.SegPlace.Visible = false;
            this.SegPlace.Click += new System.EventHandler(this.SegPlace_Click);
            // 
            // isReplacePage
            // 
            this.isReplacePage.Location = new System.Drawing.Point(20, 144);
            this.isReplacePage.Name = "isReplacePage";
            this.isReplacePage.Size = new System.Drawing.Size(81, 21);
            this.isReplacePage.TabIndex = 16;
            this.isReplacePage.Text = "PageRepalce";
            this.isReplacePage.UseVisualStyleBackColor = true;
            this.isReplacePage.Visible = false;
            this.isReplacePage.Click += new System.EventHandler(this.isReplacePage_Click);
            // 
            // breakInfo
            // 
            this.breakInfo.Location = new System.Drawing.Point(71, 64);
            this.breakInfo.Multiline = true;
            this.breakInfo.Name = "breakInfo";
            this.breakInfo.Size = new System.Drawing.Size(126, 63);
            this.breakInfo.TabIndex = 15;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(12, 67);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 12);
            this.label7.TabIndex = 14;
            this.label7.Text = "缺页信息";
            // 
            // physicalPosition
            // 
            this.physicalPosition.Location = new System.Drawing.Point(71, 26);
            this.physicalPosition.Name = "physicalPosition";
            this.physicalPosition.Size = new System.Drawing.Size(126, 21);
            this.physicalPosition.TabIndex = 12;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(12, 30);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(53, 12);
            this.label6.TabIndex = 11;
            this.label6.Text = "物理地址";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(203, 30);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(53, 12);
            this.label5.TabIndex = 10;
            this.label5.Text = "是否缺页";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.m88);
            this.groupBox4.Controls.Add(this.m86);
            this.groupBox4.Controls.Add(this.m87);
            this.groupBox4.Controls.Add(this.m85);
            this.groupBox4.Controls.Add(this.m84);
            this.groupBox4.Controls.Add(this.m82);
            this.groupBox4.Controls.Add(this.m83);
            this.groupBox4.Controls.Add(this.m81);
            this.groupBox4.Controls.Add(this.m78);
            this.groupBox4.Controls.Add(this.m76);
            this.groupBox4.Controls.Add(this.m77);
            this.groupBox4.Controls.Add(this.m75);
            this.groupBox4.Controls.Add(this.m74);
            this.groupBox4.Controls.Add(this.m72);
            this.groupBox4.Controls.Add(this.m73);
            this.groupBox4.Controls.Add(this.m71);
            this.groupBox4.Controls.Add(this.m68);
            this.groupBox4.Controls.Add(this.m66);
            this.groupBox4.Controls.Add(this.m67);
            this.groupBox4.Controls.Add(this.m65);
            this.groupBox4.Controls.Add(this.m64);
            this.groupBox4.Controls.Add(this.m62);
            this.groupBox4.Controls.Add(this.m63);
            this.groupBox4.Controls.Add(this.m61);
            this.groupBox4.Controls.Add(this.m58);
            this.groupBox4.Controls.Add(this.m56);
            this.groupBox4.Controls.Add(this.m57);
            this.groupBox4.Controls.Add(this.m55);
            this.groupBox4.Controls.Add(this.m54);
            this.groupBox4.Controls.Add(this.m52);
            this.groupBox4.Controls.Add(this.m53);
            this.groupBox4.Controls.Add(this.m51);
            this.groupBox4.Controls.Add(this.m48);
            this.groupBox4.Controls.Add(this.m46);
            this.groupBox4.Controls.Add(this.m47);
            this.groupBox4.Controls.Add(this.m45);
            this.groupBox4.Controls.Add(this.m44);
            this.groupBox4.Controls.Add(this.m42);
            this.groupBox4.Controls.Add(this.m43);
            this.groupBox4.Controls.Add(this.m41);
            this.groupBox4.Controls.Add(this.m38);
            this.groupBox4.Controls.Add(this.m36);
            this.groupBox4.Controls.Add(this.m37);
            this.groupBox4.Controls.Add(this.m35);
            this.groupBox4.Controls.Add(this.m34);
            this.groupBox4.Controls.Add(this.m32);
            this.groupBox4.Controls.Add(this.m33);
            this.groupBox4.Controls.Add(this.m31);
            this.groupBox4.Controls.Add(this.m28);
            this.groupBox4.Controls.Add(this.m26);
            this.groupBox4.Controls.Add(this.m27);
            this.groupBox4.Controls.Add(this.m25);
            this.groupBox4.Controls.Add(this.m24);
            this.groupBox4.Controls.Add(this.m22);
            this.groupBox4.Controls.Add(this.m23);
            this.groupBox4.Controls.Add(this.m21);
            this.groupBox4.Controls.Add(this.m18);
            this.groupBox4.Controls.Add(this.m16);
            this.groupBox4.Controls.Add(this.m17);
            this.groupBox4.Controls.Add(this.m15);
            this.groupBox4.Controls.Add(this.m14);
            this.groupBox4.Controls.Add(this.m12);
            this.groupBox4.Controls.Add(this.m13);
            this.groupBox4.Controls.Add(this.m11);
            this.groupBox4.Location = new System.Drawing.Point(346, 230);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(314, 243);
            this.groupBox4.TabIndex = 4;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "内存分配信息-64k/64";
            // 
            // m88
            // 
            this.m88.Enabled = false;
            this.m88.Location = new System.Drawing.Point(256, 209);
            this.m88.Name = "m88";
            this.m88.Size = new System.Drawing.Size(28, 21);
            this.m88.TabIndex = 89;
            // 
            // m86
            // 
            this.m86.Enabled = false;
            this.m86.Location = new System.Drawing.Point(185, 209);
            this.m86.Name = "m86";
            this.m86.Size = new System.Drawing.Size(28, 21);
            this.m86.TabIndex = 88;
            // 
            // m87
            // 
            this.m87.Enabled = false;
            this.m87.Location = new System.Drawing.Point(222, 209);
            this.m87.Name = "m87";
            this.m87.Size = new System.Drawing.Size(28, 21);
            this.m87.TabIndex = 87;
            // 
            // m85
            // 
            this.m85.Enabled = false;
            this.m85.Location = new System.Drawing.Point(150, 209);
            this.m85.Name = "m85";
            this.m85.Size = new System.Drawing.Size(28, 21);
            this.m85.TabIndex = 86;
            // 
            // m84
            // 
            this.m84.Enabled = false;
            this.m84.Location = new System.Drawing.Point(112, 209);
            this.m84.Name = "m84";
            this.m84.Size = new System.Drawing.Size(28, 21);
            this.m84.TabIndex = 85;
            // 
            // m82
            // 
            this.m82.Enabled = false;
            this.m82.Location = new System.Drawing.Point(41, 209);
            this.m82.Name = "m82";
            this.m82.Size = new System.Drawing.Size(28, 21);
            this.m82.TabIndex = 84;
            // 
            // m83
            // 
            this.m83.Enabled = false;
            this.m83.Location = new System.Drawing.Point(78, 209);
            this.m83.Name = "m83";
            this.m83.Size = new System.Drawing.Size(28, 21);
            this.m83.TabIndex = 83;
            // 
            // m81
            // 
            this.m81.Enabled = false;
            this.m81.Location = new System.Drawing.Point(6, 209);
            this.m81.Name = "m81";
            this.m81.Size = new System.Drawing.Size(28, 21);
            this.m81.TabIndex = 82;
            // 
            // m78
            // 
            this.m78.Enabled = false;
            this.m78.Location = new System.Drawing.Point(256, 182);
            this.m78.Name = "m78";
            this.m78.Size = new System.Drawing.Size(28, 21);
            this.m78.TabIndex = 81;
            // 
            // m76
            // 
            this.m76.Enabled = false;
            this.m76.Location = new System.Drawing.Point(185, 182);
            this.m76.Name = "m76";
            this.m76.Size = new System.Drawing.Size(28, 21);
            this.m76.TabIndex = 80;
            // 
            // m77
            // 
            this.m77.Enabled = false;
            this.m77.Location = new System.Drawing.Point(222, 182);
            this.m77.Name = "m77";
            this.m77.Size = new System.Drawing.Size(28, 21);
            this.m77.TabIndex = 79;
            // 
            // m75
            // 
            this.m75.Enabled = false;
            this.m75.Location = new System.Drawing.Point(150, 182);
            this.m75.Name = "m75";
            this.m75.Size = new System.Drawing.Size(28, 21);
            this.m75.TabIndex = 78;
            // 
            // m74
            // 
            this.m74.Enabled = false;
            this.m74.Location = new System.Drawing.Point(112, 182);
            this.m74.Name = "m74";
            this.m74.Size = new System.Drawing.Size(28, 21);
            this.m74.TabIndex = 77;
            // 
            // m72
            // 
            this.m72.Enabled = false;
            this.m72.Location = new System.Drawing.Point(41, 182);
            this.m72.Name = "m72";
            this.m72.Size = new System.Drawing.Size(28, 21);
            this.m72.TabIndex = 76;
            // 
            // m73
            // 
            this.m73.Enabled = false;
            this.m73.Location = new System.Drawing.Point(78, 182);
            this.m73.Name = "m73";
            this.m73.Size = new System.Drawing.Size(28, 21);
            this.m73.TabIndex = 75;
            // 
            // m71
            // 
            this.m71.Enabled = false;
            this.m71.Location = new System.Drawing.Point(6, 182);
            this.m71.Name = "m71";
            this.m71.Size = new System.Drawing.Size(28, 21);
            this.m71.TabIndex = 74;
            // 
            // m68
            // 
            this.m68.Enabled = false;
            this.m68.Location = new System.Drawing.Point(256, 155);
            this.m68.Name = "m68";
            this.m68.Size = new System.Drawing.Size(28, 21);
            this.m68.TabIndex = 73;
            // 
            // m66
            // 
            this.m66.Enabled = false;
            this.m66.Location = new System.Drawing.Point(185, 155);
            this.m66.Name = "m66";
            this.m66.Size = new System.Drawing.Size(28, 21);
            this.m66.TabIndex = 72;
            // 
            // m67
            // 
            this.m67.Enabled = false;
            this.m67.Location = new System.Drawing.Point(222, 155);
            this.m67.Name = "m67";
            this.m67.Size = new System.Drawing.Size(28, 21);
            this.m67.TabIndex = 71;
            // 
            // m65
            // 
            this.m65.Enabled = false;
            this.m65.Location = new System.Drawing.Point(150, 155);
            this.m65.Name = "m65";
            this.m65.Size = new System.Drawing.Size(28, 21);
            this.m65.TabIndex = 70;
            // 
            // m64
            // 
            this.m64.Enabled = false;
            this.m64.Location = new System.Drawing.Point(112, 155);
            this.m64.Name = "m64";
            this.m64.Size = new System.Drawing.Size(28, 21);
            this.m64.TabIndex = 69;
            // 
            // m62
            // 
            this.m62.Enabled = false;
            this.m62.Location = new System.Drawing.Point(41, 155);
            this.m62.Name = "m62";
            this.m62.Size = new System.Drawing.Size(28, 21);
            this.m62.TabIndex = 68;
            // 
            // m63
            // 
            this.m63.Enabled = false;
            this.m63.Location = new System.Drawing.Point(78, 155);
            this.m63.Name = "m63";
            this.m63.Size = new System.Drawing.Size(28, 21);
            this.m63.TabIndex = 67;
            // 
            // m61
            // 
            this.m61.Enabled = false;
            this.m61.Location = new System.Drawing.Point(6, 155);
            this.m61.Name = "m61";
            this.m61.Size = new System.Drawing.Size(28, 21);
            this.m61.TabIndex = 66;
            // 
            // m58
            // 
            this.m58.Enabled = false;
            this.m58.Location = new System.Drawing.Point(256, 128);
            this.m58.Name = "m58";
            this.m58.Size = new System.Drawing.Size(28, 21);
            this.m58.TabIndex = 65;
            // 
            // m56
            // 
            this.m56.Enabled = false;
            this.m56.Location = new System.Drawing.Point(185, 128);
            this.m56.Name = "m56";
            this.m56.Size = new System.Drawing.Size(28, 21);
            this.m56.TabIndex = 64;
            // 
            // m57
            // 
            this.m57.Enabled = false;
            this.m57.Location = new System.Drawing.Point(222, 128);
            this.m57.Name = "m57";
            this.m57.Size = new System.Drawing.Size(28, 21);
            this.m57.TabIndex = 63;
            // 
            // m55
            // 
            this.m55.Enabled = false;
            this.m55.Location = new System.Drawing.Point(150, 128);
            this.m55.Name = "m55";
            this.m55.Size = new System.Drawing.Size(28, 21);
            this.m55.TabIndex = 62;
            // 
            // m54
            // 
            this.m54.Enabled = false;
            this.m54.Location = new System.Drawing.Point(112, 128);
            this.m54.Name = "m54";
            this.m54.Size = new System.Drawing.Size(28, 21);
            this.m54.TabIndex = 61;
            // 
            // m52
            // 
            this.m52.Enabled = false;
            this.m52.Location = new System.Drawing.Point(41, 128);
            this.m52.Name = "m52";
            this.m52.Size = new System.Drawing.Size(28, 21);
            this.m52.TabIndex = 60;
            // 
            // m53
            // 
            this.m53.Enabled = false;
            this.m53.Location = new System.Drawing.Point(78, 128);
            this.m53.Name = "m53";
            this.m53.Size = new System.Drawing.Size(28, 21);
            this.m53.TabIndex = 59;
            // 
            // m51
            // 
            this.m51.Enabled = false;
            this.m51.Location = new System.Drawing.Point(6, 128);
            this.m51.Name = "m51";
            this.m51.Size = new System.Drawing.Size(28, 21);
            this.m51.TabIndex = 58;
            // 
            // m48
            // 
            this.m48.Enabled = false;
            this.m48.Location = new System.Drawing.Point(256, 101);
            this.m48.Name = "m48";
            this.m48.Size = new System.Drawing.Size(28, 21);
            this.m48.TabIndex = 57;
            // 
            // m46
            // 
            this.m46.Enabled = false;
            this.m46.Location = new System.Drawing.Point(185, 101);
            this.m46.Name = "m46";
            this.m46.Size = new System.Drawing.Size(28, 21);
            this.m46.TabIndex = 56;
            // 
            // m47
            // 
            this.m47.Enabled = false;
            this.m47.Location = new System.Drawing.Point(222, 101);
            this.m47.Name = "m47";
            this.m47.Size = new System.Drawing.Size(28, 21);
            this.m47.TabIndex = 55;
            // 
            // m45
            // 
            this.m45.Enabled = false;
            this.m45.Location = new System.Drawing.Point(150, 101);
            this.m45.Name = "m45";
            this.m45.Size = new System.Drawing.Size(28, 21);
            this.m45.TabIndex = 54;
            // 
            // m44
            // 
            this.m44.Enabled = false;
            this.m44.Location = new System.Drawing.Point(112, 101);
            this.m44.Name = "m44";
            this.m44.Size = new System.Drawing.Size(28, 21);
            this.m44.TabIndex = 53;
            // 
            // m42
            // 
            this.m42.Enabled = false;
            this.m42.Location = new System.Drawing.Point(41, 101);
            this.m42.Name = "m42";
            this.m42.Size = new System.Drawing.Size(28, 21);
            this.m42.TabIndex = 52;
            // 
            // m43
            // 
            this.m43.Enabled = false;
            this.m43.Location = new System.Drawing.Point(78, 101);
            this.m43.Name = "m43";
            this.m43.Size = new System.Drawing.Size(28, 21);
            this.m43.TabIndex = 51;
            // 
            // m41
            // 
            this.m41.Enabled = false;
            this.m41.Location = new System.Drawing.Point(6, 101);
            this.m41.Name = "m41";
            this.m41.Size = new System.Drawing.Size(28, 21);
            this.m41.TabIndex = 50;
            // 
            // m38
            // 
            this.m38.Enabled = false;
            this.m38.Location = new System.Drawing.Point(256, 74);
            this.m38.Name = "m38";
            this.m38.Size = new System.Drawing.Size(28, 21);
            this.m38.TabIndex = 49;
            // 
            // m36
            // 
            this.m36.Enabled = false;
            this.m36.Location = new System.Drawing.Point(185, 74);
            this.m36.Name = "m36";
            this.m36.Size = new System.Drawing.Size(28, 21);
            this.m36.TabIndex = 48;
            // 
            // m37
            // 
            this.m37.Enabled = false;
            this.m37.Location = new System.Drawing.Point(222, 74);
            this.m37.Name = "m37";
            this.m37.Size = new System.Drawing.Size(28, 21);
            this.m37.TabIndex = 47;
            // 
            // m35
            // 
            this.m35.Enabled = false;
            this.m35.Location = new System.Drawing.Point(150, 74);
            this.m35.Name = "m35";
            this.m35.Size = new System.Drawing.Size(28, 21);
            this.m35.TabIndex = 46;
            // 
            // m34
            // 
            this.m34.Enabled = false;
            this.m34.Location = new System.Drawing.Point(112, 74);
            this.m34.Name = "m34";
            this.m34.Size = new System.Drawing.Size(28, 21);
            this.m34.TabIndex = 45;
            // 
            // m32
            // 
            this.m32.Enabled = false;
            this.m32.Location = new System.Drawing.Point(41, 74);
            this.m32.Name = "m32";
            this.m32.Size = new System.Drawing.Size(28, 21);
            this.m32.TabIndex = 44;
            // 
            // m33
            // 
            this.m33.Enabled = false;
            this.m33.Location = new System.Drawing.Point(78, 74);
            this.m33.Name = "m33";
            this.m33.Size = new System.Drawing.Size(28, 21);
            this.m33.TabIndex = 43;
            // 
            // m31
            // 
            this.m31.Enabled = false;
            this.m31.Location = new System.Drawing.Point(6, 74);
            this.m31.Name = "m31";
            this.m31.Size = new System.Drawing.Size(28, 21);
            this.m31.TabIndex = 42;
            // 
            // m28
            // 
            this.m28.Enabled = false;
            this.m28.Location = new System.Drawing.Point(256, 47);
            this.m28.Name = "m28";
            this.m28.Size = new System.Drawing.Size(28, 21);
            this.m28.TabIndex = 41;
            // 
            // m26
            // 
            this.m26.Enabled = false;
            this.m26.Location = new System.Drawing.Point(185, 47);
            this.m26.Name = "m26";
            this.m26.Size = new System.Drawing.Size(28, 21);
            this.m26.TabIndex = 40;
            // 
            // m27
            // 
            this.m27.Enabled = false;
            this.m27.Location = new System.Drawing.Point(222, 47);
            this.m27.Name = "m27";
            this.m27.Size = new System.Drawing.Size(28, 21);
            this.m27.TabIndex = 39;
            // 
            // m25
            // 
            this.m25.Enabled = false;
            this.m25.Location = new System.Drawing.Point(150, 47);
            this.m25.Name = "m25";
            this.m25.Size = new System.Drawing.Size(28, 21);
            this.m25.TabIndex = 38;
            // 
            // m24
            // 
            this.m24.Enabled = false;
            this.m24.Location = new System.Drawing.Point(112, 47);
            this.m24.Name = "m24";
            this.m24.Size = new System.Drawing.Size(28, 21);
            this.m24.TabIndex = 37;
            // 
            // m22
            // 
            this.m22.Enabled = false;
            this.m22.Location = new System.Drawing.Point(41, 47);
            this.m22.Name = "m22";
            this.m22.Size = new System.Drawing.Size(28, 21);
            this.m22.TabIndex = 36;
            // 
            // m23
            // 
            this.m23.Enabled = false;
            this.m23.Location = new System.Drawing.Point(78, 47);
            this.m23.Name = "m23";
            this.m23.Size = new System.Drawing.Size(28, 21);
            this.m23.TabIndex = 35;
            // 
            // m21
            // 
            this.m21.Enabled = false;
            this.m21.Location = new System.Drawing.Point(6, 47);
            this.m21.Name = "m21";
            this.m21.Size = new System.Drawing.Size(28, 21);
            this.m21.TabIndex = 34;
            // 
            // m18
            // 
            this.m18.Enabled = false;
            this.m18.Location = new System.Drawing.Point(256, 20);
            this.m18.Name = "m18";
            this.m18.Size = new System.Drawing.Size(28, 21);
            this.m18.TabIndex = 33;
            // 
            // m16
            // 
            this.m16.Enabled = false;
            this.m16.Location = new System.Drawing.Point(185, 20);
            this.m16.Name = "m16";
            this.m16.Size = new System.Drawing.Size(28, 21);
            this.m16.TabIndex = 32;
            // 
            // m17
            // 
            this.m17.Enabled = false;
            this.m17.Location = new System.Drawing.Point(222, 20);
            this.m17.Name = "m17";
            this.m17.Size = new System.Drawing.Size(28, 21);
            this.m17.TabIndex = 31;
            // 
            // m15
            // 
            this.m15.Enabled = false;
            this.m15.Location = new System.Drawing.Point(150, 20);
            this.m15.Name = "m15";
            this.m15.Size = new System.Drawing.Size(28, 21);
            this.m15.TabIndex = 30;
            // 
            // m14
            // 
            this.m14.Enabled = false;
            this.m14.Location = new System.Drawing.Point(112, 20);
            this.m14.Name = "m14";
            this.m14.Size = new System.Drawing.Size(28, 21);
            this.m14.TabIndex = 29;
            // 
            // m12
            // 
            this.m12.Enabled = false;
            this.m12.Location = new System.Drawing.Point(41, 20);
            this.m12.Name = "m12";
            this.m12.Size = new System.Drawing.Size(28, 21);
            this.m12.TabIndex = 28;
            // 
            // m13
            // 
            this.m13.Enabled = false;
            this.m13.Location = new System.Drawing.Point(78, 20);
            this.m13.Name = "m13";
            this.m13.Size = new System.Drawing.Size(28, 21);
            this.m13.TabIndex = 27;
            // 
            // m11
            // 
            this.m11.Enabled = false;
            this.m11.Location = new System.Drawing.Point(6, 20);
            this.m11.Name = "m11";
            this.m11.Size = new System.Drawing.Size(28, 21);
            this.m11.TabIndex = 26;
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.label2);
            this.groupBox5.Controls.Add(this.cb_pageSize);
            this.groupBox5.Controls.Add(this.label8);
            this.groupBox5.Location = new System.Drawing.Point(346, 480);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(309, 57);
            this.groupBox5.TabIndex = 5;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "系统信息";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(110, 23);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(11, 12);
            this.label2.TabIndex = 17;
            this.label2.Text = "K";
            // 
            // cb_pageSize
            // 
            this.cb_pageSize.FormattingEnabled = true;
            this.cb_pageSize.Items.AddRange(new object[] {
            "1",
            "2",
            "3"});
            this.cb_pageSize.Location = new System.Drawing.Point(70, 20);
            this.cb_pageSize.Name = "cb_pageSize";
            this.cb_pageSize.Size = new System.Drawing.Size(36, 20);
            this.cb_pageSize.TabIndex = 9;
            this.cb_pageSize.Text = "1";
            this.cb_pageSize.SelectedIndexChanged += new System.EventHandler(this.cb_pageSize_SelectedIndexChanged);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(23, 24);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(41, 12);
            this.label8.TabIndex = 16;
            this.label8.Text = "页大小";
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.releaseProcess);
            this.groupBox6.Controls.Add(this.process_Info);
            this.groupBox6.Controls.Add(this.label9);
            this.groupBox6.Controls.Add(this.cb_ProcessList);
            this.groupBox6.Controls.Add(this.groupBox1);
            this.groupBox6.Controls.Add(this.groupBox2);
            this.groupBox6.Location = new System.Drawing.Point(12, 213);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(313, 324);
            this.groupBox6.TabIndex = 6;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "groupBox6";
            // 
            // releaseProcess
            // 
            this.releaseProcess.Location = new System.Drawing.Point(207, 25);
            this.releaseProcess.Name = "releaseProcess";
            this.releaseProcess.Size = new System.Drawing.Size(72, 20);
            this.releaseProcess.TabIndex = 12;
            this.releaseProcess.Text = "关闭进程";
            this.releaseProcess.UseVisualStyleBackColor = true;
            this.releaseProcess.Click += new System.EventHandler(this.releaseProcess_Click);
            // 
            // process_Info
            // 
            this.process_Info.Location = new System.Drawing.Point(25, 266);
            this.process_Info.Name = "process_Info";
            this.process_Info.Size = new System.Drawing.Size(253, 21);
            this.process_Info.TabIndex = 11;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(38, 28);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(41, 12);
            this.label9.TabIndex = 10;
            this.label9.Text = "进程名";
            // 
            // cb_ProcessList
            // 
            this.cb_ProcessList.FormattingEnabled = true;
            this.cb_ProcessList.Location = new System.Drawing.Point(85, 25);
            this.cb_ProcessList.Name = "cb_ProcessList";
            this.cb_ProcessList.Size = new System.Drawing.Size(112, 20);
            this.cb_ProcessList.TabIndex = 3;
            this.cb_ProcessList.SelectedIndexChanged += new System.EventHandler(this.cb_ProcessList_SelectedIndexChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(203, 64);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 18;
            this.label3.Text = "是否缺段";
            // 
            // isLackPage
            // 
            this.isLackPage.AutoSize = true;
            this.isLackPage.Location = new System.Drawing.Point(265, 29);
            this.isLackPage.Name = "isLackPage";
            this.isLackPage.Size = new System.Drawing.Size(15, 14);
            this.isLackPage.TabIndex = 22;
            this.isLackPage.UseVisualStyleBackColor = true;
            // 
            // isLackSeg
            // 
            this.isLackSeg.AutoSize = true;
            this.isLackSeg.Location = new System.Drawing.Point(265, 62);
            this.isLackSeg.Name = "isLackSeg";
            this.isLackSeg.Size = new System.Drawing.Size(15, 14);
            this.isLackSeg.TabIndex = 23;
            this.isLackSeg.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(676, 549);
            this.Controls.Add(this.groupBox6);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.进程信息);
            this.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Name = "Form1";
            this.Text = "Form1";
            this.进程信息.ResumeLayout(false);
            this.进程信息.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox 进程信息;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tb_PID;
        private System.Windows.Forms.TextBox seg2;
        private System.Windows.Forms.TextBox seg1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox breakInfo;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox physicalPosition;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.ListBox lb_seg;
        private System.Windows.Forms.TextBox m11;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ComboBox cb_pageSize;
        private System.Windows.Forms.Button generator;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ComboBox cb_ProcessList;
        private System.Windows.Forms.ListBox lb_page;
        private System.Windows.Forms.TextBox m12;
        private System.Windows.Forms.TextBox m13;
        private System.Windows.Forms.TextBox seg16;
        private System.Windows.Forms.TextBox seg15;
        private System.Windows.Forms.TextBox seg14;
        private System.Windows.Forms.TextBox seg13;
        private System.Windows.Forms.TextBox seg12;
        private System.Windows.Forms.TextBox seg11;
        private System.Windows.Forms.TextBox seg10;
        private System.Windows.Forms.TextBox seg9;
        private System.Windows.Forms.TextBox seg8;
        private System.Windows.Forms.TextBox seg7;
        private System.Windows.Forms.TextBox seg6;
        private System.Windows.Forms.TextBox seg5;
        private System.Windows.Forms.TextBox seg4;
        private System.Windows.Forms.TextBox seg3;
        private System.Windows.Forms.TextBox m88;
        private System.Windows.Forms.TextBox m86;
        private System.Windows.Forms.TextBox m87;
        private System.Windows.Forms.TextBox m85;
        private System.Windows.Forms.TextBox m84;
        private System.Windows.Forms.TextBox m82;
        private System.Windows.Forms.TextBox m83;
        private System.Windows.Forms.TextBox m81;
        private System.Windows.Forms.TextBox m78;
        private System.Windows.Forms.TextBox m76;
        private System.Windows.Forms.TextBox m77;
        private System.Windows.Forms.TextBox m75;
        private System.Windows.Forms.TextBox m74;
        private System.Windows.Forms.TextBox m72;
        private System.Windows.Forms.TextBox m73;
        private System.Windows.Forms.TextBox m71;
        private System.Windows.Forms.TextBox m68;
        private System.Windows.Forms.TextBox m66;
        private System.Windows.Forms.TextBox m67;
        private System.Windows.Forms.TextBox m65;
        private System.Windows.Forms.TextBox m64;
        private System.Windows.Forms.TextBox m62;
        private System.Windows.Forms.TextBox m63;
        private System.Windows.Forms.TextBox m61;
        private System.Windows.Forms.TextBox m58;
        private System.Windows.Forms.TextBox m56;
        private System.Windows.Forms.TextBox m57;
        private System.Windows.Forms.TextBox m55;
        private System.Windows.Forms.TextBox m54;
        private System.Windows.Forms.TextBox m52;
        private System.Windows.Forms.TextBox m53;
        private System.Windows.Forms.TextBox m51;
        private System.Windows.Forms.TextBox m48;
        private System.Windows.Forms.TextBox m46;
        private System.Windows.Forms.TextBox m47;
        private System.Windows.Forms.TextBox m45;
        private System.Windows.Forms.TextBox m44;
        private System.Windows.Forms.TextBox m42;
        private System.Windows.Forms.TextBox m43;
        private System.Windows.Forms.TextBox m41;
        private System.Windows.Forms.TextBox m38;
        private System.Windows.Forms.TextBox m36;
        private System.Windows.Forms.TextBox m37;
        private System.Windows.Forms.TextBox m35;
        private System.Windows.Forms.TextBox m34;
        private System.Windows.Forms.TextBox m32;
        private System.Windows.Forms.TextBox m33;
        private System.Windows.Forms.TextBox m31;
        private System.Windows.Forms.TextBox m28;
        private System.Windows.Forms.TextBox m26;
        private System.Windows.Forms.TextBox m27;
        private System.Windows.Forms.TextBox m25;
        private System.Windows.Forms.TextBox m24;
        private System.Windows.Forms.TextBox m22;
        private System.Windows.Forms.TextBox m23;
        private System.Windows.Forms.TextBox m21;
        private System.Windows.Forms.TextBox m18;
        private System.Windows.Forms.TextBox m16;
        private System.Windows.Forms.TextBox m17;
        private System.Windows.Forms.TextBox m15;
        private System.Windows.Forms.TextBox m14;
        private System.Windows.Forms.TextBox process_Info;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button releaseProcess;
        private System.Windows.Forms.Button SegPlace;
        private System.Windows.Forms.Button isReplacePage;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.CheckBox isLackPage;
        private System.Windows.Forms.CheckBox isLackSeg;
    }
}

