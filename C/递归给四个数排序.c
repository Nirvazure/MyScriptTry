#include<stdio.h>
int max;
main()
{
 	int i,a[4];
 	int max_4(int a[]); 
	printf("please enter 4 numbers:\n");
		for(i=0;i<4;i++)
			scanf("%d",&a[i]);
		max=a[0];
 	   printf("%d\n",max_4(a));
}
 	int max_4(int a[])
{
	static int i=0;
 	if(a[i]<a[i+1])
 	max=a[i+1];
  	i++;
	 if(i<4)max_4(a);
 	return max;
}
