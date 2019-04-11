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
{//构造一个空队列
	Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
	}
}

void EnQueue(LinkQueue *Q,BiTree e)
{//插入元素e为Q的新的队尾元素
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
{//若队列不空，删除Q的对头元素，用e返回其值，并返回OK，否则返回ERROR
	LinkQueueNode *p;
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	*e=p->data;
	free(p);
}

//扩展先序遍历序列创建二叉链表
void CreateBiTree(BiTree *bt)
{
	//扩展的遍历序列中，用特定的元素表示空子树，此处用.表示空子树
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
{//若Q为空队列，则返回TRUE，否则返回FALSE
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
		else   //遇到不为空的节点
			return(1);
	}
	return(0);//否则说明整个队列的元素都是空的
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
	printf("按扩展先序遍历序列建立二叉树，请输入序列:");
    CreateBiTree(&T);
	if(IsComplete(T)==1)
		printf("该树是完全二叉树！\n");
	if(IsComplete(T)==0)
		printf("该树不是完全二叉树！\n");
}

