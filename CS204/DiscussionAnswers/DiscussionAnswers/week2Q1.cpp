#include <iostream>
using namespace std;

struct node 
{

	int value;
	node *next;

	node(int v = 0, node *nxt = nullptr) : value(v), next(nxt) {}

};

node* Add2Beg(node *head, int val)
{
	node *tmp = new node(val);
	if(head == nullptr)
		head = tmp;
	else
	{
		tmp->next = head;
		head = tmp;
	}
	return head;
}

