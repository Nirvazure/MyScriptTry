#include <stdio.h>
#include <math.h>
int main()
{
	double a, b, c,disc,x1,x2,realpart,imagpart;
	printf("This is a method to find out the equation's roots\n ");
	scanf("%lf%lf%lf",&a,&b,&c);
	printf("The equation: %dx^2+%dx+%d\n",&a,&b,&c);
	printf("The equation");
	if(fabs(a)<=1e-6)
		printf("is not a quadratic\n");
		else{
		disc=b*b-4*a*c;
		if disc=0
			printf("has two equal roots:%8.4f\n",-b/(2*a));
		else{
			if disc>0
			{x1=(-b+sqrt(disc)/(2*a));
			 x2=(-b-sqrt(disc)/(2*a));
			 printf("has two real roots:%8.4f,%8,4f\n",x1,x2);
			 else{
				 realpart=-b/(2*a);
				 imagpart=(-b-sqrt(-disc)/(2*a));
				 printf("has complex roots:\n");
				 printf("%8.4f+%8.4fi\n",realpart,imagpart);
				 printf("%8.4f+%8.4fi\n",realpart,imagpart);
			 }
			}
		}
		return 0;
	}