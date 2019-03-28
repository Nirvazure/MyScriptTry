#include <stdio.h>
#include <math.h>
int main()
{
	int sign=1;double pi=0,n=1,term=1;
	while(fabs(term)>=1e-7)         /*为什么这里的-7,可以改为-6不能改为-8*/
	{
	pi=pi+term;
	n=n+2;
	sign=-sign;
	term=sign/n;
	}
	pi=pi*4;
printf("pi=%10.8f\n",pi);
return 0;
}

