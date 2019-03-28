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
	printf("请输入学生信息：\n");
	for(i=0;i<6;i++)
		scanf("%ld%s%s",&stu[i].number,stu[i].name,stu[i].hobby);
	for(i=0;i<6;i++)
	{
		if(strcmp(stu[i].hobby,"篮球")==0)	k++;
		else if(strcmp(stu[i].hobby,"足球")==0)	l++;
		else if(strcmp(stu[i].hobby,"羽毛球")==0)	m++;
		else if(strcmp(stu[i].hobby,"乒乓球")==0)	n++;
	}
	printf("学生信息：\n");
	for(i=0;i<6;i++)
		printf("%ld%s%s",stu[i].number,stu[i].name,stu[i].hobby);
	printf("共同爱好的学生数量：\n");
	printf("篮球：%d\n足球：%d\n羽毛球：%d\n乒乓球：%d\n",k,l,m,n);
	return 0;
}
	
