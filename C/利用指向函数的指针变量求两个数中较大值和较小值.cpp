#include<stdio.h>
#include<stdlib.h> 
int main()
{
	int max(int,int);
	int min(int,int);
	int(*p)(int,int);
	int a,b,c,n;
	printf("please enter a b:\n");
	scanf("%d,%d",&a,&b);
	printf("please enter max is 1,min is 2:\n");
	scanf("%d",&n);
	if(n==1) p=max;
	if(n==2) p=min;
	c=(*p)(a,b);
	printf("a=%d,b=%d\n",a,b);
	if(n==1) printf("max=%d\n",c);
	if(n==2) printf("min=%d\n",c);
	return 0;
}
int max(int x,int y)
{int z;
if(x>y) z=x;
else z=y;
return z;
}
int min(int x,int y)
{int z;
if(x>y) z=y;
else z=x;
return z;
}
