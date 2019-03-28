#include<stdio.h>
#include<stdlib.h>
int t=0;

int b(char x,char y)
{
	if(x!=65&&y!=65)return (65);
	if(x!=66&&y!=66)return (66);
	else return (67);
}
void a(int n,char x,char y)
{
	if(n==1)printf("%c-->%c\t",x,y);
	else
	{
		a(n-1,x,b(x,y));
		printf("%c-->%c\t",x,y);
		a(n-1,b(x,y),y);
	}
	t++;
}
int main()
{
	int i;
	printf("please input the number of diskes\n");
	scanf("%d",&i);
	a(i,65,67);
	printf("\n%d times moving used\n",t);
	system("sleep 2");
	system("pause");	
	system("exit");
	return 0;
}