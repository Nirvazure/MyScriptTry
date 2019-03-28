#include<stdio.h>
int main()
{
	int max_4(int a,int b,int c,int d);
	int a,b,c,d,max;
	printf("a interger numbers:\n");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	max=max_4(a,b,c,d);
	printf("max is %d\n",max);
	return 0;
}
int max_4(int a,int b,int c,int d)
{
	int max_2(int a,int b);
	int m;
	m=max_2(a,b);
	m=max_2(m,c);
	m=max_2(m,d);
	/*return max_2(max_2(a,b),c),d))*/
	return m;
}
int max_2(int a,int b)
{
	if(a>=b)
		return a;
	else 
		return b;
}
