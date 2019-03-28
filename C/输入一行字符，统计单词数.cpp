#include <stdio.h>
int main()
{
	char string[81];                      /*定义一个足够大的数组string储存变量*/
	int i;							      /*用i来控制逐个读string中的字符*/
	int word=0,num=0;					  /*在这里一定要给num和word赋初值，否则*/
	char c;
	printf("this program is for us to find how many nmbers in the sentence\n the sentence's chars are below 80.\n");
	gets(string);					      /*读入一个字符串，放在string数组中*/
	for(i=0;(c=string[i])!='\0';i++)      /*从第一个字符起到最后一个字符*/
		if(c==' ')                        /*如果当前字符为空格，word置为0*/
			word=0;
		else if (word==0)                 /*如果当前不是空格，前一个是空格，word置为1，num加一*/
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

