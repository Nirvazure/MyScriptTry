#include <stdio.h>
int main()
{
	char string[81];                      /*����һ���㹻�������string�������*/
	int i;							      /*��i�����������string�е��ַ�*/
	int word=0,num=0;					  /*������һ��Ҫ��num��word����ֵ������*/
	char c;
	printf("this program is for us to find how many nmbers in the sentence\n the sentence's chars are below 80.\n");
	gets(string);					      /*����һ���ַ���������string������*/
	for(i=0;(c=string[i])!='\0';i++)      /*�ӵ�һ���ַ������һ���ַ�*/
		if(c==' ')                        /*�����ǰ�ַ�Ϊ�ո�word��Ϊ0*/
			word=0;
		else if (word==0)                 /*�����ǰ���ǿո�ǰһ���ǿո�word��Ϊ1��num��һ*/
		{
		word=1;
		num++;
		}
		if(num==1)
			printf("there is one word in this line.\n");
		else
			printf("there are %dwords in this line.\n",num);
		return 0;
}

