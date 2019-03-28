#include<stdio.h>
#include<stdlib.h>
#define Stack_Size 50
#define FALSE 0
#define TURE 1
#define StackElementType
type struct{
	StackElementType elem[Stack_Size]；
	int top;//存放栈顶元素的下标，top为-1表示空桟
}SeqStack;

void InitStack(SeqStack *S)//顺序栈的初始化，构造一个空桟S
{
	S->top=-1;
}

int Push(SeqStack *S,StackElementType x)//顺序栈进栈运算，将x置于棧顶
{
	if(S->top==Stack_Size-1) return FALSE;//栈已满，-1是因为数组a[9]是a[0]到a[8]九个数
	S->top++;//棧顶上移一位
	S->elem[S->top]=x;//最高位还没有数值，将x赋予棧顶
	return TURE;
}

int Pop(SeqStack *S,StackElementType *x)//出栈操作，将棧顶元素弹出，放到x存储空间带走
{
	if(S->top==-1)//栈为空
		return FALSE;
	else
	{
		*x=S->elem[S->top];
		S->top--;
		return TURE;
	}
}

int GetTop(SeqStack *S,StackElementType *x)//顺序栈读栈顶运算操作，将棧顶元素读出，放到x所指储存空间，栈顶指针保持不变，栈还保持原样，只是读出棧顶值
{
	if(S->top==-1)
		return FALSE;
	else
	{
		*x=S->elem[S->top];
		return TURE;
	}
}




