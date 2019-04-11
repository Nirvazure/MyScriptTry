#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	char data;
	struct Node *lchild;
	struct Node *rchild;
}BiTNode,*BiTree;

typedef struct node
{
	BiTree data;
	struct node *next;
}LinkQueueNode;
typedef struct
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

void InitQueue(LinkQueue *Q)
{//����һ���ն���
	Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
	}
}

void EnQueue(LinkQueue *Q,BiTree e)
{//����Ԫ��eΪQ���µĶ�βԪ��
	LinkQueueNode *p;
	p=(LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if(p!=NULL)
	{
		p->data=e;
		p->next=NULL;
		Q->rear->next=p;
		Q->rear=p;
	}
}

void DeQueue(LinkQueue *Q,BiTree *e)
{//�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
	LinkQueueNode *p;
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	*e=p->data;
	free(p);
}

//��չ����������д�����������
void CreateBiTree(BiTree *bt)
{
	//��չ�ı��������У����ض���Ԫ�ر�ʾ���������˴���.��ʾ������
	char ch;
	ch=getchar();
	if(ch=='.')
		*bt=NULL;
	else
	{
		*bt=(BiTree)malloc(sizeof(BiTNode));
		(*bt)->data=ch;
		CreateBiTree(&((*bt)->lchild));
		CreateBiTree(&((*bt)->rchild));
	}
}

int QueueEmpty(LinkQueue *Q)
{//��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
	if(Q->front==Q->rear)
		return(1);
	else
		return(0);
}

int list(LinkQueue *Q)
{
	LinkQueueNode *p;
	p=Q->front->next;
	while(p!=Q->rear)
	{
		if(p->data==NULL)
			p=p->next;
		else   //������Ϊ�յĽڵ�
			return(1);
	}
	return(0);//����˵���������е�Ԫ�ض��ǿյ�
}

int IsComplete(BiTree t)
{
	LinkQueue Q;
	BiTree p;
	InitQueue(&Q);
	if(t==NULL)
		return(1);
	EnQueue(&Q,t);
	DeQueue(&Q,&p);
 /*   while(p!=NULL)  
    { 
		EnQueue(&Q,p->lchild);
		EnQueue(&Q,p->rchild);
		DeQueue(&Q,&p);
	}
	if(list(&Q)==0)
		return(1);  
	if(list(&Q)==1)
		return(0);*/
	if(!p)  
    { 
		EnQueue(&Q,p->lchild);
		EnQueue(&Q,p->rchild);
		DeQueue(&Q,&p);
	}
	else
	{
		while(QueueEmpty(&Q)==0)
		{
			DeQueue(&Q,&p);
			if(!p)
				return(0);
		}
		return(1);
	}	
}

void main()
{
	BiTree T;
	printf("����չ����������н���������������������:");
    CreateBiTree(&T);
	if(IsComplete(T)==1)
		printf("��������ȫ��������\n");
	if(IsComplete(T)==0)
		printf("����������ȫ��������\n");
}

