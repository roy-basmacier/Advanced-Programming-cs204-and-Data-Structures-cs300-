#include <iostream>
using namespace std;

struct node 
{

	int value;
	node *next;

	node(int v = 0, node *nxt = nullptr) : value(v), next(nxt) {}

};
void Add2Beg(node **head, int val)
{
	node *tmp = new node(val);
	if(*head == nullptr)
		*head = tmp;
	else
	{
		tmp->next = *head;
		*head = tmp;
	}
}
void DeleteNode(node**head, int i)
{
	node *tmp = *head;
	node *prv = nullptr;
	while(tmp)
	{
		if(tmp->value == i)
			break;

		prv = tmp;
		tmp = tmp->next;
	}
	if (tmp == *head)
	{
		if (tmp)
		{
			if(tmp->next)
				*head = tmp->next;
			else
				*head = nullptr;
		}
	}
	else
	{
		if (tmp)
		{
			prv->next = tmp->next;
		}
	}


}

void print(node*head)
{
	cout << "PRINTING \n";
	while(head)
	{
		cout << head->value << endl;
		head = head->next;
	}

}

node**  merge(node *h1, node *h2)
{
	node *tmp1 = h1, *tmp2 = h2, *maxptr = tmp1, **ptp, *mergedList = nullptr;
	ptp = &mergedList;
	node **ptp1 = &h1;
	node **ptp2 = &h2;
	while(h1 != nullptr && h2 != nullptr)
	{
		tmp1 = h1;
		tmp2 = h2;
		while(tmp1)
		{
			cout << "max is " << maxptr->value << endl;
			if(maxptr->value < tmp1->value)
				maxptr = tmp1;
			tmp1 = tmp1->next;
		}
		while(tmp2)
		{
			cout << "max is l2 is "  << maxptr->value << endl;
			if(maxptr->value < tmp2->value)
				maxptr = tmp2;
			tmp2 = tmp2->next;
		}
		cout << "FINAL MAX " << maxptr->value << endl;
		Add2Beg(ptp, maxptr->value);
		DeleteNode(ptp1, maxptr->value);
		DeleteNode(ptp2, maxptr->value);


	}
	return ptp;
}

int main()
{
	node *list1 = nullptr, *list2 = nullptr, **list3 = nullptr;
	node **ptp1 = &list1;
	node **ptp2 = &list2;
	Add2Beg(ptp1, 99);
	Add2Beg(ptp1, 2);
	Add2Beg(ptp1, 1);
	print(list1);
	cout << "~~~~~~~\n";
	Add2Beg(ptp2, 101);
	Add2Beg(ptp2, 22);
	Add2Beg(ptp2, 11);
	print(list2);
	print(list1);
	print(list2);
	list3 = (merge(list1, list2));
	print(*list3);

	return 0;
}
