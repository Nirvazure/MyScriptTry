//***********************************************************
//*		�� �� �������ʻ���.c								*
//*		��    �ߣ����D 										*
//*		�����༶��12��������								*
//*		ѧ    �ţ�2012118064								*
//*		����ʱ�䣺2013��02��16��							*
//*		��Ҫ���ܣ�											*
//***********************************************************
#include<hrmthw.h>    //�����Զ����ͷ�ļ�
//#include<malloc.h>
#define MaxHeadcount 200											//�����������������
#define MaxRelationCount (MaxHeadcount*(MaxHeadcount-1)/2)			//����������˹�ϵ����

int headcount = 0;													//����������
int relationConunt = 0;												//���˹�ϵ�ܶ���
int relation[2][MaxRelationCount] = { {-1, 0, 0}, {-1, 0, 0} };		//�洢��������˹�ϵ��relation[0][1]��relation[1][1]��ʶ

/*�����������ۺ���Ϣ���룬���ɼ�������ʽ�������ظ�����*/
int informationInput()
{
	int i = 0, j = 0,k = 0;									//ѭ���ۼӱ���
	int tmp[2] = {0,0};										//����intinput()�����ʱ���
	int maxRelationCount=0;								//��ʱ���������˹�ϵ����

// �������������ܶ��������飬����headcount��relationConunt
	headcount = intinput(1, 1, MaxHeadcount,tmp, "�����������������");
	maxRelationCount = headcount * (headcount - 1) / 2;
	printf("�����������㣬����Ӧ������%d��\n",maxRelationCount);
	relationConunt = intinput(1,0,maxRelationCount,tmp,"�������������˹�ϵ�ܶ�����ͬһ���������ʶ���ˣ���");
	printf("���ԡ�a,b���ĸ�ʽ�����໥��ʶ����ı�ţ�\n");

/*������ʶ���������������뼰�ظ�����,��ȷ����ʶ�������relation[][]��������������*/
	for (i = 1; i <= relationConunt; i++)
	{
		intinput(2, 1, headcount, tmp, " ");/*intinput����hrmthw.h�������Զ���ĺ��������ڰ�ȫ������һ��int���͵����ݡ�
											�˺��������ж������ʽ�����Զ������뷶Χ������ʱ�ṩ��ʾ������Ĺ��ܡ���
											���������ҷֱ���ÿ���������ݸ�������Сֵ�����ֵ����������������������
											�������顢������ʾ��*/               
		if(tmp[0]==tmp[1]){printf("��������Ų�����ͬ�����������룺");i--;continue;}//�����������
		for (j = 0, k = 0; k < 2; j++)
		{
			if (tmp[0] == relation[k][j] && tmp[1] == relation[!k][j])//�����ظ�����
			{
				printf("�����������%d���ظ������������룺\n",j);
				i--;
				break;
			}													
			if (j >= i-1){j = 0;k++;}
		}
		if (k == 2)
		{
			relation[0][i] = tmp[0];
			relation[1][i] = tmp[1];
			printf("�ѳɹ����� %d,%d", relation[0][i], relation[1][i]);
		}
	}
	printf("\n���������!\n");
	return 0;
}

/*���������õݹ鷽ʽ����ܷ񽫴���ֳɻ�����ʶ�����飬���򷵻�0�����򷵻�1����ǵ��²��ܵ�һ���ϵ*/
int compare(int ringHead, int ringNow,int stackNum)						//ringHeadΪ������ʼ�ڵ㣬ringNowΪ��ǰ�ڵ㣬stackNumΪ��ǰջ����
{
	int i,j,k;		//ѭ���ۼӱ���
	int flag=0;		//��ʱ��Ǳ���
	static int relationSkip[MaxRelationCount+1];						//�洢compare()�б��й�ϵ�Ƿ�����Ϊ�ڵ㣬������1����һ��compare()���������С�
	static int newGroup[2][MaxHeadcount+1];								//������
	if(stackNum==0) 
	{
		if(ringHead==1)
		{
			for(i=0;i <= MaxHeadcount;i++) 
			{
				newGroup[0][i]=0;
				newGroup[1][i]=0;
			}
		}
		for(i=0;i <= MaxRelationCount;i++) 
			relationSkip[i]=0;
	}
	stackNum++;
	for (i = 1, j = 0; j < 2; i++)
	{
		if (relationSkip[i] == 1)continue;
		if (i > relationConunt)
		{
			i = 0;
			j++;
			continue;
		}
		if (relation[j][i] != ringNow)continue;
//		if (relation[j][i] <= ringHead)continue;
	/*      */
		flag=(stackNum+ringHead)%2;			//�ж���ż
		for(k=1;k<=headcount;k++)
		{
			if(newGroup[flag][k]==relation[j][i])break;
			else if(newGroup[flag][k]==0){newGroup[flag][k]=relation[j][i];break;};
		}
		for(k=1;k<=headcount;k++)
		{
			if(newGroup[!flag][k]==relation[!j][i])break;
			else if(newGroup[!flag][k]==0){newGroup[!flag][k]=relation[!j][i];break;};
		}

		if (relation[!j][i] == ringHead)
		{
			if (stackNum % 2 == 1){relationSkip[i] = 1;return 1;}
			else continue;
		}
		else 
		{
			relationSkip[i] = 1;
			if(compare(ringHead, relation[!j][i],stackNum)==1)
			{
				if (stackNum==1)
				{
					printf("���ֳܷ����ڳ�Ա������ʶ�����飡\n���ԭ��\n");
					for(i=1;i<=headcount;i++) 
						if(relationSkip[i]==1) 
							printf("%d-%d ",relation[0][i],relation[1][i]);;
				}
				return 1;
			}
			relationSkip[i] = 0;
		}
	}
	stackNum--;
	if(stackNum==0&&ringHead==headcount)
		for(i=1;i<=headcount;i++)
			printf("%d-%d\n",newGroup[0][i],newGroup[1][i]);;
	return 0;
}

/*�����򽫴���ֳ����ڳ�Ա������ʶ������*/
int grouping()
{

	return 0;
}

int main()
{
	int i = 0, j = 0,k = 0;									//ѭ���ۼӱ���
	int errorLevel=0;										//������
//	int newGroup[2][MaxHeadcount+1]={{-1,0,0},{-1,0,0}};	//������
	int acquaintanceNum[MaxHeadcount+1] = { 0 };			// �洢ÿ��������ʶ�����������
//	int sum = 0;

	informationInput();										//�����������ۺ���Ϣ���룬���ɼ�������ʽ�������ظ�����

/*�ݹ����compare()����ܷ񽫴���ֳɻ�����ʶ������,�ɷ��������grouping()���з��飬�������������Ϣ*/
	for (i = 1; i <= headcount; i++)
		if(compare(i, i, 0)==1)break;;

/* �ҳ�ÿ��������ʶ�����������������acquaintanceNum[]*/
	for (i = 1, k = 0; k < 2; i++)
	{
		for (j = 1;j<= headcount;j++)
			if (relation[k][i] == j)acquaintanceNum[j]++;;
		if (i >= MaxHeadcount){i=0;k++;}
	}						

/*	for (i = 1; i <= MaxHeadcount; i++)
		if(x[i] != 0)sum++;;
	// ����������˵Ĵ�������������sum��ʣ�´�����ʶ�κ���*/
	system("pause");
	return 0;
}