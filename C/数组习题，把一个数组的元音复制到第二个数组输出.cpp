/*this is a program to put a,e,i,o,u to another array*/
#include<stdio.h>
void main()
{
	void yuan(char a[100]);
	char a[100];
	printf("please scanf the char string:\n");
	gets(a);
	yuan(a);
	printf("the trakled string is:\n");
    puts(a);
}
void yuan(char a[100])
{
	int i,m=0,j=0;
	for(i=0;i<100;i++)
		if(a[i]==65||a[i]==69||a[i]==73||a[i]==79||a[i]==85||a[i]==97||a[i]==101||a[i]==105||a[i]==111||a[i]==117){a[j]=a[i];j++;m++;}
		{
			for(i=j;i<100;i++)a[i]=0;
		}
}
/*
#include <stdio.h>
int main()
{
	int i,j=0;char c,d;
	char a[100],b[100]={0};
	gets (a);
	for (i=0;(c=a[i])!='\0';i++)
	{
		if(a[i]=='a'||a[i]=='e'||a[i]=='u'||a[i]=='i'||a[i]=='o'||a[i]=='A'||a[i]=='U'||a[i]=='I'||a[i]=='O'||a[i]=='E')
		{
			b[j]=a[i];
			j++;
		}
	}
	for (j=0;(d=b[j])!='\0';j++)
	printf("%c",b[j]);
	printf("\n");
	return 0;
}*/