#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int max,min;
}Data;
int MIN;/*声明全局变量*/
int fun1(int a[],int n){
	/*通过函数return返回最大值，通过全局变量MIN带回最小值*/
	int i,max;
	max=MIN=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max) max=a[i];
		if(a[i]<MIN) MIN=a[i];
	}
	return max;
}

int *fun2(int a[],int n){
	/*将最大值最小值放在数组b中，通过return返回*/
	static int b[2];
	b[0]=b[1]=a[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(a[i]>b[0]) b[0]=a[i];
		if(a[i]<b[1]) b[1]=a[i];
	}
	return b;
}

Data *fun3(int a[],int n){
	/*将最大值最小值放到结构体中，通过return返回结构体指针*/
	Data *p;
	int i;
	p=(Data *)malloc(sizeof(Data));//指针初始化
	p->max=p->min=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>p->max) p->max=a[i];
		if(a[i]<p->min) p->min=a[i];
	}
	return p;
}

Data fun4(int a[],int n){
	/*将最大值最小值放到结构体p中，通过结构体p带回返回值*/
	Data p;
	int i;
	p.max=p.min=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>p.max) p.max=a[i];
		if(a[i]<p.min) p.min=a[i];
	}
	return p;
}

void fun5(int a[],int n,int *p,int *q){
	/*用指针返回结果，指针p指向最大值，指针q指向最小值*/
	int i;
	*p=*q=a[0];
	for(i=1;i<n;i++)
	{
		if(*p<a[i]) *p=a[i];//注意大小写
		if(*q>a[i]) *q=a[i];//注意大小写
	}
}

void main(){
	int a[10]={1,3,8,8,4,2,5,0,7,6},max,*p;
	Data *q;
	Data z;
	int x,y;

	max=fun1(a,10);
	printf("max=%d min=%d\n",max,MIN);

	p=fun2(a,10);
	printf("max=%d min=%d\n",p[0],p[1]);

	q=fun3(a,10);
	printf("max=%d min=%d\n",q->max,q->min);

	z=fun4(a,10);
	printf("max=%d min=%d\n",z.max,z.min);

	fun5(a,10,&x,&y);
	printf("max=%d min=%d\n",x,y);
}
