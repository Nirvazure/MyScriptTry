/*���ⲿ�����������������ֵ*/
#include<stdio.h>
int main()
{
	int max();
	extern int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	printf("max is %d\n",max());
	return 0;
}
int A,B,C;
int max()
{
	int m;
	m=A>B?A:B;
	if(C>m) m=C;
	return m;
}
/*���һ��������������ļ����������ļ��ж�ҪӦ��ͬһ���ⲿ����num�����ֱܷ��������ļ����и��Զ���һ���ⲿ����num*/
/*Ӧ��һ���ļ��ж����ⲿ����num����һ�ļ�����eatern��num���ⲿ��������*/