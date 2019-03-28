#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
/*
本程序意图基于贪吃蛇的世界模型，
探究最基本的机器学习。
		由二维数组构成的方盒是简单的“世界”，内有障碍物，蛇在盒内行进。绝对方向上、右、下、左分别由1,2,3,4表示。
		模拟的蛇有固定的神经网络形状（但神经之间的连接模式有3种，即无连接、正向刺激、反向刺激，表现为网络内每个神经元的输出o与输入i1,i2的关系为o=i1+i2,o=i1-i2,o=i1,o=-i1+i2等8种。），有对前、左、右三个方向（不同于绝对方向，这里是由蛇的视角看的相对方向）两格内障碍物的感知（由l,f,r和函数vision实现），并输入神经网络，根据输出返回决定的转向。（详见图解）
		每个神经元的类型由随机函数生成并存入文件mem.dat，当蛇死亡（即撞上障碍物）则重新生成一组随机值写入文件并重新开始。当生成的一组值令蛇的活动规律总能避免撞上障碍物时，文件就存下了“正确”的一组神经状态。实现了简单的自学习。
*/
char w[17][17]={
			{42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42},
			{42,32,32,32,32,32,32,32,32,32,32,32,42,32,32,32,42},
			{42,32,32,32,32,32,32,32,32,32,32,32,42,32,32,32,42},
			{42,32,32,32,32,32,32,42,32,32,32,32,42,32,32,32,42},
			{42,32,32,32,32,32,32,42,42,32,32,32,32,32,32,32,42},
			{42,32,32,32,32,32,32,42,32,32,32,32,32,32,32,32,42},
			{42,32,32,32,32,32,32,42,32,32,32,32,32,32,32,32,42},
			{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
			{42,32,32,32,32,32,32,32,32,32,32,42,42,42,32,32,42},
			{42,32,32,42,32,32,32,32,32,32,32,32,32,42,42,42,42},
			{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
			{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
			{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
			{42,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,42},
			{42,32,32,32,32,32,32,32,42,32,32,32,32,32,32,32,42},
			{42,32,32,32,32,32,32,32,42,32,32,32,32,32,32,32,42},
			{42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42}
			};//世界数组,外围为框架，内部可随意放置障碍物，但不能放在正中心（蛇出现的位置）
int headx,heady;//蛇头坐标
FILE *fp;//用于建立神经状态存储文件
int memt[100];//用于暂存mem.dat的神经状态数据，避免过多读写
int dir;//蛇头方向
int bodylength=25;//蛇身长度(<100)
char *body[100];//为蛇身建立指针数组
int initialize(int x)//x=1则进行死亡后世界重置，否则仅初始化世界
{
	char xx=32;/*此变量仅用于重置蛇身指针，因为手机编程软件不支持将指针指向NULL*/
	int i;
	int ran;
	headx=8;heady=8;
	dir=1;
	srand((unsigned int)time(NULL));
	if((fp=fopen("mem.dat","r+"))==NULL)//打开mem.dat文件，没有则创建并随机赋值
	{
		fp=fopen("mem.dat","w+");
		for(i=0;i<=56;i++)
		{
			ran=abs(rand())%7;
			fprintf(fp,"%d ",ran);
		}
	}
	if(x==1)//x=1进行死亡重置，重置蛇身为空格并将一组新随机值写入mem.dat文件
	{
		for(i=0;i<=bodylength;i++)*body[i]=32;
		rewind(fp);
		for(i=0;i<=56;i++)
		{
			ran=abs(rand())%7;
			fprintf(fp,"%d ",ran);
		}
	}
	for(i=0;i<=56;i++)//将mem.dat文件录入memt[]
	{
		fseek(fp,2*i,0);
		fscanf(fp,"%d",&memt[i]);
	}
	fclose(fp);//关闭文件
	for(i=bodylength;i>=0;i=i-1) body[i]=&xx;//重置蛇身指针
	return 0;
}
int wait(int t0)//延时函数
{
	int t1,t2;
	for(t1=1;t1<=t0;t1++)
	for(t2=1;t2<=32767;t2++);;
    return 0;
}
int forward(int ddir)//用于执行蛇前进时的系列操作
{
	int i,ndir;
	*body[bodylength]=32;//尾巴重置为空格
	for (i=bodylength;i>=1;i--)
		body[i]=body[i-1];//身体跟进
	body[0]=&w[headx][heady];//身体最前段指向蛇头当前位置
	ndir=dir+ddir;
	if(ndir==0) ndir=4;
	if(ndir==5) ndir=1;//此三行用于将蛇决定的相对方向ddir转化为绝对方向ndir（即new direction）
	if(ndir==1) heady--;
	if(ndir==2) headx++;
	if(ndir==3) heady++;
	if(ndir==4) headx--;//蛇头前进
	if(w[headx][heady]==42) return 1;//前进位置上有障碍则死亡，返回1
	dir=ndir;
	w[headx][heady]=42;//未死亡则将蛇头位置赋为*
	return 0;
}
int vision(int x)//此函数用于模拟视觉
{
	int xndir;
	xndir=dir+x;//相对方向转换为绝对方向
	if(xndir==0) xndir=4;
	if(xndir==5) xndir=1;
	if (xndir==4)
	{
		if(w[headx-1][heady]==42)return 1;
		if(w[headx-2][heady]==42)return 2;
		else return 0;
	}
	if (xndir==3)
	{
		if(w[headx][heady+1]==42)return 1;
		if(w[headx][heady+2]==42)return 2;
		else return 0;
	}
	if (xndir==2)
	{
		if(w[headx+1][heady]==42)return 1;
		if(w[headx+2][heady]==42)return 2;
		else return 0;
	}
	if (xndir==1)
	{
		if(w[headx][heady-1]==42)return 1;
		if(w[headx][heady-2]==42)return 2;
		else return 0;
	}//按绝对方向判断蛇头2格内是否有障碍物
	return 0;
}
int neuron(int i1,int i2,int f)//模拟神经元，f决定每个神经元类型，详见图解
{
	switch(f)
	{
		case 0:return 0;
		case 1:return (i1+i2);
		case 2:return (i1);
		case 3:return (i2);
		case 4:return (-i1-i2);
		case 5:return (-i1);
		case 6:return (-i2);
	}
	return 0;
}
int snake(int l,int f,int r)
{
	int i,j,n=0;
	int k;
	int temp[2][100]={{0},{0}};		
	{
		if(l==0)temp[1][0]=1;
		if(f==1)temp[1][1]=2;
		if(r==1)temp[1][2]=1;
		if(f==2)temp[1][3]=1;
		if(r==2)temp[1][4]=1;
		if(f==0)temp[1][5]=3;
		if(l==2)temp[1][6]=1;
		if(f==2)temp[1][7]=1;
		if(l==1)temp[1][8]=1;
		if(f==1)temp[1][9]=2;
		if(r==0)temp[1][10]=1;
	//	temp[1][11]=rand()%2;
	//	temp[1][12]=0;
	}//将传感器反馈输入神经网络，详见图解
	for(j=10;j>=5;j--)
	{
		k=j%2;
		for(i=0;i<j;i++)
		{
			temp[k][i]=neuron(temp[!k][i],temp[!k][i+1],memt[n]);
			n++;
		}//temp[0][]和temp[1][]交替接受每一级神经的输出结果
	}//神经网络系列运算，最终可用输出为temp[1][0]~temp[1][4]
	if(temp[1][2]>=temp[1][1])
	{
		if(temp[1][2]>=temp[1][3])return 0;
		else return 1;
	}
	else
	{
		if(temp[1][1]>temp[1][3])return -1;
		else return 1;
	}/*暂使用temp[1][1],temp[1][2],temp[1][3]这三
	 个输出,比较出最大值并以此做决定。
	如temp[1][1]最大时返回-1，最终使蛇向左转头*/
}
int main()
{
	long time=0;//时间变量
	int l,r,f;//定义左、前、右传感器变量
	int x,y,ddir;
	initialize(0);
	while(time<=1000000)
	{
		l=vision(-1);
		f=vision(0);
		r=vision(1);/*获得左、前、右障碍物情况，一格内有障碍为1，两格为2，两格范围内没有为0*/
		ddir=snake(l,f,r);/*由snack函数根据l、f、r值判断并决定前进方向，-1向左，0不变，1向右*/
		if (forward(ddir)==1)//检验死亡
		{
			system ("cls");
			printf("-----die!-----\n\n\n\n\n\n\n");
			wait(30);
			initialize(1);
		}
		system ("cls");
		printf("--         Smart Snake         --\n\n          \n\n\n            Time:%d\n\n",time);
		for (y=0;y<=16;y++)
		{
			for(x=0;x<=16;x++) printf("%c " ,w[x][y]);
			printf("\n");
		}//这一系列语句用于绘制世界
		wait(10);//控制括号中的值可改变速度
		time ++;
	}
	return 0;
}