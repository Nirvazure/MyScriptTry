#include<stdio.h>
#include<string.h>
struct student
{
	double number;
	char name[20];
	char hobby[20];
};
int main()
{
	struct student stu[6];
	int i,k=0,l=0,m=0,n=0;
	printf("������ѧ����Ϣ��\n");
	for(i=0;i<6;i++)
		scanf("%ld%s%s",&stu[i].number,stu[i].name,stu[i].hobby);
	for(i=0;i<6;i++)
	{
		if(strcmp(stu[i].hobby,"����")==0)	k++;
		else if(strcmp(stu[i].hobby,"����")==0)	l++;
		else if(strcmp(stu[i].hobby,"��ë��")==0)	m++;
		else if(strcmp(stu[i].hobby,"ƹ����")==0)	n++;
	}
	printf("ѧ����Ϣ��\n");
	for(i=0;i<6;i++)
		printf("%ld%s%s",stu[i].number,stu[i].name,stu[i].hobby);
	printf("��ͬ���õ�ѧ��������\n");
	printf("����%d\n����%d\n��ë��%d\nƹ����%d\n",k,l,m,n);
	return 0;
}
	
