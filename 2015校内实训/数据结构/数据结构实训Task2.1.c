#include<stdio.h>
#include<stdlib.h>

//0代表左，1代表右
void nuo(int table[], int x, int length,int dir){
	int* w = table;
	int* r = table;
	int temp[20] = { 0 };
	if (dir == 0){
		for (int i = 0; i < length; i++)
		{
			if (i < x){
				temp[i] = *(r++);
			}
			else
			{
				*(w++) = *(r++);
			}
		}
		for (int i = 0; i < x; i++)
		{
			*(w++) = temp[i];
		}
	}
	else if (dir == 1){
		for (int i = 0; i < length; i++)
		{
			if (i <length - x){
				temp[i] = *(r++);
			}
			else
			{
				*(w++) = *(r++);
			}
		}
		for (int i = 0; i < length - x; i++)
		{
			*(w++) = temp[i];
		}
	}
}

void main(){
	int table[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	nuo(table, 3, 10,1);
	for (int i = 0; i < 10; i++)
	{
		printf("%d", table[i]);
	}
	system("pause");
}