#include<stdio.h>
#include<stdlib.h>

typedef struct TNode
{
	char data;
	struct TNode * lchild;
	struct TNode * rchild;
}TNode,*BiTree;
//输入先序完整序列创立二叉树
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
//利用先序和中序序列创建二叉树
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
//	printf("请输入序列的大小:\n");
//	scanf("%d",&n);
//	pre = (char *)malloc(n);
//	inorder = (char *)malloc(n);
//	printf("请输入先序序列:\n");
//	getchar();
//	for(int i = 0;i < n;i++)
//	{
//		pre[i] = getchar();
//	}
//	printf("请输入中序序列:\n");
//	getchar();
//	for(int j = 0;j < n;j++)
//	{
//		inorder[j] = getchar();
//	}
//	t = buildTree(pre,inorder,n);
//	printf("先序遍历的结果是:\n");
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