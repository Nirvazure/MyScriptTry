#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,c,s,area;
	scanf("%d,%d,%d",&a,&b,&c);
		s=(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("area=%d\n",area);
		return 0;
}