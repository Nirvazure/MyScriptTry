#include <stdio.h>
int main()
{
	int begin,end,sum=1;
	scanf("%d,%d",&begin,&end);
	for(begin=1;begin<=end;begin++)
	{
		sum=begin*sum;
	}
		printf("result=%d",sum);
		return 0;
}
