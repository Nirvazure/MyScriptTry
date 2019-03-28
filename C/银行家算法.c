#include<stdio.h>
#include<stdlib.h>

int n,m;			//用m，n分别记录进程数和资源的种类数
int *resource ;	//声明资源数组
int *available ;//声明剩余资源数组
int **claim ; //声明进程对资源的需求矩阵
int **alloction; //声明当前进程已得到的资源矩阵
int *temp ;	//声明一个缓冲矩阵，用于临时数据处理

void init()
{
	int i = 0,j = 0,t = 0;
	printf("请输入进程数和资源种类数：");
	scanf("%d%d",&n,&m);
	resource = (int *)malloc(sizeof(int)*m);	//为资源数组动态分配空间
	available = (int *)malloc(sizeof(int)*m);//为剩余资源数组动态分配空间
	claim = (int **)malloc(sizeof(*claim)*n);//为进程对资源的需求矩阵动态分配空间
	for(i = 0;i < n;i++)
		claim[i] = (int *)malloc(sizeof(int)*m);
	alloction = (int **)malloc(sizeof(*alloction)*n);//为当前进程已得到的资源矩阵动态分配空间
	for(i = 0;i < n;i++)
		alloction[i] = (int *)malloc(sizeof(int)*m);
	temp = (int *)malloc(sizeof(int)*m);	//为临时矩阵分配空间
	printf("\n请依次输入各类资源总数：");
	for(i = 0;i < m; i++)
		scanf("%d",&resource[i]);
	printf("\n请依次输入各个进程需要的资源数：\n");
	for(i = 0;i < n; i++)
		{
			printf("\n请输入p%d需要的资源数:\t",i+1);
			for(j = 0;j < m; j++)
				scanf("%d",&claim[i][j]);
			//printf("\n");
		}
	printf("\n请为各个进程分配资源\n");
	for(i = 0;i < n; i++)
	{
		printf("\n请为p%d分配资源：",i+1);
		for(j = 0;j < m; j++)
			scanf("%d",&alloction[i][j]);
		//printf("\n");
	}
	for(i = 0;i < m;i++)
		temp[i] = 0;		//初始化temp
	for(i = 0;i < m; i++)
		for(j = 0;j < n;j++)
			temp[i] += alloction[j][i];	//用temp数组记录当前各类已分配的资源的数量

	for(i = 0;i < m;i++)
		available[i] = resource[i] - temp[i];//用总资源减去已分配的资源，获得剩余资源数

}

void display()
{
	int i = 0,j = 0,t = 0;
	system("cls");
	printf("系统总资源数为：\n\n");
	for(i = 0; i < m; i++)
		printf("%d\t",resource[i]);
	printf("\n各进程所需的资源数\n");
		for(i = 0;i < n; i++)
		{
			printf("p%d\t",i+1);
			for(j = 0;j < m; j++)
				printf("%d\t",claim[i][j]);
			printf("\n");
		}
	printf("\n各进程已获得的资源数\n");
		for(i = 0;i < n; i++)
		{
			printf("p%d\t",i+1);
			for(j = 0;j < m; j++)
				printf("%d\t",alloction[i][j]);
			printf("\n");
		}
	printf("\n各进程已还需要的资源数\n");
		for(i = 0;i < n; i++)
		{
			printf("p%d\t",i+1);
			for(j = 0;j < m; j++)
				printf("%d\t",alloction[i][j]);
			printf("\n");
		}
	printf("\n剩余的资源数\t");
	for(i = 0; i < m; i++)
		printf("%d\t",available[i]);
}

void bank()
{
	int i,j,k,flag = 1;
	int *requst;
	requst = (int *)malloc(sizeof(int)*m);
	printf("\n\n准备就绪。\n\n");
	printf("请选择请求资源的进程号：");
	scanf("%d",&k);
	printf("\np%d请求资源：",k);
	for(i = 0;i < m;i++)
		scanf("%d",&requst[i]);
	for(i = 0;i < m;i++)
	{
		if(alloction[k-1][i] + requst[i] > resource[i])
		{
			flag = 0;
			break;
		}
	}
	if(flag == 0)
		printf("\n请求错误，操作失败！\n");
	else 
	{
		for(i = 0;i < m;i++)
		{
			if(requst[i] > available[i])
			{
				flag = 2;
				break;
			}
		}
		if(flag == 2)
			printf("\n资源不足，请求失败。\n");
		else 
		{
			printf("请求中。。。\n");
			printf("安全检测中。。。\n");
			for(i = 0;i < m;i++)
				{
					alloction[k-1][i] += requst[i];
					available[i] -= requst[i];
				}
			if(safe(k - 1) == 1);
			else    
			{
				printf("\n请求不安全。");
				for(i = 0;i < m;i++)		//请求不安全，恢复之前的状态
				{
					alloction[k][i] -= requst[i];
					available[i] += requst[i];
				}
			}
		}
	}

}

int safe(int k)
{
	int i,j;
	int flag1 = 1,q = 1,t = 0,num = 0,num1 = 0,num2 = 0;
	int *currentavail,**newalloc,*sort;
	int x = k;
	currentavail = (int *)malloc(sizeof(int)*m);
	newalloc = (int **)malloc(sizeof(*newalloc)*n);
	for(i = 0;i < n;i++)
		newalloc[i] = (int *)malloc(sizeof(int)*m);
	currentavail = available;
	sort = (int *)malloc(sizeof(int)*n);	//记录推进完的进程的进程号
	newalloc = alloction;
	for(i = 0;i < n;i++)
		sort[i] = 0;		
	while(num < n)
	{
		t = 0;
		for(i = 0;i < m; i++)
			if(claim[x][i] - newalloc[x][i] <= currentavail[i]&&sort[num] == 0)
				t++;
		if(t == m)		//当前进程可以运行完，释放所占资源
		{
			num1 = 0;
			for(i = 0;i < m; i++)
				currentavail[i] += newalloc[x][i];
			sort[num] = x + 1;
			num++;		//完成的进程数+1
		}
		else
		{
			num1++;	//不能执行完的进程数+1
			if(num1 == n)
			{
				printf("\n请求不安全，会导致死锁。\n");
				system("pause");
				return 0;
			}
		}
		if (num == n)
		{
			printf("请求成功！\n");
			printf("\n该分配不会造成死锁，可执行序列为：\n");
			for (i = 0; i < n; i++)
			{
				printf("%d", sort[i]);
				if (i != n - 1)
					printf("->");
			}
			printf("\n");
			return 1;
		}
		x++;    
		if (x == n)
		{
			x = 0;
		}
	}
}

void main()
{
	int flag = 1;
	char ch = 'y';
	while(flag == 1)
	{
		if(ch == 'Y'||ch == 'y')
		{
			init();
			display();		//显示信息
			bank();			//银行家算法
			system("pause");
			system("cls");
			printf("是否继续操作：Y/N\t");
			fflush(stdin);		
			ch = getchar();
			free(resource );	
			free(available);
			free(claim); 
			free(alloction); 
			free(temp);
		}
		else 
			exit(0);
	}
}

void test1(){
		init();
		display();
		safe(0);//显示信息
		bank();	
}