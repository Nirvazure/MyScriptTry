#include<stdio.h>
void sort(int array[],int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		if(array[j]>array[k]) k=j;
		t=array[k];
		array[k]=array[i];
		array[i]=t;
	}
}
void delete_1(int array[],int n,int value)
{
	int i;
	for(i=0;i<n;i++)
		if(array[i]==value)
		{
			array[i]=array[i+1];
		}
}
int main()
{
	int a[12];
	int i,b;
	printf("please enter 12 numbers:\n");
	for(i=0;i<12;i++)
	{scanf("%d",&a[i]);}
	sort(a,12);
	for(i=0;i<12;i++)
	{printf("%d ",a[i]);}
	printf("\n");
	scanf("%d",&b);
	delete_1(a,12,b);
	for(i=0;i<11;i++)
		printf("%d ",a[i]);
	return 0;
}