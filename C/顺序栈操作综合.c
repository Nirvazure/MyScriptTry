#include<stdio.h>
#include<stdlib.h>
#define Stack_Size 50
#define FALSE 0
#define TURE 1
#define StackElementType
type struct{
	StackElementType elem[Stack_Size]��
	int top;//���ջ��Ԫ�ص��±꣬topΪ-1��ʾ�՗C
}SeqStack;

void InitStack(SeqStack *S)//˳��ջ�ĳ�ʼ��������һ���՗CS
{
	S->top=-1;
}

int Push(SeqStack *S,StackElementType x)//˳��ջ��ջ���㣬��x���ڗ���
{
	if(S->top==Stack_Size-1) return FALSE;//ջ������-1����Ϊ����a[9]��a[0]��a[8]�Ÿ���
	S->top++;//��������һλ
	S->elem[S->top]=x;//���λ��û����ֵ����x���藣��
	return TURE;
}

int Pop(SeqStack *S,StackElementType *x)//��ջ������������Ԫ�ص������ŵ�x�洢�ռ����
{
	if(S->top==-1)//ջΪ��
		return FALSE;
	else
	{
		*x=S->elem[S->top];
		S->top--;
		return TURE;
	}
}

int GetTop(SeqStack *S,StackElementType *x)//˳��ջ��ջ�����������������Ԫ�ض������ŵ�x��ָ����ռ䣬ջ��ָ�뱣�ֲ��䣬ջ������ԭ����ֻ�Ƕ�������ֵ
{
	if(S->top==-1)
		return FALSE;
	else
	{
		*x=S->elem[S->top];
		return TURE;
	}
}




