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
	printf("����������Ԫ�ظ�����\n");
	scanf("%d",&n);
	printf("��������%d������Ԫ�أ�\n",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("�������鳤��һ���Ԫ��Ϊ��\n%d\n",find(a,n));
}