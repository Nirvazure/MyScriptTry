#include <stdio.h>
int main()
{
	printf("this program is a method to work out a simple code");
	printf("please enter a char");	/*if you scanf a it will put Z*/
	char c1,c2;						/*if you scanf Z it will put a*/
	c1=putchar(getchar());
	c2=187-c1;
	printf("%d\n",c2);
	printf("%c\n",c2);
	return 0;
}
