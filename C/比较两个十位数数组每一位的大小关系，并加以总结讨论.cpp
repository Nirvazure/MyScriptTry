/*比较两个十位数数组每一位的大小关系，并加以总结讨论*/
#include<stdio.h>
int main()
{
	int higher(int x,int y);
	int a[10],b[10],i,m=0,n=0,k=0;
	printf("int arrat a:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
		printf("\n");
	printf("enter array b:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&b[i]);
	}
		printf("\n");
	for(i=0;i<10;i++)
	{
		if(higher(a[i],b[i])==1) n++;
		else if(higher(a[i],b[i])==0) m++;
		else k++;
	}
	printf("a higher b %dtimes\n",n);
	printf("a equals b %dtimes\n",m);
	printf("b higher a %dtimes\n",k);
	if(n>k)   printf("a wins!\n");
	if(n==k)  printf("a equals b!\n");
	if(n<k)	  printf("b wins!\n");
	return 0;
}


int higher(int x,int y)
{
	int flag;
	if(x>y) flag=1;
	else if(x==y) flag=0;
	else flag=-1;
	return flag;
}

