/*
*	�� �� ����Сѧ���������㿼��ģ��ϵͳ
*	�����ܣ������20��100��������������Ŀ��������ɺ󽫴����˵������͵÷�д���ļ��
*	 ��  �� ��hrmthw
*	 ��  �� ��2013-06-30
*	 ˵  �� ������������bug���������ȶ���
*	
*							    -> test() -> question()��20 ->
*	��������ͼ��start -> top()  -> scan()					-> top() -> ��
*							 	-> clear()					->	   
*	
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>

#define FILE_NAME "mem.log"		//��ųɼ���Ϣ���ļ��������޸�

#define getch _getch			//�滻Ϊ��ISO C++ ��׼�⺯���������뱨��Ͱ��⼸���궨��ע�͵�����
#define _sleep Sleep			

FILE* fp;

char choose(int itemNum)            //��ͣ�ȴ��û�����ѡ��,itemNumΪѡ���������������µļ�
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

float input_in_one_minute()			//���Ĵ��룬���ֹ�����˫�̡߳�����ʱ1��������(�����˴������鷳��)������floatֵ��
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
			printf("��ʱ��\n");
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
	return -2;			//������ִ�е�
}

int question()						//����������⡢����𰸣������������
{
	int a=0,b=0;
	int op=0;
	int ans=0;
	int user_ans=-1;
	int flag=0;

	op=abs(rand())%4;
	a=abs(rand())%101;
	b=abs(rand())%101;					//���������

	if (op==3)
		printf("��ʡ����λС����\n");		//��������˵��
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
			b=abs(rand())%(a+1);		//�����������ڱ���������
		ans=100 * ( a - b );
		break;
	case 2:
		printf(" * ");
		ans=100*a*b;
		break;
	case 3:
		printf(" / ");
		if (b==0)
			b=abs(rand())%100+1;		//��������Ϊ������
		ans=1000*a/b;
		ans=ans/10+((ans%10 > 4)?1:0);	//�������벢�������ʵֵ��һ�ٱ���ת��Ϊint���ڱȽ�
		break;
	default:
		break;
	}
	printf("%d = ",b);

	user_ans=(int)(1000 * input_in_one_minute());
	user_ans=user_ans/10+((user_ans%10 > 4)?1:0);		//�������벢�������ʵ����ֵ��һ�ٱ���ת��Ϊint���ڱȽ�

	flag=(user_ans==ans);
	if (flag==0)
	{
		printf("����\n");
	}else
	{
		printf("��ȷ��\n");
	}
	return flag;
}

void test()							//���Խ���
{
	int i;
	char name[21]={0};
	char ans[101]={0};
	int grade=0;

	system("cls");
	printf("****************************************************************************\n");
	printf("**                    Сѧ���������㿼��ģ��ϵͳ                          **\n");
	printf("**                       *   ����׼������   *                             **\n");
	printf("**     * ������Ϊ��ʱ���ԣ�����20������������Ŀ��ÿ������ʱһ���ӣ�       **\n");
	printf("**   ȫ20������ʱ20���ӡ�                                                 **\n");
	printf("**                                                                        **\n");
	printf("****************************************************************************\n");
	printf("������������                                                                \n");
	fflush(stdin);
	scanf("%10s",name);

	for (i = 5; i > 0; i--)
	{
		system("cls");
		printf("������׼����\n���Խ���%d���ʼ...\n",i);
		_sleep(1000);		
	}
	system("cls");

	printf("----------------------------------���Կ�ʼ----------------------------------\n\n");
	printf("                    ������%s                         \n",name);

	for (i = 0; i < 20; i++)
	{
		printf("\n-----��%2d��-----\n",i+1);
		grade =question()*5 + grade;
	}

	fp=fopen(FILE_NAME,"r+");
	fseek(fp,0,SEEK_END);
	fprintf(fp,"%-10s\t%3d\n",name,grade);
	fclose(fp);



	printf("\n\n");
	printf("----------------------------------���Խ���----------------------------------\n\n");
	printf("                                 ������%s                                   \n",name);
	printf("                                 �ɼ���%3d                                  \n\n",grade);
	printf("--------------------------------�����������--------------------------------\n");

	_sleep(50);
	getch();
	return;
}

void scan()						//����ɼ�����
{
	char tmp[101]={0};
	
	system("cls");
	printf("----------------------------------�ɼ����----------------------------------\n\n");

	fp=fopen(FILE_NAME,"r+");

	while (1)
	{
		fgets (tmp,100, fp);
		if(feof(fp))break;
		printf("%s",tmp);

	}


	fclose(fp);
	printf("\n");
	printf("--------------------------------�����������--------------------------------\n");

	_sleep(50);
	getch();

}

void clear()						//�����ʷ��¼����
{
	int i;
	fp=fopen(FILE_NAME,"w+");
	fprintf(fp,"%-10s\t%4s\n","����","�ɼ�");
	fclose(fp);
	system("cls");
	printf("--------------------------------�����¼��...-------------------------------\n\n");
	for (i = 0; i < 50; i++)
	{
		printf("*");
		_sleep(20);
	}								//���ûʲôʵ�����壬ֻ��Ϊ�˿�����������~
	printf("\n�����ɣ�\n\n");
	printf("--------------------------------�����������--------------------------------\n");
	_sleep(50);
	getch();
}

void top()					//������
{
	while (1)
	{

		system("cls");
		printf("****************************************************************************\n");
		printf("**              ��ӭ����Сѧ���������㿼��ģ��ϵͳ��                      **\n");
		printf("**     ��ѡ��                                                           **\n");
		printf("**                                                                        **\n");
		printf("**        [1] ��ʼ����                                                    **\n");
		printf("**        [2] �鿴�ɼ�                                                    **\n");
		printf("**        [3] �����¼                                                    **\n");
		printf("**        [4] �˳�����                                                    **\n");
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
	system("color f0");					//���ñ�����ɫ

	if((fp=fopen(FILE_NAME,"r+"))==NULL)//���ļ���û���򴴽�����ʼ��
	{
		fp=fopen(FILE_NAME,"w+");
		fprintf(fp,"%-10s\t%4s\n","����","�ɼ�");
	}
	fclose(fp);

	srand((unsigned int)time(NULL));	//�����������Ϊ��ǰϵͳʱ��

	top();
	return 0;
}