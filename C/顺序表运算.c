#define MAXSIZE 100
typedef struct
{
	ElemType elem[MAXSIZE];
	int      last;//记录线性表最后一个元素在数组elem【】中的位置，问此处为什么空一片地方
}Seqlist；
/*顺序表的查找运算*/
int locate(Seqlist L,ElemType e)
/*在顺序表中查找与e相等的元素，若L.elem[i]=e,则找到该元素，并返回i+1(即当前在数组中的位置，找不到则返回-1)*/
{   i=0;//此处不加int是否会报错
	while((i<=L.last)&&(L.elem[i]!=e))//顺序扫描表，直到扫描到值为一的元素，或扫描到表尾未找到元素
		i++;
	if(i<=L.last)
		return(i+1);
	else
		return(-1);
}

/*顺序表的插入运算*/
#define OK 1
#define ERROR 0
int InsList(SeqList*L,int i,ElemType e)
/*在顺序变Ldii个元素前插入一个元素e*/
{
	int k；
	if((i<1)||(i>L->last+2)) //此语句用来判断插入位置是否合法
	{printf("插入位置i不合法")；
	return ERROR；
	}
	if(L->last>=MAXSIZE-1)//之所以减一是因为数组a[10]实际上是a[0]到a[9]，最后一个角号为9
	{printf("表已满，无法插入！");
	return ERROR;
	}
	/*排除两种错误情况之后，表示插入位置合法，执行接下来的插入语句*/
	for(k=L->last;k>=i-1;k--) /*为插入元素而移动位置*/
		L->elem[k+1]=L->elem[k];
	L->elem[i-1]=e;//c语言中数组第i个元素下标为i-1，详情参见课本42页示意图
	L->last++;	//表尾指针在不超过最大长度的前提下向后指一位
	return OK;	
}

/*顺序表删除操作，此操作与插入相当于是一个逆过程*/
/*如需删除第5个元素，把6位以后的数据全部前移*/
int DelList(SeqList *L,int i,ElemType e){//此三个形参起的作用分别是什么
	/*在顺序表L中删除i元素，并用指针参数e返回其值*/
	int k；
	if((i<1)||(i>L->last+1))//在顺序表内做删除操作，故不应大于顺序表实际长度
	{printf("删除位置不合法！");
	return ERROR；
	}
	*e=L->elem[i-1];//将删除的元素放到e所指示指针变量中，因为在C语言中，第n个元素其下标为n-1
	for(k=i;i<=L->last;k++)
		L->elem[k-1]=L->[k];//依次前移后面的元素
	L->last--//表的实际长度减一
	return OK；
}