#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
/*
��������ͼ����̰���ߵ�����ģ�ͣ�
̽��������Ļ���ѧϰ��
		�ɶ�ά���鹹�ɵķ����Ǽ򵥵ġ����硱�������ϰ�����ں����н������Է����ϡ��ҡ��¡���ֱ���1,2,3,4��ʾ��
		ģ������й̶�����������״������֮�������ģʽ��3�֣��������ӡ�����̼�������̼�������Ϊ������ÿ����Ԫ�����o������i1,i2�Ĺ�ϵΪo=i1+i2,o=i1-i2,o=i1,o=-i1+i2��8�֡������ж�ǰ�������������򣨲�ͬ�ھ��Է������������ߵ��ӽǿ�����Է����������ϰ���ĸ�֪����l,f,r�ͺ���visionʵ�֣��������������磬����������ؾ�����ת�򡣣����ͼ�⣩
		ÿ����Ԫ������������������ɲ������ļ�mem.dat��������������ײ���ϰ������������һ�����ֵд���ļ������¿�ʼ�������ɵ�һ��ֵ���ߵĻ�������ܱ���ײ���ϰ���ʱ���ļ��ʹ����ˡ���ȷ����һ����״̬��ʵ���˼򵥵���ѧϰ��
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
			};//��������,��ΧΪ��ܣ��ڲ�����������ϰ�������ܷ��������ģ��߳��ֵ�λ�ã�
int headx,heady;//��ͷ����
FILE *fp;//���ڽ�����״̬�洢�ļ�
int memt[100];//�����ݴ�mem.dat����״̬���ݣ���������д
int dir;//��ͷ����
int bodylength=25;//������(<100)
char *body[100];//Ϊ������ָ������
int initialize(int x)//x=1������������������ã��������ʼ������
{
	char xx=32;/*�˱�����������������ָ�룬��Ϊ�ֻ���������֧�ֽ�ָ��ָ��NULL*/
	int i;
	int ran;
	headx=8;heady=8;
	dir=1;
	srand((unsigned int)time(NULL));
	if((fp=fopen("mem.dat","r+"))==NULL)//��mem.dat�ļ���û���򴴽��������ֵ
	{
		fp=fopen("mem.dat","w+");
		for(i=0;i<=56;i++)
		{
			ran=abs(rand())%7;
			fprintf(fp,"%d ",ran);
		}
	}
	if(x==1)//x=1�����������ã���������Ϊ�ո񲢽�һ�������ֵд��mem.dat�ļ�
	{
		for(i=0;i<=bodylength;i++)*body[i]=32;
		rewind(fp);
		for(i=0;i<=56;i++)
		{
			ran=abs(rand())%7;
			fprintf(fp,"%d ",ran);
		}
	}
	for(i=0;i<=56;i++)//��mem.dat�ļ�¼��memt[]
	{
		fseek(fp,2*i,0);
		fscanf(fp,"%d",&memt[i]);
	}
	fclose(fp);//�ر��ļ�
	for(i=bodylength;i>=0;i=i-1) body[i]=&xx;//��������ָ��
	return 0;
}
int wait(int t0)//��ʱ����
{
	int t1,t2;
	for(t1=1;t1<=t0;t1++)
	for(t2=1;t2<=32767;t2++);;
    return 0;
}
int forward(int ddir)//����ִ����ǰ��ʱ��ϵ�в���
{
	int i,ndir;
	*body[bodylength]=32;//β������Ϊ�ո�
	for (i=bodylength;i>=1;i--)
		body[i]=body[i-1];//�������
	body[0]=&w[headx][heady];//������ǰ��ָ����ͷ��ǰλ��
	ndir=dir+ddir;
	if(ndir==0) ndir=4;
	if(ndir==5) ndir=1;//���������ڽ��߾�������Է���ddirת��Ϊ���Է���ndir����new direction��
	if(ndir==1) heady--;
	if(ndir==2) headx++;
	if(ndir==3) heady++;
	if(ndir==4) headx--;//��ͷǰ��
	if(w[headx][heady]==42) return 1;//ǰ��λ�������ϰ�������������1
	dir=ndir;
	w[headx][heady]=42;//δ��������ͷλ�ø�Ϊ*
	return 0;
}
int vision(int x)//�˺�������ģ���Ӿ�
{
	int xndir;
	xndir=dir+x;//��Է���ת��Ϊ���Է���
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
	}//�����Է����ж���ͷ2�����Ƿ����ϰ���
	return 0;
}
int neuron(int i1,int i2,int f)//ģ����Ԫ��f����ÿ����Ԫ���ͣ����ͼ��
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
	}//���������������������磬���ͼ��
	for(j=10;j>=5;j--)
	{
		k=j%2;
		for(i=0;i<j;i++)
		{
			temp[k][i]=neuron(temp[!k][i],temp[!k][i+1],memt[n]);
			n++;
		}//temp[0][]��temp[1][]�������ÿһ���񾭵�������
	}//������ϵ�����㣬���տ������Ϊtemp[1][0]~temp[1][4]
	if(temp[1][2]>=temp[1][1])
	{
		if(temp[1][2]>=temp[1][3])return 0;
		else return 1;
	}
	else
	{
		if(temp[1][1]>temp[1][3])return -1;
		else return 1;
	}/*��ʹ��temp[1][1],temp[1][2],temp[1][3]����
	 �����,�Ƚϳ����ֵ���Դ���������
	��temp[1][1]���ʱ����-1������ʹ������תͷ*/
}
int main()
{
	long time=0;//ʱ�����
	int l,r,f;//������ǰ���Ҵ���������
	int x,y,ddir;
	initialize(0);
	while(time<=1000000)
	{
		l=vision(-1);
		f=vision(0);
		r=vision(1);/*�����ǰ�����ϰ��������һ�������ϰ�Ϊ1������Ϊ2������Χ��û��Ϊ0*/
		ddir=snake(l,f,r);/*��snack��������l��f��rֵ�жϲ�����ǰ������-1����0���䣬1����*/
		if (forward(ddir)==1)//��������
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
		}//��һϵ��������ڻ�������
		wait(10);//���������е�ֵ�ɸı��ٶ�
		time ++;
	}
	return 0;
}