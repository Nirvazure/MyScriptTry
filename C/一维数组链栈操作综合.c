#include<stdio.h>
#include<stdlib.h>
#define StackElementType 
#define NULL 0
#define TURE 1
#define FALSE 0
#define M 10//用一维数组管理链栈M个链栈

typedef struct node{
	StackElementType data;
	struct node  *next;
}LinkStackNode;
LinkStack top[M];
typedef LinkStackNode *LinkStack;//问：这一步的功能是？

int Push(LinkStack top[M],int i,StackElementType x)//将数据元素x压入栈top中
{
	LinkStackNode *temp//结构体指针temp
	temp=(LinkStackNode *)malloc(sizeof(LinkStackNode));
	if(temp==NULL)
	return FALSE;//申请空间失败
	temp->data=x;
	temp->next=top[i]->next;
	top[i]->next=temp;
	return TURE;
}

int Pop(LinkStack top[M],int i,StackElementType *x)//将栈top的棧顶元素弹出，放到x所指的存储空间中
{
	LinkStackNode *temp;
	temp=top[i]->next;
	if(temp==NULL)
		return FALSE;
	top[i]->next=temp->next;
	*x=temp->data;
	free(temp);
	return TURE;
}

