#include<stdio.h>
#include<stdlib.h>
#define ElemType int//ElemType ������Ϊ��������ͳһ�����еĺ궨�塣�����ָ�����Ϳ��ں궨�������޸ģ�int��struct���
typedef struct Node //������Ͷ��壬�ʣ��˴���Node��ʾʲô����
{ElemType data;
struct Node *next;
}Node,*LinkList;//LinkListΪ�ṹ��ָ�����͡��ʣ��˾仰��������

/*��ʼ�����������*/
void InitList(LinkList *L)
{
	printf("��ʼ������\n");
	*L=(LinkList)malloc(sizeof(Node));//����ͷ��㡣�ʣ�����ʵ�ַ���
	
	(*L)->next=NULL;//�����յĵ�����L���ʣ�(*L)��ʲô��˼
	printf("��ʼ���������\n");
}

/*ͷ�巨����������*/
void CreateFromHead(LinkList L)
/* *L�Ǵ�ͷ���Ŀ�����ͷָ��*/
{
	Node *s;
	char c;
	int flag=1;

	printf("ͷ�巨��������,$�����˲���\n");
	while(flag) //*flag��ֵΪ1�������롮$��ʱ����flagΪ0���������
	{
		c=getchar();
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node));//sizeof����ṹ�����ͳ��ȼ��ռ䣬malloc������ռ䣬��Node *������ת��Ϊָ����Ϣ
			s->data=c;
			s->next=L->next;
			L->next=s;
		}else {
			flag=0;
			printf("ͷ�巨�������\n");
		}
	}
}

/*β�巨����������*/
void CreateFromTail(LinkList L)
{
	Node *r,*s;//rʼ�մ��βԪ��ַ
	int flag=1;
	r=L;//rָ�붯ָ̬������ǰ��β��������β���룬���ֵָ��ͷ���
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

/*��������Ų���*/
Node *Get(LinkList L,int i)//����ֵΪ�ṹ��ָ��ĺ���get
{
	int j;//ɨ��ڵ������
	Node *p;//�ṹ������ָ�����p
	if(i<0) return NULL;//����λ�ò��Ϸ�,����NULL
	p=L;j=0;//pָ��L,p=0
	while((p->next!=NULL)&&(j<i))
	{
		p=p->next;//ɨ����һ�ڵ�
		j++;//������+1
	}
	if(i==j) return p;
	else return NULL;//�Ҳ���,����NULL
}

void main()
{
	LinkList p;
	InitList(&p);//ʵ�δ�������,����������,ʵ��ֵ���ᱻ�ı�,���Դ�ʵ�ε�ַ,�õ�ַ�������޸�
	CreateFromHead(p);
	printf("%c",Get(p,2)->data);
	system("pause");
}

