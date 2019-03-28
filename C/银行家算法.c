#include<stdio.h>
#include<stdlib.h>

int n,m;			//��m��n�ֱ��¼����������Դ��������
int *resource ;	//������Դ����
int *available ;//����ʣ����Դ����
int **claim ; //�������̶���Դ���������
int **alloction; //������ǰ�����ѵõ�����Դ����
int *temp ;	//����һ���������������ʱ���ݴ���

void init()
{
	int i = 0,j = 0,t = 0;
	printf("���������������Դ��������");
	scanf("%d%d",&n,&m);
	resource = (int *)malloc(sizeof(int)*m);	//Ϊ��Դ���鶯̬����ռ�
	available = (int *)malloc(sizeof(int)*m);//Ϊʣ����Դ���鶯̬����ռ�
	claim = (int **)malloc(sizeof(*claim)*n);//Ϊ���̶���Դ���������̬����ռ�
	for(i = 0;i < n;i++)
		claim[i] = (int *)malloc(sizeof(int)*m);
	alloction = (int **)malloc(sizeof(*alloction)*n);//Ϊ��ǰ�����ѵõ�����Դ����̬����ռ�
	for(i = 0;i < n;i++)
		alloction[i] = (int *)malloc(sizeof(int)*m);
	temp = (int *)malloc(sizeof(int)*m);	//Ϊ��ʱ�������ռ�
	printf("\n���������������Դ������");
	for(i = 0;i < m; i++)
		scanf("%d",&resource[i]);
	printf("\n�������������������Ҫ����Դ����\n");
	for(i = 0;i < n; i++)
		{
			printf("\n������p%d��Ҫ����Դ��:\t",i+1);
			for(j = 0;j < m; j++)
				scanf("%d",&claim[i][j]);
			//printf("\n");
		}
	printf("\n��Ϊ�������̷�����Դ\n");
	for(i = 0;i < n; i++)
	{
		printf("\n��Ϊp%d������Դ��",i+1);
		for(j = 0;j < m; j++)
			scanf("%d",&alloction[i][j]);
		//printf("\n");
	}
	for(i = 0;i < m;i++)
		temp[i] = 0;		//��ʼ��temp
	for(i = 0;i < m; i++)
		for(j = 0;j < n;j++)
			temp[i] += alloction[j][i];	//��temp�����¼��ǰ�����ѷ������Դ������

	for(i = 0;i < m;i++)
		available[i] = resource[i] - temp[i];//������Դ��ȥ�ѷ������Դ�����ʣ����Դ��

}

void display()
{
	int i = 0,j = 0,t = 0;
	system("cls");
	printf("ϵͳ����Դ��Ϊ��\n\n");
	for(i = 0; i < m; i++)
		printf("%d\t",resource[i]);
	printf("\n�������������Դ��\n");
		for(i = 0;i < n; i++)
		{
			printf("p%d\t",i+1);
			for(j = 0;j < m; j++)
				printf("%d\t",claim[i][j]);
			printf("\n");
		}
	printf("\n�������ѻ�õ���Դ��\n");
		for(i = 0;i < n; i++)
		{
			printf("p%d\t",i+1);
			for(j = 0;j < m; j++)
				printf("%d\t",alloction[i][j]);
			printf("\n");
		}
	printf("\n�������ѻ���Ҫ����Դ��\n");
		for(i = 0;i < n; i++)
		{
			printf("p%d\t",i+1);
			for(j = 0;j < m; j++)
				printf("%d\t",alloction[i][j]);
			printf("\n");
		}
	printf("\nʣ�����Դ��\t");
	for(i = 0; i < m; i++)
		printf("%d\t",available[i]);
}

void bank()
{
	int i,j,k,flag = 1;
	int *requst;
	requst = (int *)malloc(sizeof(int)*m);
	printf("\n\n׼��������\n\n");
	printf("��ѡ��������Դ�Ľ��̺ţ�");
	scanf("%d",&k);
	printf("\np%d������Դ��",k);
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
		printf("\n������󣬲���ʧ�ܣ�\n");
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
			printf("\n��Դ���㣬����ʧ�ܡ�\n");
		else 
		{
			printf("�����С�����\n");
			printf("��ȫ����С�����\n");
			for(i = 0;i < m;i++)
				{
					alloction[k-1][i] += requst[i];
					available[i] -= requst[i];
				}
			if(safe(k - 1) == 1);
			else    
			{
				printf("\n���󲻰�ȫ��");
				for(i = 0;i < m;i++)		//���󲻰�ȫ���ָ�֮ǰ��״̬
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
	sort = (int *)malloc(sizeof(int)*n);	//��¼�ƽ���Ľ��̵Ľ��̺�
	newalloc = alloction;
	for(i = 0;i < n;i++)
		sort[i] = 0;		
	while(num < n)
	{
		t = 0;
		for(i = 0;i < m; i++)
			if(claim[x][i] - newalloc[x][i] <= currentavail[i]&&sort[num] == 0)
				t++;
		if(t == m)		//��ǰ���̿��������꣬�ͷ���ռ��Դ
		{
			num1 = 0;
			for(i = 0;i < m; i++)
				currentavail[i] += newalloc[x][i];
			sort[num] = x + 1;
			num++;		//��ɵĽ�����+1
		}
		else
		{
			num1++;	//����ִ����Ľ�����+1
			if(num1 == n)
			{
				printf("\n���󲻰�ȫ���ᵼ��������\n");
				system("pause");
				return 0;
			}
		}
		if (num == n)
		{
			printf("����ɹ���\n");
			printf("\n�÷��䲻�������������ִ������Ϊ��\n");
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
			display();		//��ʾ��Ϣ
			bank();			//���м��㷨
			system("pause");
			system("cls");
			printf("�Ƿ����������Y/N\t");
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
		safe(0);//��ʾ��Ϣ
		bank();	
}