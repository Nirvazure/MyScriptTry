#include<stdio.h>
void main()
{
	int max_value(int array[][4]);
	int a[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};/*��θ���һ�����������������ֵ����������У���һ��n��m������*/
	int n;
	n=max_value(a);
	printf("%d",n);
}
int max_value(int array[][4])
{
	int i,j,max;
	max=array[0][0];
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			if(array[i][j]>max)
			max=array[i][j];
	return max;
}