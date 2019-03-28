#include <stdio.h>
void main()
{
 int a[5][4],b[5],i,j,h,t,c,d;
   for (j=0;j<5;j++)
   {d=j+1;
	   for (i=0;i<4;i++)
	   {   
		   c=i+1;
		   printf("请输入第%d位同学第%d科的成绩：",d,c);
		   scanf("%d",&a[j][i]);
	   }
	   b[j]=(a[j][0]+a[j][1]+a[j][2]+a[j][3])/4;
       printf("平均成绩为%-5d\n",b[j]);
   }
for (j=0;j<5;j++)
{
	for (h=0;h<5-j;h++)
    if (b[j]>b[j+1])
	{
	t=b[j];
    b[j]=b[j+1];
    b[j+1]=t;
	}
}
	for (j=0;j<5;j++)
		printf("%-5d",b[j]);
}