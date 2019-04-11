#include <stdio.h>
#include <stdlib.h>
/***
 * 后缀
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
 * 找后缀
**/
int findSuffix(LinkList l1,LinkList l2){
	int margin=0;
	int i,j,flag=0;
	Node *p1=l1,*p2=l2,*sp1,*sp2;
	
	//对齐
	margin=length(l1)-length(l2);
	for(i=0;margin+flag!=0;i++){
		if(margin>0){p1=p1->next;flag--;}
		else{p2=p2->next;flag++;}
	}
	
	//遍历对比
	sp1=p1;
	sp2=p2;
	for(j=0;p1->next!=NULL;j++){
		if (p1->data!=p2->data){
			sp1=p1;
			sp2=p2;
			i++;
		}
		p1=p1->next;
		p2=p2->next;			
	}

	
	if (margin>0){
		printf("在前一个字符串中第%d位，后一个第%d位。\n",i,i-margin);
	}
	if (margin<0){
		printf("在前一个字符串中第%d位，后一个第%d位。\n",i+margin,i);
	}
	if(margin==0){
		printf("在前一个字符串中第%d位，后一个第%d位。\n",i+1,i+1);
	}
	
	printf("共同后缀：");
	sp2->next=sp1->next;
	printList(sp1,"%c");

	return 0;
}

int main(int argc, char const *argv[])
{
	LinkList a1,a2;
	char in1[100],in2[100];

	printf("请输入字符串1：");
	scanf("%s",in1);
	printf("请输入字符串2：");
	scanf("%s",in2);

	initList(&a1);
	initList(&a2);
	
	createData(a1,in1,-1);
	createData(a2,in2,-1);
	findSuffix(a1,a2);
	printf("修改连接后输出验证：\n");
	printList(a1,"%c");
	printList(a2,"%c");	
	return 0;
}
