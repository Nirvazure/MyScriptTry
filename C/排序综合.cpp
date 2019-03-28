/*this is a program to sorted array起泡法实现。*/
#include<stdio.h>
int main()
{
	void sort(int array[],int n);
	int a[10],i;
	printf("please enter the array:\n");
	for(i=0;i<=10;i++)
		scanf("%d",&a[i]);
	sort(a,10);
	printf("the sorter array:\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

/*void sort(int array[],int n)
{
	int i,j,k,t;
	for(i=0;i<n-i;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(array[j]<array[k]) 
			{
				k=j;
			}
			t=array[k];
			array[k]=array[i];
			array[i]=t;
	}
}*/

void sort(int array[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(array[j]>array[j+1])
			{t=array[j];array[j]=array[j+1];array[j+1]=t;}
		}
	}
}
