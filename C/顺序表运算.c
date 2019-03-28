#define MAXSIZE 100
typedef struct
{
	ElemType elem[MAXSIZE];
	int      last;//��¼���Ա����һ��Ԫ��������elem�����е�λ�ã��ʴ˴�Ϊʲô��һƬ�ط�
}Seqlist��
/*˳���Ĳ�������*/
int locate(Seqlist L,ElemType e)
/*��˳����в�����e��ȵ�Ԫ�أ���L.elem[i]=e,���ҵ���Ԫ�أ�������i+1(����ǰ�������е�λ�ã��Ҳ����򷵻�-1)*/
{   i=0;//�˴�����int�Ƿ�ᱨ��
	while((i<=L.last)&&(L.elem[i]!=e))//˳��ɨ���ֱ��ɨ�赽ֵΪһ��Ԫ�أ���ɨ�赽��βδ�ҵ�Ԫ��
		i++;
	if(i<=L.last)
		return(i+1);
	else
		return(-1);
}

/*˳���Ĳ�������*/
#define OK 1
#define ERROR 0
int InsList(SeqList*L,int i,ElemType e)
/*��˳���Ldii��Ԫ��ǰ����һ��Ԫ��e*/
{
	int k��
	if((i<1)||(i>L->last+2)) //����������жϲ���λ���Ƿ�Ϸ�
	{printf("����λ��i���Ϸ�")��
	return ERROR��
	}
	if(L->last>=MAXSIZE-1)//֮���Լ�һ����Ϊ����a[10]ʵ������a[0]��a[9]�����һ���Ǻ�Ϊ9
	{printf("���������޷����룡");
	return ERROR;
	}
	/*�ų����ִ������֮�󣬱�ʾ����λ�úϷ���ִ�н������Ĳ������*/
	for(k=L->last;k>=i-1;k--) /*Ϊ����Ԫ�ض��ƶ�λ��*/
		L->elem[k+1]=L->elem[k];
	L->elem[i-1]=e;//c�����������i��Ԫ���±�Ϊi-1������μ��α�42ҳʾ��ͼ
	L->last++;	//��βָ���ڲ�������󳤶ȵ�ǰ�������ָһλ
	return OK;	
}

/*˳���ɾ���������˲���������൱����һ�������*/
/*����ɾ����5��Ԫ�أ���6λ�Ժ������ȫ��ǰ��*/
int DelList(SeqList *L,int i,ElemType e){//�������β�������÷ֱ���ʲô
	/*��˳���L��ɾ��iԪ�أ�����ָ�����e������ֵ*/
	int k��
	if((i<1)||(i>L->last+1))//��˳�������ɾ���������ʲ�Ӧ����˳���ʵ�ʳ���
	{printf("ɾ��λ�ò��Ϸ���");
	return ERROR��
	}
	*e=L->elem[i-1];//��ɾ����Ԫ�طŵ�e��ָʾָ������У���Ϊ��C�����У���n��Ԫ�����±�Ϊn-1
	for(k=i;i<=L->last;k++)
		L->elem[k-1]=L->[k];//����ǰ�ƺ����Ԫ��
	L->last--//���ʵ�ʳ��ȼ�һ
	return OK��
}