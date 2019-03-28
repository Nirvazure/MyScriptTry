#include <stdio.h>
#include<stdlib.h>
int main()
{ 
     char a[100];
     char c;
	 int i;
     scanf("%s",a);
     for(i=0;a[i]!=0;i++)
	 {
		c=a[i];
		printf("%c ",c);
	 }
	 system("pause");
     return 0;
}
/*
#include<stdio.h>
main()
{
	int a,b;int i=0;
	scanf("%d",&a);
	while(a!=0)
	{
		b=a%10;i++;
		printf("倒数第%d位是%d ",i,b);
		a=a/10;
		printf("\n");
	}
}

#include <stdio.h>
int main()
{ 
	 int tmp=0;
	 int a[50]={0};
	 int i,j;
	 scanf("%d",&tmp);
	 for(i=0;tmp>0;i++){
	   a[j++]=tmp%10;
	   tmp=tmp/10;
	 }
	 for(i=49;i>=0;i--){
	   if(a[i]!=0)break;
	 }
	 for(j=i;j>=0;j--){
	   printf("%d  ",a[j]);
	 }
  printf("\n");
  return 0;
}
*/