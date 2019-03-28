#include<stdio.h>
#include "BiTree_List.h"

void main()
{
	int i;
	int numOfLeave=0;
	BiTree_List* tree;
	ElemType data[]="abcdefghijkl";

	tree=BiTree_create(12,data);

	for ( i = 0; i < tree->num; i++)
	{
		if (LChild(tree,i)==0&&RChild(tree,i)==0){
			numOfLeave++;
		}
	}

	printf("非叶子结点有%d个。\n",tree->num-numOfLeave);


	system("pause");
}