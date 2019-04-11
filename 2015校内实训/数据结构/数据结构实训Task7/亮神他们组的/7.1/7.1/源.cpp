#include<stdio.h>
#include<stdlib.h>

typedef struct TNode
{
	char data;
	struct TNode * lchild;
	struct TNode * rchild;
}TNode,*BiTree;
//���������������д���������
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
//����������������д���������
TNode * buildTree(char * pre,char * inorder,int n)
{
	TNode * root;
	if(!(n > 0))
	{
		return NULL;
	}
	root = (TNode*)malloc(sizeof(TNode));
	root->data = pre[0];
	root->lchild = root->rchild = NULL;;
	int i = 0;
	while(i < n)
	{
		if(pre[0] == inorder[i])
		{
			break;
		}
		i++;
	}
	if(i > 0)
	{
		root->lchild = buildTree(&pre[1],&inorder[0],i);
	}
	if(n - i - 1 > 0)
	{
		root->rchild = buildTree(&pre[i + 1],&inorder[i + 1],n - i - 1);
	}
	return root;
}

void outputAsPreOrder(BiTree t)
{
	if(t != NULL)
	{
		printf("%c",t->data);
		outputAsPreOrder(t->lchild);
		outputAsPreOrder(t->rchild);
	}
	else
	{
		printf(" ");
	}
}

//int main()
//{
//	BiTree t;
//	char * pre;
//	char * inorder;
//	int n;
//	printf("���������еĴ�С:\n");
//	scanf("%d",&n);
//	pre = (char *)malloc(n);
//	inorder = (char *)malloc(n);
//	printf("��������������:\n");
//	getchar();
//	for(int i = 0;i < n;i++)
//	{
//		pre[i] = getchar();
//	}
//	printf("��������������:\n");
//	getchar();
//	for(int j = 0;j < n;j++)
//	{
//		inorder[j] = getchar();
//	}
//	t = buildTree(pre,inorder,n);
//	printf("��������Ľ����:\n");
//	preOrder(t);
//	printf("\n");
//	system("pause");
//
//}

void main(){
	BiTree *bt;
	bt = (BiTree *)malloc(sizeof(BiTree));
	CreateBiTree(bt);
	outputAsPreOrder(*bt);
	system("pause");
}