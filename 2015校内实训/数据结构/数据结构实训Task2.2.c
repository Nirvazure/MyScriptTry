#include<stdio.h>
#include<stdlib.h>

void gun(char * table, char x){
	char* w = table;
	char* r = table;
	while (*r!='\0')
	{
		if (*r != x){
			*w = *r;
			w++;
		}
		r++;
	}
	*w = '\0';
}

void main(){
	char table[50] = "kjgiuguifyudfgsadafku";
	gun(table, 'u');
	printf("%s", table);
	system("pause");
}