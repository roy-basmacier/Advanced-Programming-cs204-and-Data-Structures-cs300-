#include <iostream>
#include "linkedList.h"

using namespace std;

//creating an empty linkedlist
linkedlist::linkedlist()
{
	head = nullptr;
}

//printing the elements of the list
void linkedlist::printList()
{
	
	cout << head->data << endl;
	node * ptr = head->next;
	while(ptr != head)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
	}
}

//adds an element to the beginning of the list
void linkedlist::addToBeginning(string n)
{
	if(head == nullptr)
	{
		head = new node(n, head);
		head->next = head;
	}
	else
	{
        node *temp = new node(n,head);
		node *temp2 = head;
		while (temp2->next != head)
		{
			temp2 = temp2->next;
		}
		temp->next = temp;

	}
}

/*
 Implement the delete function by yourself
*/

//printing the list elements in the reverse order
void linkedlist::printListInverse()
{
	printListInverse(head);
}

void linkedlist::printListInverse(node *n)
{
	if(n->next != head)
	{
		printListInverse(n->next);
	}
	cout << n->data << endl;
}