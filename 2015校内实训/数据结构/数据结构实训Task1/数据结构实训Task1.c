#include <stdio.h>
#include <stdlib.h>
/***
* 蒋镈 2012118064
**/

/***
* 链表实现
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
* 创建测试数据
* 参数：
* 	L链表；
* 	raw字符串表示的原数据；
* 	tail链表尾接在自身第几个节点，-1表示留空，否则成环。
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
*打印链表(警告：如果链表有环会永久打印下去)
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
* 判断环的存在，利用老师给出的方法。
* 空间复杂度o(n)，时间复杂度o(1)
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


