/*************************************
*Modified by Gizem Gezici
*Date: 05.03.2012
*Modified by Gizem Gezici on 13.03.2012 (Bug fix on addToEnd member function)
*************************************/

#include <iostream>
#include "linkedList.h"

using namespace std;

linkedlist::linkedlist()
{
	head = nullptr;
}

//TODO: implement the following function 
//If the list is empty print  "List is empty"
//Otherwise print each node's content to a different line
void linkedlist::printList()
{	
	node *temp = head;
	if(!head)
		cout << "List is empty" << endl;

	while(temp)
	{
		
		cout << temp->data << endl;
		temp = temp->next;
	}
	delete temp;
}

void linkedlist::addToEnd(string n)
{
	node *ptr = head;
	node *temp = new node(n, nullptr);
	//List is empty
	if(head == nullptr)
	{
		head = temp;
	}
	else
	{
		while(ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void linkedlist::addToBeginning(string n)
{
	//List is empty
	if(head == nullptr)
	{
		node *ptr = new node(n, nullptr);
		head = ptr;
		head->next = nullptr;
	}
	else
	{
		node *ptr = new node(n, head);
		head = ptr;
	}
}

/*
Delete Function could be implemented here.
*/


void linkedlist::deleteList()
{
	node *temp = head;
	while(temp)
	{
		temp ->next;
	}

}


void linkedlist::printListInverse()
{
	if(head != NULL)
	{
		printListInverse(head);
	}
}

void linkedlist::printListInverse(node *n)
{
	if(n->next != NULL)
	{
		printListInverse(n->next);
	}
	cout << n->data << endl;
}
