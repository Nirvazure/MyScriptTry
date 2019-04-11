#include <iostream>
#include <string>

using namespace std;
//code by Õı¿Ë≥«
class Node
{
	public:
		char data;
		Node *next;

		Node() : data(0) , next(NULL) {}
		Node(char ch) : data(ch) , next(NULL) {}
};

void initList(Node *str1 , Node *str2);
Node *found(Node *str1 , Node *str2);

int main()
{
	Node *str1 = new Node();
	Node *str2 = new Node();
	Node *UnionBegin = NULL;

	initList(str1 , str2);
	UnionBegin = found(str1 , str2);

	if (UnionBegin)
		cout << UnionBegin->data << endl;
	else
		cout << "not found" << endl;

	return 0;
}

void initList(Node *str1 , Node *str2)
{
	str2->next = new Node('b');
	str2->next = new Node('e');

	str1->next = new Node('l');
	str1->next->next = new Node('o');
	str1->next->next->next = new Node('a');
	str1->next->next->next->next = new Node('d');
	str1->next->next->next->next->next = new Node('i');

	str2->next = str1->next->next->next->next->next;

	str1->next->next->next->next->next->next = new Node('n');
	str1->next->next->next->next->next->next->next = new Node('g');

	return ;
}

Node *found(Node *str1 , Node *str2)
{
	Node *p1 = str1->next;
	Node *p2 = str2->next;
	Node *index = NULL;

	while(1)
	{
		if (!p1)
		{
			index = str2->next;

			while(p2)
			{
				p2 = p2->next;
				index = index->next;
			}

			p2 = index;
			p1 = str1->next;

			break;
		}

		if(!p2)
		{
			index = str1->next;

			while(p1)
			{
				p1 = p1->next;
				index = index->next;
			}

			p1 = index;
			p2 = str2->next;

			break;
		}

		p1 = p1->next;
		p2 = p2->next;
	}

	while(p1 && p2)
		if (p1 == p2)
			return p1;
		else
		{
			p1 = p1->next;
			p2 = p2->next;
		}

	return NULL;
}