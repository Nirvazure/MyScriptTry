#include<stdio.h>
int main()
{
	int fac(int n);
	int i;
	for(i=1;i<=5;i++)
		printf("%d!=%d\n",i,fac(i));
	return 0;
}
int fac(int n)
{
	static int f=1;/*静态变量，下一次执行时初始赋值无效*/
	f=f*n;
	return f;
}
