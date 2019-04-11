#include <stdio.h>
#include <stdlib.h>
/***
 * 获取倒数位数据
 * hrmthw
 * 2015-05-21
 **/
typedef char datatype;

/***
 * 链表实现
 **/
typedef struct Node{
	datatype data;
	struct Node* next;
}Node,*LinkList;
void initList(LinkList *L){
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
}

void append(LinkList L,datatype data){
	Node* tail=L;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	tail->next=(Node*)malloc(sizeof(Node));
	tail->next->data=data;
	tail->next->next=NULL;
}

/***
 * 创建测试数据
 * 参数：
 * 	L链表；
 * 	raw字符串表示的原数据；
 * 	tail链表尾接在自身第几个节点，-1表示留空，否则成环。
 **/
void createData(LinkList L,datatype raw[],int tail){	
	int i;
	Node* p=L;
	Node* q=NULL;
	for (i=0;raw[i]!='\0';i++){
		p->next=(Node*)malloc(sizeof(Node));
		p=p->next;
		p->data=raw[i];
		p->next=NULL;
		if(tail==i)q=p;
	}
	p->next=q;
}

/***
 *打印链表(警告：不防止链表有环)
 **/
void printList(LinkList L,char* format){
	Node* p=L->next;
	while(1){
		if(p==NULL)break;
		printf(format,p->data);
		p=p->next;
	}
	printf("\n");
}

/***
 * 合并两个链表
 * */
LinkList combine(LinkList a1,LinkList a2){
	LinkList ans;
	Node* t1=a1->next;
	Node* t2=a2->next;
	initList(&ans);
	while(t1!=NULL||t2!=NULL){
		if(t1==NULL){append(ans,t2->data);t2=t2->next;continue;}
		if(t2==NULL){append(ans,t1->data);t1=t1->next;continue;}
		if(t1->data > t2->data){append(ans,t2->data);t2=t2->next;continue;}
		append(ans,t1->data);t1=t1->next;continue;
	}
	return ans;
}

/***
 * 获取数组长度（警告：不防止链表有环）
**/
int length(LinkList l){
	int i;
	Node* p=l->next;
	for(i=0;p!=NULL;i++){p=p->next;}
	return i;
}

/***
 * 输出倒数第k位，若k<=0，输出末位。
 **/
void findRight(LinkList l,int k){
	Node *fast=l->next,*slow=l;
	int i;
	for (i = 0;fast!=NULL; i++){
		fast=fast->next;
		if (i>=k-1) slow=slow->next;
	}
	if (slow==l){
		printf("index error!");
	}else{
		printf("%c",slow->data);
	}
}

int main(int argc, char const *argv[])
{
	LinkList list;
	char in[100];
	int index;
	
	initList(&list);
	printf("请输入字符串：");
	scanf("%s",in);
	createData(list,in,-1);
//	printList(list,"%c");
	printf("请输入倒数数字：");
	scanf("%d",&index);

	findRight(list,index);

	return 0;
}
