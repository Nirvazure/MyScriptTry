
#include<stdio.h>
void main()
{
	int max(int x,int y);
	int min(int x,int y);
	int a,b,maxn,minn;
	printf("please enter two int numbers:\n");
	scanf("%d%d",&a,&b);
	maxn=max(a,b);
	minn=min(a,b);
	printf("max=%d\n",maxn);
	printf("min=%d\n",minn);
}

int max(int x,int y)
{
	int i,max;
	for(i=(x<y?x:y);i>=1;i--)
		if(x%i==0&&y%i==0)
		{
		max=i;
		return max;
		}
}
int min(int x,int y)
{
	int i,min;
	for(i=(x>y?x:y);;i++)
		if(i%x==0&&i%y==0)
		{
		min=i;
		return min;
		}
}



/*
#include<stdio.h>
void main()
{
	int min(int x,int y);
	int max(int x,int y,int z);
	int a,b,maxn,minn;
	printf("please enter two int numbers:\n");
	scanf("%d%d",&a,&b);
	maxn=min(a,b);
	minn=max(a,b,maxn);
	printf("max=%d\n",maxn);
	printf("min=%d\n",minn);
}


int min(int x,int y)
{
	int i,minn;
	for(i=1;i<(x<y?x:y);i++)
		if(x%i==0&&y%i==0)
		{
		minn=i;
		}
		return minn;
}
int max(int x,int y,int z)
{
	int i,maxn ;
	maxn=(x*y)/z;
	return maxn;
}
*/


/*#include<stdio.h>
void main()
{
	int max(int x,int y);
	int min(int x,int y);
	int a,b,maxn,minn;
	printf("please enter two int numbers:\n");
	scanf("%d%d",&a,&b);
	maxn=max(a,b);
	minn=min(a,b);
	printf("max=%d\n",maxn);
	printf("min=%d\n",minn);
}


#include<stdio.h>
int maxm(int x,int y)
{
	int i,max;
	for(i=1;i<=(x>y?y:x);i++)
		if(x%i==0&&y%i==0)max=i;
	return max;
}
int minm(int x,int y)
{
	int i;
	for(i=x>y?x:y;i<=x*y;i++)
		if(i%x==0&&i%y==0)return i;
}
main()
{
	int x,y;
	printf("please input two number:\n");
	scanf("%d%d",&x,&y);
	printf("最大公约数是：%d\n",maxm(x,y));
	printf("最小公倍数是：%d\n",minm(x,y));

}*/