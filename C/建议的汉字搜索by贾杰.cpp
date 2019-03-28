#include<stdio.h>
#include<string.h>
void main()
{
	char a[2][20]={{"贾杰是好人"},{"我爱你"}};
	char b[20];
	int i,j,k,x,flag;
	printf("请输入关键字");
	gets(b);
	for(j=0;j<2;j++)
	if(strcmp(a[j],b)==0)puts(a[j]);
	for(i=0;b[i]!='\0';i=i+2){
		for(j=0;j<2;j++)
			for(k=0;a[j][k]!='\0';k=k+2)
				if(a[j][k]==b[i]&&a[j][k+1]==b[i+1]){
					flag=1;x=j;
				}
	}
	if(flag==1)puts(a[x]);
	else printf("无相关信息");
}
