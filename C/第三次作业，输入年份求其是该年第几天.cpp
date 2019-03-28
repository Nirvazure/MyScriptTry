#include<stdio.h>
void main()
{
	int n,y,m,d;
	int run(int x);
	scanf("%d%d%d",&y,&m,&d);
	n=run(y);
	printf("这一天是该年的第");
	switch(m)
	{
	case 1: printf("%d",d);			break;
	case 2: printf("%d",d+31);		break;
	case 3: printf("%d",d+59+n);	break;
	case 4: printf("%d",d+90+n);	break;
	case 5: printf("%d",d+120+n);	break;
	case 6: printf("%d",d+151+n);	break;
	case 7: printf("%d",d+181+n);	break;
	case 8: printf("%d",d+212+n);	break;
	case 9: printf("%d",d+243+n);	break;
	case 10:printf("%d",d+273+n);	break;
	case 11:printf("%d",d+304+n);	break;
	case 12:printf("%d",d+334+n);	break;
	}
	printf("天\n");
}
int run(int x)
{
	int leap;
	if((x%4==0)&&(x%100!=0)||(x%400==0))
	leap=1;
	else leap=0;
	return leap;
}

/*#include<stdio.h>
void main()
{
	int run_days(int y,int m,int d);
	int y,m,d,s;
	printf("输入年月日\n");
	scanf("%d%d%d",&y,&m,&d);
	s=run_days(y,m,d);
	printf("%d年%d月%d日是今年的%d天",y,m,d,s);}

int run_days(int y,int m,int d)
{
int a[12];int t=0,i,s;
a[0]=0;a[1]=31;a[3]=31;a[4]=30;a[5]=31;a[6]=30;a[7]=31;a[8]=31;a[9]=30;a[10]=31;a[11]=30;
if(y%4==0&&y%100!=0)a[2]=20;
else if(y%100==0&&y%400==0)
a[2]=29;
else
a[2]=28;
if(m>12||d>a[m])
printf("错误数据");
else{
for(i=0;i<=m-1;i++)
	{t=t+a[i];}
	s=t+d;
	return s;}
}*/
