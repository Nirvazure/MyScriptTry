//***************************************************
//*    程 序 名：国际会议代表分配.c                 *
//*    作    者：蒋镈                               *
//*    所属班级：12届软工二班                       *
//*    学    号：2012118064                         *
//*    编制时间：2013年02月16日                     *
//*    主要功能：参会代表的组别、房间分配           *
//***************************************************

#define MAX_HEADCOUNT 200												//容许最高与会代表人数
#define INPUT_FILENAME "info.txt"
#define OUTPUT_FILENAME "output.txt"
#include"hrmthw.h"													    //作者自定义的头文件

int g_headcount = 0;														//代表总人数
int g_RelationCount = 0;													//熟人关系总对数
int g_Relation[MAX_HEADCOUNT+1][MAX_HEADCOUNT+1] = {{0,0},{0,0}};			//存储代表间熟人关系，g_Relation[0][1]与g_Relation[1][1]认识


/*本函数用于从键盘输入信息，并可检查输入格式错误与重复输入*/
int informationInput()
{
	int i = 0;										
	int tmp[2] = {0,0};										//用于ui_NumInput()结果临时存放
	int maxRelationCount=0;									//临时存放最大熟人关系对数

// 输入总人数、总对数并检验，存入g_headcount、g_RelationCount
	g_headcount = ui_NumInput(1, 1, MAX_HEADCOUNT,tmp, "请输入代表总人数：\n");
	maxRelationCount = g_headcount * (g_headcount - 1) / 2;
	printf("据总人数计算，对数应不大于%d对\n",maxRelationCount);
	g_RelationCount = ui_NumInput(1,0,maxRelationCount,tmp,"请输入代表间熟人关系总对数（同一个代表可认识多人）：\n");
	printf("请以“a,b”的格式输入相互认识代表的编号：\n");

//输入相识情况并检验错误输入及重复输入,正确则将相识情况存入g_Relation[][]，否则重新输入
	for (i = 1; i <= g_RelationCount; i++)
	{
		ui_NumInput(2, 1, g_headcount, tmp, "");           
		if(tmp[0]==tmp[1]){printf("输入代表编号不可相同！请重新输入：");i--;continue;}						
		if (g_Relation[tmp[0]][tmp[1]]==1){printf("本次输入与之前输入重复，请重新输入：\n");i--;continue;}								
		g_Relation[tmp[0]][tmp[1]] = 1;
		g_Relation[tmp[1]][tmp[0]] = 1;
		printf("已成功输入 %d,%d\n", tmp[0], tmp[1]);
	}
	printf("\n输入已完成!\n");
	return 0;
}


//本函数用于从info.txt输入信息，并能检查格式错误
int informationFromFile ()
{
	FILE *fp;
	char tmp[100]={0};
	int i=0;
	int temp=0,temp1=0;
	int errorFlag=0;
	int originRelationData[2][MAX_HEADCOUNT+1]={0};

    if((fp=fopen(INPUT_FILENAME,"r"))==NULL)									//打开 INPUT_FILENAME 文件，未找到则提示错误
    {
		printf("未找到文件 %s!\n",INPUT_FILENAME);
        return 1;
    }
	if(file_TargetRead(fp,"g_headcount=",1,"%[0-9]",tmp))errorFlag=1;		//从文件读取代表总人数
	temp=atoi(tmp);
	if(temp<0||temp>MAX_HEADCOUNT) errorFlag=3;
	else g_headcount=temp;

	if(file_TargetRead(fp,"g_RelationCount=",1,"%[0-9]",tmp))errorFlag=2;	//从文件读取代表关系总对数
	temp=atoi(tmp);
	if(temp<0||temp>MAX_HEADCOUNT*(MAX_HEADCOUNT-1)/2) errorFlag=3;
	else g_RelationCount=temp;

	for(i=1;i<=g_RelationCount && errorFlag==0;i++)						//从文件读取代表关系
	{
		if(file_TargetRead(fp,"#",i+1,"%[0-9]",tmp))errorFlag=4;
		temp=atoi(tmp);
		if(temp<1||temp>g_headcount) {errorFlag=3;break;}
		if(file_TargetRead(fp,",",i+1,"%[0-9]",tmp))errorFlag=4;
		temp1=atoi(tmp);
		if(temp1<1||temp1>g_headcount) {errorFlag=3;break;}
		if(temp==temp1) {errorFlag=4;break;}					//检验错误
		if (g_Relation[temp][temp1]==1) {errorFlag=5;break;}		//检验重复关系
		g_Relation[temp][temp1] = 1;
		g_Relation[temp1][temp] = 1;
		originRelationData[0][i]=temp;
		originRelationData[1][i]=temp1;
	}
	fclose(fp);
	switch (errorFlag)
	{
	case 0:
		printf("\n已成功从文件%s录入信息！\n\n",INPUT_FILENAME);
		printf("____ 原始数据 ____\n\n");
		printf("代表总人数：%d\n关系总对数：%d\n",g_headcount,g_RelationCount);
		printf("代表关系：\n");											//输出代表相识关系
		for(i=1;i<=g_RelationCount;i++)
			printf("%3d  -%3d\n",originRelationData[0][i],originRelationData[1][i]);
		return 0;
	case 1:
		printf("\n获取总人数错误！\n");
		break;
	case 2:
		printf("\n获取代表间熟人关系总对数错误！\n");
		break;
	case 3:
		printf("\n输入项不在有效范围内！\n");
		break;
	case 4:
		printf("\n获取代表间关系错误！\n");
		break;
	case 5:
		printf("\n代表间关系存在重复！\n");
		break;
	default:		
		break;
	}
	return 1;
}


//本函数产生测试用随机数据
int randomDataGenerator()
{
	int maxRelationCount=0;									//临时存放最大熟人关系对数
	int i=0,j=0;
	int tmp[2]={0};

	printf("请耐心等待...\n");
	g_headcount = math_Random(1,10);
	maxRelationCount = g_headcount * (g_headcount - 1) / 2;
	g_RelationCount = math_Random(0,maxRelationCount);
	for(i=1;i<=g_RelationCount;i++)
	{
		tmp[0]=math_Random(1,g_headcount);
		tmp[1]=math_Random(1,g_headcount);
		if(tmp[0]==tmp[1]){i--;continue;}						
		if (g_Relation[tmp[0]][tmp[1]]==1){i--;continue;}								
		g_Relation[tmp[0]][tmp[1]] = 1;
		g_Relation[tmp[1]][tmp[0]] = 1;
		printf("%d\n",g_RelationCount-i);
	}
	return 0;
}


//本函数往复将代表分入newGroup[][]，详见说明
int printer(int newGroup[][MAX_HEADCOUNT+1],int peopleSkip[])
{
	int i,j;
	int target=1;
	int line=0;
	int endFlag=0;				//结束标志
	while(1)
	{
		for(i=1;i<=g_headcount;i++)
			if( peopleSkip[newGroup[line][i]] == 0 )break;;		//找出尚未扫描其关系人的已分组员
		if(newGroup[line][i]!=0 && i<=g_headcount)
		{
			endFlag=0;
			target = newGroup[line][i];
		}
		else
		{ 
			if(endFlag==1)return 0;
			endFlag=1;
			line=!line;
			continue;
		}	

		for(i=1;i<=g_headcount;i++)
		{		
			if(target<0)return 2;
			if(g_Relation[target][i]==1)
			{
				for(j=1;newGroup[line][j]>0&&j<=g_headcount;j++)
					if(newGroup[line][j]==i) return 1;;
				for(j=1;newGroup[!line][j]>0&&j<=g_headcount;j++)
					if(newGroup[!line][j]==i) break;;
				if(j<=g_headcount) 
					newGroup[!line][j]=i;
			}
		}
		peopleSkip[target]=1;
	}
	return 0;
}
//本函数将代表分成组内成员互不相识的两组,成功返回0,不能分组则返回1
int grouping(int newGroup[][MAX_HEADCOUNT+1])
{
	int i,j;		//循环累加变量
	int peopleSkip[MAX_HEADCOUNT+1]={0};

	for (i = 1; i <= g_headcount; i++)
	{
		if(peopleSkip[i]==1)continue;			//判断i代表是否已分组，是则跳过
		for(j=1;newGroup[0][j]!=0;j++);
		newGroup[0][j]=i;
		if(printer(newGroup,peopleSkip))return 1;
	}
	return 0;
}


//计算任意编号代表的熟人数量
int acquaintanceNum(int peopleNum,int peopleSkip[])//要计算的代表编号
{
	int i;
	int ans=0;
	for(i=1;i<=g_headcount;i++)
	{
		if(peopleSkip[i]==1)continue;
		ans=ans+g_Relation[peopleNum][i];
	}
	return ans;
}
//使用贪心法分配尽可能多的房间，使同一房间代表相互认识，结果放入room[][]，返回值为分配房间数
int allotRoom(int room[][2])
{
	int i,j,k=0;
	int minX=1,minY=1;
	int peopleSkip[MAX_HEADCOUNT+1]={0};

	while(1)
	{
		int min=g_headcount;
		for(i=1;i<=g_headcount-1;i++)//找出最小损失
		{
			if(peopleSkip[i]==1)continue;
			for(j=i+1;j<=g_headcount;j++)
			{
				if (peopleSkip[j]==1)continue;
				if(g_Relation[i][j])
				{
					if(min>acquaintanceNum(i,peopleSkip)+acquaintanceNum(j,peopleSkip)-2)
					{
						minX=i;
						minY=j;
						min=acquaintanceNum(i,peopleSkip)+acquaintanceNum(j,peopleSkip)-2;
					}
				}
			}
		}
		if(min==g_headcount)return k;
		room[k][0]=minX;
		room[k][1]=minY;
		k++;
		peopleSkip[minX]=1;
		peopleSkip[minY]=1;
	}
	return 0;
}


int main()
{
	int i = 0,j = 0;										//循环累加变量
	int newGroup[2][MAX_HEADCOUNT+1]={{0},{0}};				//分组结果
	int room[MAX_HEADCOUNT][2]={0};							//房间分配结果
	FILE *out_fp;											//输出文件

	printf("***********************************************************\n");
	printf("*       程 序 名：国际会议代表分配.c                      *\n");
	printf("*       作    者：蒋镈 	  2012118064    12届软工2班       *\n");
	printf("*       编制时间：2013年02月16日                          *\n");
	printf("*       主要功能：主要功能：参会代表的组别、房间分配      *\n");
	printf("***********************************************************\n");
	printf("\n");
	
	switch (ui_Select(3,"选择数据输入方式：\n1.键盘输入\n2.来自文件\n3.随机生成用于测试(生成随机数据耗时巨大，慎用)\n"))
	{
	case 1:
		informationInput();					//键盘输入信息，并可检查输入格式错误与重复输入，错误则循环直至正确为止
		break;
	case 2:
		if(informationFromFile())			//文件输入信息，错误则返回1，直接结束main()
		{
			printf("\n程序将在两秒后自动退出...\n");
			_sleep(2000);
			return 1;										
		}
		break;
	case 3:
		randomDataGenerator();
		break;
	default:
		break;
	}

	if((out_fp=fopen(OUTPUT_FILENAME,"w"))==NULL)									//打开 OUTPUT_FILENAME 文件，未找到则提示错误
    {
		printf("没有文件访问权限%s!\n",OUTPUT_FILENAME);
        return 1;
    }
	fprintf(out_fp,"%s","____ 原始数据 ____\n\n");
	fprintf(out_fp,"%s%d%s%d","代表总人数：",g_headcount,"\n关系总对数：",g_RelationCount);
	fprintf(out_fp,"%s","\n代表关系：\n");											//输出代表相识关系
	for(i=1;i<=g_headcount-1;i++)
		for(j=i;j<=g_headcount;j++)
			if(g_Relation[i][j]==1)
				fprintf(out_fp,"%3d -%3d\n",i,j);;;;

	printf("\n____ 处理结果 ____\n\n");
	fprintf(out_fp,"\n____ 处理结果 ____\n\n");

	if( grouping(newGroup) )
	{
		printf("不能分成两组，组内成员互不相识的条件无法满足！\n\n");		//将代表分成互不相识的两组,可分组则放入newGroup[][]输出，否则输出错误信息
		fprintf(out_fp,"不能分成两组，组内成员互不相识的条件无法满足！\n\n");
	}
	else
	{
		printf("分组：\n第一组：");
		fprintf(out_fp,"分组：\n第一组：");
		for(i=1;i<=g_headcount&&newGroup[0][i]!=0;i++)
		{
			printf("%d ",newGroup[0][i]);
			fprintf(out_fp,"%d ",newGroup[0][i]);
		}
		printf("\n第二组：");
		fprintf(out_fp,"\n第二组：");
		for(i=1;i<=g_headcount&&newGroup[1][i]!=0;i++)
		{
			printf("%d ",newGroup[1][i]);
			fprintf(out_fp,"%d ",newGroup[1][i]);
		}
		printf("\n\n");
		fprintf(out_fp,"\n\n");
	}

	if(allotRoom(room)==0)//贪心法分配尽可能多的房间，使同一房间代表相互认识，结果放入room[][]
	{
		printf("没有代表相互认识，未分配任何房间！\n\n");
		fprintf(out_fp,"没有代表相互认识，未分配任何房间！\n\n");
	}
	else
	{
		printf("房间分配情况：\n");
		fprintf(out_fp,"房间分配情况：\n");
		for(i=0;i<g_headcount&&room[i][0]!=0;i++)
		{
			printf("%3d  -%3d\n",room[i][0],room[i][1]);
			fprintf(out_fp,"%3d  -%3d\n",room[i][0],room[i][1]);
		}
		printf("共分配%d个房间满足同一房间代表相互认识。\n\n",i);
		fprintf(out_fp,"共分配%d个房间满足同一房间代表相互认识。\n\n",i);
	}
	fclose(out_fp);

	system("pause");
	return 0;
}