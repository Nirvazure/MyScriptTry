#include <stdio.h>
int a[100];
int find(int *a,int n) 
{
	int num=a[0];
	int count=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==num)
			count++;
		else
		{
			count--;
			if(count==0)
			{
				num=a[i];
				count=1;
			}
		}
	}
	return num;
}

void main()
{
	int n;
	printf("请输入数组元素个数：\n");
	scanf("%d",&n);
	printf("请输入这%d个数组元素：\n",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("超过数组长度一半的元素为：\n%d\n",find(a,n));
}