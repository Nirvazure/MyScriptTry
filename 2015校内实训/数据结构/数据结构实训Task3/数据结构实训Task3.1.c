#include <stdio.h>
#include <stdlib.h>
/***
 * 合并两组有序数据并输出中位数（中位数定义为偏右一个）
 * 蒋镈 2012118064
 * 2015-05-21
 **/
typedef int datatype;

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
 *打印链表(警告：如果链表有环会永久打印下去)
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
 * 获取中位数 
 **/
datatype getMedian(LinkList L){
	Node* fast=L->next;
	Node* slow=L->next;
	int i;
	for(i=0;fast!=NULL;i++){
		fast=fast->next;
		if(i%2!=0)slow=slow->next;
	}
	return slow->data;
}

int main(int argc, char const *argv[])
{
	LinkList a1,a2,ans;
	int raw1[]={1,2,4,19,33,0};
	int raw2[]={3,7,11,12,13,14,17,0};
	
	initList(&a1);
	initList(&a2);
	
	createData(a1,raw1,-1);
	createData(a2,raw2,-1);

	ans=combine(a1,a2);
	
	printf("合并后：");
	printList(ans,"%d ");
	printf("中位数是：%d",getMedian(ans));
	
	return 0;
}
