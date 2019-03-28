/*有三个字符串，找出其中最大者*/
#include <stdio.h>
#include <string.h>
int main()
{
	char string[20];
	char str[3][20];
	int i;
	printf("please pay attention to the length of string is below 20");
	for(i=0;i<=2;i++)
		gets(str[i]);
	if(strcmp(str[0],str[1])>0)
		strcpy(string,str[0]);
	else
		strcpy(string,str[1]);
	if(strcmp(string,str[2])<0)
		strcpy(string,str[2]);
	printf("\nthe large string is:\n%s\n",string);
	return 0;
}