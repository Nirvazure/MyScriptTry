#include<stdio.h>
#include<stdlib.h>
#define StackElementType 
#define NULL 0
#define TURE 1
#define FALSE 0
#define M 10//��һά���������ջM����ջ

typedef struct node{
	StackElementType data;
	struct node  *next;
}LinkStackNode;
LinkStack top[M];
typedef LinkStackNode *LinkStack;//�ʣ���һ���Ĺ����ǣ�

int Push(LinkStack top[M],int i,StackElementType x)//������Ԫ��xѹ��ջtop��
{
	LinkStackNode *temp//�ṹ��ָ��temp
	temp=(LinkStackNode *)malloc(sizeof(LinkStackNode));
	if(temp==NULL)
	return FALSE;//����ռ�ʧ��
	temp->data=x;
	temp->next=top[i]->next;
	top[i]->next=temp;
	return TURE;
}

int Pop(LinkStack top[M],int i,StackElementType *x)//��ջtop�ė���Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ���
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

