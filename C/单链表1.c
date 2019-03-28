#include<stdio.h>
#include<stdlib.h>

	typedef struct Node			/*结点类型定义*/
	{
		char data;
		struct Node *next;
	}Node,*LinkList;			/*LinkList用来定义头结点，增强程序可读性*/


//用头插法建链表
    void CreateFromHead(LinkList L){
		Node *s;
		char c;
		int flag = 1;		//这是一个控制参数，当输入“$”时，flag为0，建表结束
		while( flag ){
			c = getchar();
			if(c !='$'){
				s = (Node*)malloc(sizeof(Node));
//malloc函数是开辟一个空间，空间的具体大小就是()里的，可以是数值，sizeof的意思是计算Node所占空间的大小，***但是malloc所开辟出来的空间是一个地址空间，所以在前面要加一个（Node*）来强制转换成Node*类型（就是结点类型）
				s ->data = c;
				s ->next = L ->next;
				L ->next = s;
			}
			else flag = 0;
		}
}//这个函数不用返回值或者链表，因为在C中方法能返回参数但不能改变地址或者返回地址，而链表的头插和尾插都是以地址的形式进行的，所以不用返回照样生效

//尾插法建链表
	void CreateFromTail(LinkList L){
		Node *r=L,*s;
		int flag=1;					//这是一个控制参数，当输入“$”时，flag为0，建表结束
		char c;
		while(r->next!=NULL){			//r指针动态指向链表的当前表尾，以便于做尾插入，其初值指向头结点
			r=r->next;
		}
		while(flag){
			c=getchar();
			if(c!='$'){
				s=(Node*)malloc(sizeof(Node));
				s->data=c;
				r->next=s;
				r=s;
			}
			else{
				flag=0;
				r->next=NULL;	//将最后一个结点的next链域置为空，表示链表的结束
			}
		}
	}

//在任意位置插入某值
	int Create(LinkList L){
		int j=0,num1=0,flag=0;
		char letter1=0;			//letter1,num1都是参数，用来储存用户输入的信息，j是参数
		Node *p=L,*s;

		printf("请输入您要插入的位置（0代表表头处）\n");		//让用户输入所需要的信息
		scanf("%d",&num1);
		printf("请输入您要插入的字符\n");
		scanf("%c",&letter1);
		
		if(num1=0){			//判断插入位置是否是表头处
				s=(Node*)malloc(sizeof(Node));
				s->data=letter1;
				s->next=L->next;
				L->next=s;
				flag=1;
			}
		if(num1>0){	 //插入位置非表头处的数据插入
			while((p->next!=NULL)&&(j<num1)){
				p=p->next;
				j++;
			}
			if(num1==j){
				s=(Node*)malloc(sizeof(Node));
				s->data=letter1;
				s->next=p->next;
				p->next=s;
				flag=1;
			}
		}
		return flag;
	}

//查找某值
	void Locate(LinkList L){
		int num2=0;
		char key=0;
		Node* p=L->next;
		printf("请输入您要查找的字符数据");
		scanf("%c",&key);

		//从表中第一个结点开始查
		while(p!=NULL){			//当前表未查完
			if(p->data!=key){
				p=p->next;
				num2++;
			}
			else {
				num2++;
				break;
			}			//找到结点值=key是退出循环，num2++是为了使未找到和第一次就找到了的结果区分开来
		}
		if(num2!=0)printf("您所找的数据的位置是%d",num2);
		else printf("未找到您所要找的数据");
	}

//读取某处的值
	void Get(LinkList L){
		int num3=0,j=0;
		Node *p=L;

		do{
		printf("请输入您要读取的数据的位置（位置的值大于0）");
		scanf("%d",&num3);
		}while(num3<=0);			//确保得到的位置大于0
		
		while((p->next!=NULL)&&(j<num3)){		//从头结点开始扫描
			p=p->next;
			j++;								//已扫描结点的计数器
		}
		if(num3==j)printf("您要找的数据为%c",p->data);		//找到地num3个结点
		else printf("未找到您要找的数据");					//找不到结点，位置的值大于链表长度
	}

//修改某处的值
	void Changedata(LinkList L){
		int num4=0,j=0;
		char letter2;
		Node *p=L;

		do{
		printf("请输入您要修改的数据的位置（位置的值大于0）");
		scanf("%d",&num4);
		}while(num4<=0);			//确保得到的位置大于0

		while((p->next!=NULL)&&(j<num4)){		//从头结点开始扫描
			p=p->next;
			j++;								//已扫描结点的计数器
		}
		if(num4==j){
			printf("请输入你要修改的值");
			scanf("%c",&letter2);
			p->data=letter2;
			printf("修改成功");
		}
		else printf("未找到您要修改的数据");					//找不到结点，位置的值大于链表长度
	}

//删除某处的值
	void Deletedata(LinkList L){
		Node *p=L,*r;
		int k=0,num5;
		
		do{
		printf("请输入您要修改的数据的位置（位置的值大于0）");
		scanf("%d",&num5);
		}while(num5<=0);			//确保得到的位置大于0

		while(p->next!=NULL&&k<num5-1){		//寻找被删除结点num4的前驱结点num5 - 1使p指向它
			p=p->next;
			k++;
		}									//查找第num5 - 1个结点
		if(!(p->next)){				//while循环是因为p->next=NULL或i<1而跳出去的，因为p->next为空，没有找到合法的前驱位置，说明删除位置num5不合法
			printf("删除节点的位置不合理！");
		}
		else{
			r=p->next;
			p->next=r->next;			//修改指针，删除结点
			free(r);
			printf("删除成功");
		}					//释放被删除的结点所占用的内存空间
	}

//求链表的长度
	int ListLength(LinkList L){
		Node *p=L->next;
		int j=0;
		while(p!=NULL){
			p=p->next;
			j++;
		}
		return j;		//j为链表的长度
	}

//按顺序输出链表
	void output(LinkList L){
		Node *p=L;
		while (p ->next != NULL){
            p = p ->next;
			printf("%c",p ->data);
		}
		printf("\n");
	}

	
	
	
	void main(){
		char letter=0,letter1=0;
		int num1=0;
		LinkList L;
		L=(LinkList)malloc(sizeof(Node));
		L->next=NULL;

//用循环结构不断重复，选择需要的功能
		do{
			printf("函数编号:\n\tA.用头插法建链表\n\tB.用尾插法建链表\n\tC.在任意位置插入某值(0代表表头处)\n\tD.查找某值\n\tE.读取某处的值\n\tF.修改某值\n\tG.删除某处的值\n\tH.求链表的长度\n\tI.输出链表\n\tJ.退出程序\n");
			printf("请输入您需要进行的函数的编号\n");
			scanf("%c",&letter);
			while( (letter<'A') || (letter>'J'&&letter<'a') || (letter>'j') ){
			printf("请重新输入\n");
			scanf("%c",&letter);
			}

			if(letter=='a'||letter=='A'){
				printf("请输入您的字符数据，并以'$'符号结尾\n");
				CreateFromHead(L);
				printf("插入成功");
			}

			if(letter=='b'||letter=='B'){
				printf("请输入您的字符数据，并以'$'符号结尾\n");
				CreateFromTail(L);
				printf("插入成功");
			}

			if(letter=='c'||letter=='C'){
				while(Create(L)==0){
					printf("您输入的信息有误，请重新输入\n\n");
				}
				printf("插入成功");
			}

			if(letter=='d'||letter=='D'){
				Locate(L);
			}

			if(letter=='e'||letter=='E'){
				Get(L);
			}

			if(letter=='f'||letter=='F'){
				Changedata(L);
			}

			if(letter=='g'||letter=='G'){
				Deletedata(L);
			}

			if(letter=='h'||letter=='H'){
				printf("链表长度为%d",ListLength(L));
			}
			
			if(letter=='i'||letter=='I'){
				output(L);
			}
			printf("\n\n\n");
		}while((letter!='j')&&(letter!='J'));
		
	}
