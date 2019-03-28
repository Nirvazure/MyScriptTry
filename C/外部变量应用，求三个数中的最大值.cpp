/*用外部变量求三个数中最大值*/
#include<stdio.h>
int main()
{
	int max();
	extern int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	printf("max is %d\n",max());
	return 0;
}
int A,B,C;
int max()
{
	int m;
	m=A>B?A:B;
	if(C>m) m=C;
	return m;
}
/*如果一个程序包含两个文件，在两个文件中都要应用同一个外部变量num，不能分别在两个文件当中个自定义一个外部变量num*/
/*应在一个文件中定义外部变量num，另一文件中用eatern对num做外部变量声明*/