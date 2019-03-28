#include<stdio.h>
#include<stdlib.h>
#define ElemType int//ElemType 类型是为了描述的统一而进行的宏定义。其具体指代类型可在宏定义里面修改，int，struct随便
typedef struct Node //结点类型定义，问：此处的Node表示什么含义
{ElemType data;
struct Node *next;
}Node,*LinkList;//LinkList为结构体指针类型。问：此句话具体语意

/*初始化单链表操作*/
void InitList(LinkList *L)
{
	printf("初始化操作\n");
	*L=(LinkList)malloc(sizeof(Node));//建立头结点。问：具体实现方法
	
	(*L)->next=NULL;//建立空的单链表L。问：(*L)是什么意思
	printf("初始化操作完成\n");
}

/*头插法建立单链表*/
void CreateFromHead(LinkList L)
/* *L是带头结点的空链表头指针*/
{
	Node *s;
	char c;
	int flag=1;

	printf("头插法建立链表,$结束此操作\n");
	while(flag) //*flag初值为1，当输入‘$’时，置flag为0；建表结束
	{
		c=getchar();
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node));//sizeof测算结构体类型长度即空间，malloc申请结点空间，（Node *）类型转换为指针信息
			s->data=c;
			s->next=L->next;
			L->next=s;
		}else {
			flag=0;
			printf("头插法操作完成\n");
		}
	}
}

/*尾插法建立单链表*/
void CreateFromTail(LinkList L)
{
	Node *r,*s;//r始终存放尾元地址
	int flag=1;
	r=L;//r指针动态指向链表当前表尾，便于作尾插入，其初值指向头结点
	while(flag)
	{
		char c;
		c=getchar();
		if(c!='$')
		{
			s=(Node *)malloc(sizeof(Node));
			s->data=c;
			r->next=s;
			r=s;
		}
		else
		{
			flag=0;
			r->next=NULL;
		}
	}
}

/*单链表按序号查找*/
Node *Get(LinkList L,int i)//返回值为结构体指针的函数get
{
	int j;//扫描节点计数器
	Node *p;//结构体类型指针变量p
	if(i<0) return NULL;//插入位置不合法,返回NULL
	p=L;j=0;//p指向L,p=0
	while((p->next!=NULL)&&(j<i))
	{
		p=p->next;//扫描下一节点
		j++;//计数器+1
	}
	if(i==j) return p;
	else return NULL;//找不到,返回NULL
}

void main()
{
	LinkList p;
	InitList(&p);//实参传给函数,经历操作后,实参值不会被改变,所以传实参地址,用地址来进行修改
	CreateFromHead(p);
	printf("%c",Get(p,2)->data);
	system("pause");
}

