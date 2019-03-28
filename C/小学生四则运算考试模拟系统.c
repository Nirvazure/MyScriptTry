/*
*	程 序 名：小学生四则运算考试模拟系统
*	程序功能：随机出20道100以内四则运算题目，答题完成后将答题人的姓名和得分写到文件里。
*	 作  者 ：hrmthw
*	 日  期 ：2013-06-30
*	 说  明 ：修正了两个bug，提升了稳定性
*	
*							    -> test() -> question()×20 ->
*	简易流程图：start -> top()  -> scan()					-> top() -> …
*							 	-> clear()					->	   
*	
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>

#define FILE_NAME "mem.log"		//存放成绩信息的文件名，可修改

#define getch _getch			//替换为新ISO C++ 标准库函数名，编译报错就把这几个宏定义注释掉试试
#define _sleep Sleep			

FILE* fp;

char choose(int itemNum)            //暂停等待用户按键选择,itemNum为选项数，返回所按下的键
{
	char ans=0;
	while (ans<'1'||ans>'1'+itemNum-1)
	{
		ans=getch();
		_sleep(30);
	}
	_sleep(300);
	return ans;
}

float input_in_one_minute()			//核心代码，纯手工土制双线程……限时1分钟输入(出题人纯属找麻烦啊)，返回float值。
{
	char ans[21]={0};
	int flag=0;
	char last=0;
	char now=0;
	SYSTEMTIME timeBegin;
	SYSTEMTIME timeNow;
	GetLocalTime(&timeBegin);

	while (1)
	{
		if (_kbhit())
		{
			now=getch();
		}else{
			last=0;
			now=0;
		}

		GetLocalTime(&timeNow);
		if (timeNow.wMinute > timeBegin.wMinute && timeNow.wSecond>=timeBegin.wSecond)
		{
			printf("超时！\n");
			return -1;
		}

		if (now==0||now==last)continue;

		switch (now)
		{
		case 13:			
			printf("\n");
			return (float)atof(ans);
			break;
		case 8:
			last=now;
			if (flag!=0)
			{
				printf("%c %c",now,8);
				flag--;
			}
			break;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
		case '.':
			last=now;
			if (flag==20)continue;
			printf("%c",now);
			ans[flag]=now;
			flag++;
			break;
		default:
			break;
		}
	}
	return -2;			//不可能执行到
}

int question()						//产生随机问题、检验答案，返回正误情况
{
	int a=0,b=0;
	int op=0;
	int ans=0;
	int user_ans=-1;
	int flag=0;

	op=abs(rand())%4;
	a=abs(rand())%101;
	b=abs(rand())%101;					//产生随机数

	if (op==3)
		printf("（省略两位小数）\n");		//除法补充说明
	printf("%3d",a);
	switch (op)
	{
	case 0:
		printf(" + ");
		ans=100*(a+b);
		break;
	case 1:
		printf(" - ");
		if (b>a)
			b=abs(rand())%(a+1);		//修正减数大于被减数情形
		ans=100 * ( a - b );
		break;
	case 2:
		printf(" * ");
		ans=100*a*b;
		break;
	case 3:
		printf(" / ");
		if (b==0)
			b=abs(rand())%100+1;		//修正除数为零情形
		ans=1000*a/b;
		ans=ans/10+((ans%10 > 4)?1:0);	//四舍五入并处理成真实值的一百倍，转化为int便于比较
		break;
	default:
		break;
	}
	printf("%d = ",b);

	user_ans=(int)(1000 * input_in_one_minute());
	user_ans=user_ans/10+((user_ans%10 > 4)?1:0);		//四舍五入并处理成真实输入值的一百倍，转化为int便于比较

	flag=(user_ans==ans);
	if (flag==0)
	{
		printf("错误！\n");
	}else
	{
		printf("正确！\n");
	}
	return flag;
}

void test()							//测试界面
{
	int i;
	char name[21]={0};
	char ans[101]={0};
	int grade=0;

	system("cls");
	printf("****************************************************************************\n");
	printf("**                    小学生四则运算考试模拟系统                          **\n");
	printf("**                       *   测试准备界面   *                             **\n");
	printf("**     * 本测试为计时测试，包含20道四则运算题目，每道题限时一分钟，       **\n");
	printf("**   全20道题限时20分钟。                                                 **\n");
	printf("**                                                                        **\n");
	printf("****************************************************************************\n");
	printf("请输入姓名：                                                                \n");
	fflush(stdin);
	scanf("%10s",name);

	for (i = 5; i > 0; i--)
	{
		system("cls");
		printf("请做好准备，\n考试将在%d秒后开始...\n",i);
		_sleep(1000);		
	}
	system("cls");

	printf("----------------------------------考试开始----------------------------------\n\n");
	printf("                    姓名：%s                         \n",name);

	for (i = 0; i < 20; i++)
	{
		printf("\n-----第%2d题-----\n",i+1);
		grade =question()*5 + grade;
	}

	fp=fopen(FILE_NAME,"r+");
	fseek(fp,0,SEEK_END);
	fprintf(fp,"%-10s\t%3d\n",name,grade);
	fclose(fp);



	printf("\n\n");
	printf("----------------------------------考试结束----------------------------------\n\n");
	printf("                                 姓名：%s                                   \n",name);
	printf("                                 成绩：%3d                                  \n\n",grade);
	printf("--------------------------------按任意键返回--------------------------------\n");

	_sleep(50);
	getch();
	return;
}

void scan()						//浏览成绩界面
{
	char tmp[101]={0};
	
	system("cls");
	printf("----------------------------------成绩浏览----------------------------------\n\n");

	fp=fopen(FILE_NAME,"r+");

	while (1)
	{
		fgets (tmp,100, fp);
		if(feof(fp))break;
		printf("%s",tmp);

	}


	fclose(fp);
	printf("\n");
	printf("--------------------------------按任意键返回--------------------------------\n");

	_sleep(50);
	getch();

}

void clear()						//清除历史记录界面
{
	int i;
	fp=fopen(FILE_NAME,"w+");
	fprintf(fp,"%-10s\t%4s\n","姓名","成绩");
	fclose(fp);
	system("cls");
	printf("--------------------------------清除记录中...-------------------------------\n\n");
	for (i = 0; i < 50; i++)
	{
		printf("*");
		_sleep(20);
	}								//这段没什么实际意义，只是为了看起来很厉害~
	printf("\n清除完成！\n\n");
	printf("--------------------------------按任意键返回--------------------------------\n");
	_sleep(50);
	getch();
}

void top()					//主界面
{
	while (1)
	{

		system("cls");
		printf("****************************************************************************\n");
		printf("**              欢迎进入小学生四则运算考试模拟系统！                      **\n");
		printf("**     请选择：                                                           **\n");
		printf("**                                                                        **\n");
		printf("**        [1] 开始测试                                                    **\n");
		printf("**        [2] 查看成绩                                                    **\n");
		printf("**        [3] 清除记录                                                    **\n");
		printf("**        [4] 退出程序                                                    **\n");
		printf("**                                                                        **\n");
		printf("****************************************************************************\n");
		switch (choose(4))
		{
		case '1':
			test();
			break;
		case '2':
			scan();
			break;
		case '3':
			clear();
			break;
		case '4':
			exit(0);
			break;
		default:
			break;
		}
	}
}

int main(){
	system("color f0");					//设置背景白色

	if((fp=fopen(FILE_NAME,"r+"))==NULL)//打开文件，没有则创建并初始化
	{
		fp=fopen(FILE_NAME,"w+");
		fprintf(fp,"%-10s\t%4s\n","姓名","成绩");
	}
	fclose(fp);

	srand((unsigned int)time(NULL));	//设置随机种子为当前系统时间

	top();
	return 0;
}