#include<stdio.h>
#include<stdlib.h>

typedef struct TNode
{
	char data;
	int number;
	TNode * lchild;
	TNode * rchild;
}TNode,*BiTree;

int k = 1;

void CreateBiTree(BiTree * t)
{
	char c;
	c = getchar();
	if(c == '#')
	{
		t = NULL;
	}
	else
	{
		*t = (BiTree)malloc(sizeof(TNode));
		(*t)->data = c;
		(*t)->number = k;
		k++;
		CreateBiTree(&((*t)->lchild));
		CreateBiTree(&((*t)->rchild));
	}
}

void preOrder(BiTree t)
{
	if(t)
	{
		printf("%d,%c",t->number,t->data);
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
	else
	{
		printf(" ");
	}

}

/*int printAncestors(BiTree t,int number)
{
	if(!t)
	{
		return 0;
	}
	if(t->lchild == target || t->rchild == target)
	{
		return t;
	}
	
}
*/
int main()
{
	BiTree t;
	CreateBiTree(&t);
	preOrder(t);
	printf("\n");
	system("pause");
	return 0;
}