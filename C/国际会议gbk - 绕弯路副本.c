//***********************************************************
//*		程 序 名：国际会议.c								*
//*		作    者：蒋镈 										*
//*		所属班级：12届软工二班								*
//*		学    号：2012118064								*
//*		编制时间：2013年02月16日							*
//*		主要功能：											*
//***********************************************************
#include<hrmthw.h>    //作者自定义的头文件
//#include<malloc.h>
#define MaxHeadcount 200											//容许最高与会代表人数
#define MaxRelationCount (MaxHeadcount*(MaxHeadcount-1)/2)			//容许最高熟人关系对数

int headcount = 0;													//代表总人数
int relationConunt = 0;												//熟人关系总对数
int relation[2][MaxRelationCount] = { {-1, 0, 0}, {-1, 0, 0} };		//存储代表间熟人关系，relation[0][1]与relation[1][1]认识

/*本函数用于综合信息输入，并可检查输入格式错误与重复输入*/
int informationInput()
{
	int i = 0, j = 0,k = 0;									//循环累加变量
	int tmp[2] = {0,0};										//用于intinput()结果临时存放
	int maxRelationCount=0;								//临时存放最大熟人关系对数

// 输入总人数、总对数并检验，存入headcount、relationConunt
	headcount = intinput(1, 1, MaxHeadcount,tmp, "请输入代表总人数：");
	maxRelationCount = headcount * (headcount - 1) / 2;
	printf("据总人数计算，对数应不大于%d对\n",maxRelationCount);
	relationConunt = intinput(1,0,maxRelationCount,tmp,"请输入代表间熟人关系总对数（同一个代表可认识多人）：");
	printf("请以“a,b”的格式输入相互认识代表的编号：\n");

/*输入相识情况并检验错误输入及重复输入,正确则将相识情况存入relation[][]，否则重新输入*/
	for (i = 1; i <= relationConunt; i++)
	{
		intinput(2, 1, headcount, tmp, " ");/*intinput是在hrmthw.h中作者自定义的函数，用于安全地输入一组int类型的数据。
											此函数具有判断输入格式错误、自定义输入范围、错误时提供提示并重输的功能。参
											数从左至右分别是每次输入数据个数、最小值、最大值（均包含本身）、存放输入结
											果的数组、输入提示语*/               
		if(tmp[0]==tmp[1]){printf("输入代表编号不可相同！请重新输入：");i--;continue;}//检验错误输入
		for (j = 0, k = 0; k < 2; j++)
		{
			if (tmp[0] == relation[k][j] && tmp[1] == relation[!k][j])//检验重复输入
			{
				printf("本次输入与第%d次重复，请重新输入：\n",j);
				i--;
				break;
			}													
			if (j >= i-1){j = 0;k++;}
		}
		if (k == 2)
		{
			relation[0][i] = tmp[0];
			relation[1][i] = tmp[1];
			printf("已成功输入 %d,%d", relation[0][i], relation[1][i]);
		}
	}
	printf("\n输入已完成!\n");
	return 0;
}

/*本函数利用递归方式检查能否将代表分成互不相识的两组，能则返回0，否则返回1并标记导致不能的一组关系*/
int compare(int ringHead, int ringNow,int stackNum)						//ringHead为环的起始节点，ringNow为当前节点，stackNum为当前栈层数
{
	int i,j,k;		//循环累加变量
	int flag=0;		//临时标记变量
	static int relationSkip[MaxRelationCount+1];						//存储compare()中本行关系是否已作为节点，是则置1，下一层compare()将跳过此行。
	static int newGroup[2][MaxHeadcount+1];								//分组结果
	if(stackNum==0) 
	{
		if(ringHead==1)
		{
			for(i=0;i <= MaxHeadcount;i++) 
			{
				newGroup[0][i]=0;
				newGroup[1][i]=0;
			}
		}
		for(i=0;i <= MaxRelationCount;i++) 
			relationSkip[i]=0;
	}
	stackNum++;
	for (i = 1, j = 0; j < 2; i++)
	{
		if (relationSkip[i] == 1)continue;
		if (i > relationConunt)
		{
			i = 0;
			j++;
			continue;
		}
		if (relation[j][i] != ringNow)continue;
//		if (relation[j][i] <= ringHead)continue;
	/*      */
		flag=(stackNum+ringHead)%2;			//判断奇偶
		for(k=1;k<=headcount;k++)
		{
			if(newGroup[flag][k]==relation[j][i])break;
			else if(newGroup[flag][k]==0){newGroup[flag][k]=relation[j][i];break;};
		}
		for(k=1;k<=headcount;k++)
		{
			if(newGroup[!flag][k]==relation[!j][i])break;
			else if(newGroup[!flag][k]==0){newGroup[!flag][k]=relation[!j][i];break;};
		}

		if (relation[!j][i] == ringHead)
		{
			if (stackNum % 2 == 1){relationSkip[i] = 1;return 1;}
			else continue;
		}
		else 
		{
			relationSkip[i] = 1;
			if(compare(ringHead, relation[!j][i],stackNum)==1)
			{
				if (stackNum==1)
				{
					printf("不能分成组内成员互不相识的两组！\n造成原因：\n");
					for(i=1;i<=headcount;i++) 
						if(relationSkip[i]==1) 
							printf("%d-%d ",relation[0][i],relation[1][i]);;
				}
				return 1;
			}
			relationSkip[i] = 0;
		}
	}
	stackNum--;
	if(stackNum==0&&ringHead==headcount)
		for(i=1;i<=headcount;i++)
			printf("%d-%d\n",newGroup[0][i],newGroup[1][i]);;
	return 0;
}

/*本程序将代表分成组内成员互不相识的两组*/
int grouping()
{

	return 0;
}

int main()
{
	int i = 0, j = 0,k = 0;									//循环累加变量
	int errorLevel=0;										//错误标记
//	int newGroup[2][MaxHeadcount+1]={{-1,0,0},{-1,0,0}};	//分组结果
	int acquaintanceNum[MaxHeadcount+1] = { 0 };			// 存储每个代表认识其他代表个数
//	int sum = 0;

	informationInput();										//本函数用于综合信息输入，并可检查输入格式错误与重复输入

/*递归调用compare()检查能否将代表分成互不相识的两组,可分组则调用grouping()进行分组，否则输出错误信息*/
	for (i = 1; i <= headcount; i++)
		if(compare(i, i, 0)==1)break;;

/* 找出每个代表认识其他代表个数，存入acquaintanceNum[]*/
	for (i = 1, k = 0; k < 2; i++)
	{
		for (j = 1;j<= headcount;j++)
			if (relation[k][i] == j)acquaintanceNum[j]++;;
		if (i >= MaxHeadcount){i=0;k++;}
	}						

/*	for (i = 1; i <= MaxHeadcount; i++)
		if(x[i] != 0)sum++;;
	// 计算出有熟人的代表总数，放入sum，剩下代表不认识任何人*/
	system("pause");
	return 0;
}