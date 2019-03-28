#include<stdlib.h>
#include<stdio.h>
#ifndef null
#define null 0
#endif
#ifndef ElemType
#define ElemType int
#endif

typedef struct Node{
	ElemType data;
	struct Node * next;
}Node,*ChainList;

ChainList createList(){
	ChainList head;	
	head=(Node*)malloc(sizeof(Node));
	head->next=null;
	return head;
}


Node* scanList(ChainList p,int num){
	int i;
	Node* tmp=p;
	for(i=1;i<=num;i++){
		if(tmp->next==null)break;
		tmp=tmp->next;
	}
	return tmp;
}

int getListLength(ChainList p){
	int i;
	Node* tmp=p;
	for(i=0;tmp->next!=null;i++)
		tmp=tmp->next;
	return i;
}

void addNode(ChainList p,ElemType data){
	Node* tmp=p,*newNode;
	while(1){
		if(tmp->next==null)break;
		tmp=tmp->next;
	}
	newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=null;
	tmp->next=newNode;
}

int getData(ChainList p,int num){
	Node* tmp=scanList(p,num);
	return tmp->data;
}

int setData(ChainList p,int num,int data){
	Node* tmp=scanList(p,num);
	tmp->data=data;
	return 0;
}

int insertNode(ChainList p,int num,int data){
	
	Node* tmp=scanList(p,num-1);
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=tmp->next;
	tmp->next=newNode;
	return 0;
}

int delNode(ChainList p,int num){
	Node* deltmp;
	Node* tmp=scanList(p,num-1);
	deltmp=tmp->next;
	tmp->next=tmp->next->next;
	free(deltmp);
	return 0;
}

int main(){

	ChainList List1;
	int i;
	List1=createList();
	addNode(List1,3);
	addNode(List1,3);
	addNode(List1,4);
	addNode(List1,3);
	insertNode(List1,1,5);	
	delNode(List1,4);
	
	for(i=1;i<=getListLength(List1);i++)
		printf("%d\n",getData(List1,i));
	system("pause");
	return 0;
}