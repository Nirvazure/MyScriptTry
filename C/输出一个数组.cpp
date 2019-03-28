#include <stdio.h>
int main()
{
	char a;
	int n=0;
	int i;
	do{
	a=getchar();n++;
	}
	while(a!='\n');
	for(i=0;i<=n;i++)
	printf("%c",a);
	printf("\n");
	return 0;
}