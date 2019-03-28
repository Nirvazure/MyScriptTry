#include<stdio.h>
void main()
{
	int max_value(int array[][4]);
	int a[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};/*如何给定一个任意数组求其最大值，并输出行列，如一个n乘m的数组*/
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