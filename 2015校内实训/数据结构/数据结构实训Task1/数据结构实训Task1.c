#include <stdio.h>
#include <stdlib.h>
/***
* ���D 2012118064
**/

/***
* ����ʵ��
**/
typedef struct Node{
	char data;
	struct Node* next;
}Node, *LinkList;
void initList(LinkList *L){
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}

//void append(LinkList ){}

/***
* ������������
* ������
* 	L����
* 	raw�ַ�����ʾ��ԭ���ݣ�
* 	tail����β��������ڼ����ڵ㣬-1��ʾ���գ�����ɻ���
**/
void createData(LinkList L, char* raw, int tail){
	int i;
	Node* p = L;
	Node* q = NULL;
	for (i = 0; raw[i] != '\0'; i++){
		p->next = (Node*)malloc(sizeof(Node));
		p = p->next;
		p->data = raw[i];
		p->next = NULL;
		if (tail == i)q = p;
	}
	if (q != NULL){
		p->next = q;
	}
}
/***
*��ӡ����(���棺��������л������ô�ӡ��ȥ)
**/
void printList(LinkList L){
	Node* p = L->next;
	while (1){
		if (p == NULL)break;
		putchar(p->data);
		p = p->next;
	}
	printf("-");
}

/***
* �жϻ��Ĵ��ڣ�������ʦ�����ķ�����
* �ռ临�Ӷ�o(n)��ʱ�临�Ӷ�o(1)
**/
int isring(LinkList L){
	Node* a;
	Node* b;
	int i, flag = 0;
	a = L->next;
	b = L->next;
	for (i = 0; 1; i++){
		if (a == NULL || b == NULL)break;
		a = a->next;
		if (i % 2 != 0)b = b->next;
		if (a == b){ flag = 1; break; }
	}
	return flag;
}

int main(int argc, char const *argv[])
{
	LinkList L = NULL;
	initList(&L);
	createData(L, "abcdeasdfgjkldfgi", 10);

	if (!isring(L))
		printList(L);
	printf("%d", isring(L));
	return 0;
}


