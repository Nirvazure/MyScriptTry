//***************************************************
//*    �� �� �������ʻ���������.c                 *
//*    ��    �ߣ����D                               *
//*    �����༶��12��������                       *
//*    ѧ    �ţ�2012118064                         *
//*    ����ʱ�䣺2013��02��16��                     *
//*    ��Ҫ���ܣ��λ�������𡢷������           *
//***************************************************

#define MAX_HEADCOUNT 200												//�����������������
#define INPUT_FILENAME "info.txt"
#define OUTPUT_FILENAME "output.txt"
#include"hrmthw.h"													    //�����Զ����ͷ�ļ�

int g_headcount = 0;														//����������
int g_RelationCount = 0;													//���˹�ϵ�ܶ���
int g_Relation[MAX_HEADCOUNT+1][MAX_HEADCOUNT+1] = {{0,0},{0,0}};			//�洢��������˹�ϵ��g_Relation[0][1]��g_Relation[1][1]��ʶ


/*���������ڴӼ���������Ϣ�����ɼ�������ʽ�������ظ�����*/
int informationInput()
{
	int i = 0;										
	int tmp[2] = {0,0};										//����ui_NumInput()�����ʱ���
	int maxRelationCount=0;									//��ʱ���������˹�ϵ����

// �������������ܶ��������飬����g_headcount��g_RelationCount
	g_headcount = ui_NumInput(1, 1, MAX_HEADCOUNT,tmp, "�����������������\n");
	maxRelationCount = g_headcount * (g_headcount - 1) / 2;
	printf("�����������㣬����Ӧ������%d��\n",maxRelationCount);
	g_RelationCount = ui_NumInput(1,0,maxRelationCount,tmp,"�������������˹�ϵ�ܶ�����ͬһ���������ʶ���ˣ���\n");
	printf("���ԡ�a,b���ĸ�ʽ�����໥��ʶ����ı�ţ�\n");

//������ʶ���������������뼰�ظ�����,��ȷ����ʶ�������g_Relation[][]��������������
	for (i = 1; i <= g_RelationCount; i++)
	{
		ui_NumInput(2, 1, g_headcount, tmp, "");           
		if(tmp[0]==tmp[1]){printf("��������Ų�����ͬ�����������룺");i--;continue;}						
		if (g_Relation[tmp[0]][tmp[1]]==1){printf("����������֮ǰ�����ظ������������룺\n");i--;continue;}								
		g_Relation[tmp[0]][tmp[1]] = 1;
		g_Relation[tmp[1]][tmp[0]] = 1;
		printf("�ѳɹ����� %d,%d\n", tmp[0], tmp[1]);
	}
	printf("\n���������!\n");
	return 0;
}


//���������ڴ�info.txt������Ϣ�����ܼ���ʽ����
int informationFromFile ()
{
	FILE *fp;
	char tmp[100]={0};
	int i=0;
	int temp=0,temp1=0;
	int errorFlag=0;
	int originRelationData[2][MAX_HEADCOUNT+1]={0};

    if((fp=fopen(INPUT_FILENAME,"r"))==NULL)									//�� INPUT_FILENAME �ļ���δ�ҵ�����ʾ����
    {
		printf("δ�ҵ��ļ� %s!\n",INPUT_FILENAME);
        return 1;
    }
	if(file_TargetRead(fp,"g_headcount=",1,"%[0-9]",tmp))errorFlag=1;		//���ļ���ȡ����������
	temp=atoi(tmp);
	if(temp<0||temp>MAX_HEADCOUNT) errorFlag=3;
	else g_headcount=temp;

	if(file_TargetRead(fp,"g_RelationCount=",1,"%[0-9]",tmp))errorFlag=2;	//���ļ���ȡ�����ϵ�ܶ���
	temp=atoi(tmp);
	if(temp<0||temp>MAX_HEADCOUNT*(MAX_HEADCOUNT-1)/2) errorFlag=3;
	else g_RelationCount=temp;

	for(i=1;i<=g_RelationCount && errorFlag==0;i++)						//���ļ���ȡ�����ϵ
	{
		if(file_TargetRead(fp,"#",i+1,"%[0-9]",tmp))errorFlag=4;
		temp=atoi(tmp);
		if(temp<1||temp>g_headcount) {errorFlag=3;break;}
		if(file_TargetRead(fp,",",i+1,"%[0-9]",tmp))errorFlag=4;
		temp1=atoi(tmp);
		if(temp1<1||temp1>g_headcount) {errorFlag=3;break;}
		if(temp==temp1) {errorFlag=4;break;}					//�������
		if (g_Relation[temp][temp1]==1) {errorFlag=5;break;}		//�����ظ���ϵ
		g_Relation[temp][temp1] = 1;
		g_Relation[temp1][temp] = 1;
		originRelationData[0][i]=temp;
		originRelationData[1][i]=temp1;
	}
	fclose(fp);
	switch (errorFlag)
	{
	case 0:
		printf("\n�ѳɹ����ļ�%s¼����Ϣ��\n\n",INPUT_FILENAME);
		printf("____ ԭʼ���� ____\n\n");
		printf("������������%d\n��ϵ�ܶ�����%d\n",g_headcount,g_RelationCount);
		printf("�����ϵ��\n");											//���������ʶ��ϵ
		for(i=1;i<=g_RelationCount;i++)
			printf("%3d  -%3d\n",originRelationData[0][i],originRelationData[1][i]);
		return 0;
	case 1:
		printf("\n��ȡ����������\n");
		break;
	case 2:
		printf("\n��ȡ��������˹�ϵ�ܶ�������\n");
		break;
	case 3:
		printf("\n���������Ч��Χ�ڣ�\n");
		break;
	case 4:
		printf("\n��ȡ������ϵ����\n");
		break;
	case 5:
		printf("\n������ϵ�����ظ���\n");
		break;
	default:		
		break;
	}
	return 1;
}


//�����������������������
int randomDataGenerator()
{
	int maxRelationCount=0;									//��ʱ���������˹�ϵ����
	int i=0,j=0;
	int tmp[2]={0};

	printf("�����ĵȴ�...\n");
	g_headcount = math_Random(1,10);
	maxRelationCount = g_headcount * (g_headcount - 1) / 2;
	g_RelationCount = math_Random(0,maxRelationCount);
	for(i=1;i<=g_RelationCount;i++)
	{
		tmp[0]=math_Random(1,g_headcount);
		tmp[1]=math_Random(1,g_headcount);
		if(tmp[0]==tmp[1]){i--;continue;}						
		if (g_Relation[tmp[0]][tmp[1]]==1){i--;continue;}								
		g_Relation[tmp[0]][tmp[1]] = 1;
		g_Relation[tmp[1]][tmp[0]] = 1;
		printf("%d\n",g_RelationCount-i);
	}
	return 0;
}


//�������������������newGroup[][]�����˵��
int printer(int newGroup[][MAX_HEADCOUNT+1],int peopleSkip[])
{
	int i,j;
	int target=1;
	int line=0;
	int endFlag=0;				//������־
	while(1)
	{
		for(i=1;i<=g_headcount;i++)
			if( peopleSkip[newGroup[line][i]] == 0 )break;;		//�ҳ���δɨ�����ϵ�˵��ѷ���Ա
		if(newGroup[line][i]!=0 && i<=g_headcount)
		{
			endFlag=0;
			target = newGroup[line][i];
		}
		else
		{ 
			if(endFlag==1)return 0;
			endFlag=1;
			line=!line;
			continue;
		}	

		for(i=1;i<=g_headcount;i++)
		{		
			if(target<0)return 2;
			if(g_Relation[target][i]==1)
			{
				for(j=1;newGroup[line][j]>0&&j<=g_headcount;j++)
					if(newGroup[line][j]==i) return 1;;
				for(j=1;newGroup[!line][j]>0&&j<=g_headcount;j++)
					if(newGroup[!line][j]==i) break;;
				if(j<=g_headcount) 
					newGroup[!line][j]=i;
			}
		}
		peopleSkip[target]=1;
	}
	return 0;
}
//������������ֳ����ڳ�Ա������ʶ������,�ɹ�����0,���ܷ����򷵻�1
int grouping(int newGroup[][MAX_HEADCOUNT+1])
{
	int i,j;		//ѭ���ۼӱ���
	int peopleSkip[MAX_HEADCOUNT+1]={0};

	for (i = 1; i <= g_headcount; i++)
	{
		if(peopleSkip[i]==1)continue;			//�ж�i�����Ƿ��ѷ��飬��������
		for(j=1;newGroup[0][j]!=0;j++);
		newGroup[0][j]=i;
		if(printer(newGroup,peopleSkip))return 1;
	}
	return 0;
}


//���������Ŵ������������
int acquaintanceNum(int peopleNum,int peopleSkip[])//Ҫ����Ĵ�����
{
	int i;
	int ans=0;
	for(i=1;i<=g_headcount;i++)
	{
		if(peopleSkip[i]==1)continue;
		ans=ans+g_Relation[peopleNum][i];
	}
	return ans;
}
//ʹ��̰�ķ����価���ܶ�ķ��䣬ʹͬһ��������໥��ʶ���������room[][]������ֵΪ���䷿����
int allotRoom(int room[][2])
{
	int i,j,k=0;
	int minX=1,minY=1;
	int peopleSkip[MAX_HEADCOUNT+1]={0};

	while(1)
	{
		int min=g_headcount;
		for(i=1;i<=g_headcount-1;i++)//�ҳ���С��ʧ
		{
			if(peopleSkip[i]==1)continue;
			for(j=i+1;j<=g_headcount;j++)
			{
				if (peopleSkip[j]==1)continue;
				if(g_Relation[i][j])
				{
					if(min>acquaintanceNum(i,peopleSkip)+acquaintanceNum(j,peopleSkip)-2)
					{
						minX=i;
						minY=j;
						min=acquaintanceNum(i,peopleSkip)+acquaintanceNum(j,peopleSkip)-2;
					}
				}
			}
		}
		if(min==g_headcount)return k;
		room[k][0]=minX;
		room[k][1]=minY;
		k++;
		peopleSkip[minX]=1;
		peopleSkip[minY]=1;
	}
	return 0;
}


int main()
{
	int i = 0,j = 0;										//ѭ���ۼӱ���
	int newGroup[2][MAX_HEADCOUNT+1]={{0},{0}};				//������
	int room[MAX_HEADCOUNT][2]={0};							//���������
	FILE *out_fp;											//����ļ�

	printf("***********************************************************\n");
	printf("*       �� �� �������ʻ���������.c                      *\n");
	printf("*       ��    �ߣ����D 	  2012118064    12����2��       *\n");
	printf("*       ����ʱ�䣺2013��02��16��                          *\n");
	printf("*       ��Ҫ���ܣ���Ҫ���ܣ��λ�������𡢷������      *\n");
	printf("***********************************************************\n");
	printf("\n");
	
	switch (ui_Select(3,"ѡ���������뷽ʽ��\n1.��������\n2.�����ļ�\n3.����������ڲ���(����������ݺ�ʱ�޴�����)\n"))
	{
	case 1:
		informationInput();					//����������Ϣ�����ɼ�������ʽ�������ظ����룬������ѭ��ֱ����ȷΪֹ
		break;
	case 2:
		if(informationFromFile())			//�ļ�������Ϣ�������򷵻�1��ֱ�ӽ���main()
		{
			printf("\n������������Զ��˳�...\n");
			_sleep(2000);
			return 1;										
		}
		break;
	case 3:
		randomDataGenerator();
		break;
	default:
		break;
	}

	if((out_fp=fopen(OUTPUT_FILENAME,"w"))==NULL)									//�� OUTPUT_FILENAME �ļ���δ�ҵ�����ʾ����
    {
		printf("û���ļ�����Ȩ��%s!\n",OUTPUT_FILENAME);
        return 1;
    }
	fprintf(out_fp,"%s","____ ԭʼ���� ____\n\n");
	fprintf(out_fp,"%s%d%s%d","������������",g_headcount,"\n��ϵ�ܶ�����",g_RelationCount);
	fprintf(out_fp,"%s","\n�����ϵ��\n");											//���������ʶ��ϵ
	for(i=1;i<=g_headcount-1;i++)
		for(j=i;j<=g_headcount;j++)
			if(g_Relation[i][j]==1)
				fprintf(out_fp,"%3d -%3d\n",i,j);;;;

	printf("\n____ ������ ____\n\n");
	fprintf(out_fp,"\n____ ������ ____\n\n");

	if( grouping(newGroup) )
	{
		printf("���ֳܷ����飬���ڳ�Ա������ʶ�������޷����㣡\n\n");		//������ֳɻ�����ʶ������,�ɷ��������newGroup[][]������������������Ϣ
		fprintf(out_fp,"���ֳܷ����飬���ڳ�Ա������ʶ�������޷����㣡\n\n");
	}
	else
	{
		printf("���飺\n��һ�飺");
		fprintf(out_fp,"���飺\n��һ�飺");
		for(i=1;i<=g_headcount&&newGroup[0][i]!=0;i++)
		{
			printf("%d ",newGroup[0][i]);
			fprintf(out_fp,"%d ",newGroup[0][i]);
		}
		printf("\n�ڶ��飺");
		fprintf(out_fp,"\n�ڶ��飺");
		for(i=1;i<=g_headcount&&newGroup[1][i]!=0;i++)
		{
			printf("%d ",newGroup[1][i]);
			fprintf(out_fp,"%d ",newGroup[1][i]);
		}
		printf("\n\n");
		fprintf(out_fp,"\n\n");
	}

	if(allotRoom(room)==0)//̰�ķ����価���ܶ�ķ��䣬ʹͬһ��������໥��ʶ���������room[][]
	{
		printf("û�д����໥��ʶ��δ�����κη��䣡\n\n");
		fprintf(out_fp,"û�д����໥��ʶ��δ�����κη��䣡\n\n");
	}
	else
	{
		printf("������������\n");
		fprintf(out_fp,"������������\n");
		for(i=0;i<g_headcount&&room[i][0]!=0;i++)
		{
			printf("%3d  -%3d\n",room[i][0],room[i][1]);
			fprintf(out_fp,"%3d  -%3d\n",room[i][0],room[i][1]);
		}
		printf("������%d����������ͬһ��������໥��ʶ��\n\n",i);
		fprintf(out_fp,"������%d����������ͬһ��������໥��ʶ��\n\n",i);
	}
	fclose(out_fp);

	system("pause");
	return 0;
}