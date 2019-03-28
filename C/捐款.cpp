#include <stdio.h>
#define SUM 1000
int main()
{
	float amount,aver,total;int i;
	for(i=1,total=0;i<=10;i++)
	{
		printf("please enter amount:");
		scanf("%f",&amount);
		total=total+amount;
		if(total>=SUM) break;
	}
	aver=total/i;
	  printf("num=%d\n aver=%10.2f\n");
	  return 0;
}
