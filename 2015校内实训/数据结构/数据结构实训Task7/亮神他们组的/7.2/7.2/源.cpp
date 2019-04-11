#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct TNode
{
	char data;
	struct TNode * lchild;
	struct TNode * rchild;
}TNode,*BiTree;

struct Queue
{
	TNode * data;
}ar[MAXSIZE];

void CreateBiTree(BiTree * t)
{
	char c;
	c = getchar();
	if(c == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (BiTree)malloc(sizeof(TNode));
		(*t)->data = c;
		CreateBiTree(&((*t)->lchild));
		CreateBiTree(&((*t)->rchild));
	}
}

void preOrder(BiTree t)
{
	if(t)
	{
		printf("%c",t->data);
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
	else
	{
		printf(" ");
	}
}

int getWidth(BiTree t)
{
	int front = -1;
	int rear = -1;
	int c = 0;
	int flag = 0;								//当前层的宽度
	int k = -1;
	if(t)
	{
		rear++;
		ar[rear].data = t;
		flag = 1;
		k = rear;
	}
	while(front < k)
	{
		front++;
		t = ar[front].data;
		if(t->lchild)
		{
			c++;
			rear++;
			ar[rear].data = t->lchild;
		}
		if(t->rchild)
		{
			c++;
			rear++;
			ar[rear].data = t->rchild;
		}
		if(front == k)
		{
			if(flag < c)
			{
				flag = c;
			}
			c = 0;
			k = rear;
		}
	}
	return flag;
}

int main()
{
	BiTree t;
	printf("新建一棵树:\n");
	CreateBiTree(&t);
	printf("数的先序遍历的结果:\n");
	preOrder(t);
	printf("\n树的宽度为:\n%d\n",getWidth(t));
	printf("\n");
	system("pause");
}