#include <stdio.h>
#include <stdlib.h>
typedef char datatype;

typedef struct Node{
	datatype data;
	struct Node* lchild; 
	struct Node* rchild;
}Node,*BTree;

//创建测试数据  参数：L 树根 、raw字符串表示的原数据
void createTree(BTree *L,datatype **raw){	
	if(**raw=='#'){
		(*L)=NULL;
		(*raw)++;
		return;
	}else{
		(*L)=(Node*)malloc(sizeof(Node));
		(*L)->data=*((*raw)++);
		createTree(&((*L)->lchild),raw);
		createTree(&((*L)->rchild),raw);
	}
}

//打印树，支持三种遍历序列
void printTree(BTree L,int mode){
	if(L==NULL){printf("#");return;}
	if(mode==1){
		printf("%c",L->data);
		printTree(L->lchild,1);
		printTree(L->rchild,1);
	}
	if(mode==2){
		printTree(L->lchild,2);
		printf("%c",L->data);
		printTree(L->rchild,2);
	}
	if(mode==3){
		printTree(L->lchild,3);
		printTree(L->rchild,3);
		printf("%c",L->data);
	}
}

//判定数是否为正则二叉树，是的话返回0，否则返回其他值
int notHoloTree(BTree L){
	 if (L->lchild==NULL&&L->rchild==NULL){
	 	return 0;
	 }else{
	 	if (L->lchild!=NULL && L->rchild!=NULL){
	 		return notHoloTree(L->lchild)+notHoloTree(L->rchild);
	 	}else{
	 		return 1;
	 	}
	 }
}

int main(int argc, char const *argv[])
{
	BTree a;
	char *raw="124##5##36##7##";
	createTree(&a,&raw);
	
	printf("二叉树已创建\n");
	printf("\n先序输出：");
	printTree(a,1);
	printf("\n中序输出：");
	printTree(a,2);
	printf("\n后序输出：");
	printTree(a,3);
	
	printf("\n\n%s\n",notHoloTree(a)?"not a holomorphic tree":"is a holomorphic tree");
	
	return 0;
}
