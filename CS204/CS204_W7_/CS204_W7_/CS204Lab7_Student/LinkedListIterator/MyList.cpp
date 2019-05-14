/*
Modified by Gizem Gezici
Modified Date: 10.04.2012
Linked List Iterator

*/

#include "MyList.h"

//Default Constructor
MyList::MyList()
{
	head = nullptr;
	tail = nullptr;
	numItems = 0;
}

//Constructor
MyList::MyList(string* list,int num)
{
	head = nullptr;
	tail = nullptr;
	numItems = 0;
	for(int i=0; i < num; i++)
	{
		addToEnd(list[i]);
	}

}

//Implemented by Gizem Gezici
void MyList::addToEnd(string &newData)
{
	Node *ptr = head;
	//List is empty
	if(tail == nullptr)
	{
		tail = new Node (newData,nullptr,nullptr);
		head = tail;
	}
	else
	{
		Node *temp = new Node(newData, nullptr, tail);
		tail->next = temp;
		tail = temp;
	}
	numItems++;
}

//Implemented by Gizem Gezici
void MyList::addToBeginning(string &newData)
{
	//List is empty
	if(head == nullptr)
	{
		Node *ptr = new Node(newData, nullptr, nullptr);
		head = ptr;
		tail = head;	
	}
	else
	{
		Node *ptr = new Node(newData, head, nullptr);
		head->previous = ptr;
		head = ptr;
	}
}

int MyList::numberOfElements()
{
	return numItems;
}

MyListItr::MyListItr(const MyList &l): 
	list(l),current(l.head)
	{}

//Modified by Gizem Gezici
void MyListItr::next()
{
	if(current != nullptr)
	{
		current = current->next;
	}
}

//Modified by Gizem Gezici
void MyListItr::previous()
{
	//TODO: Implement this method
	if(current != nullptr)
	{
		current = current->previous;
	}
}

//Implemented by Gizem Gezici
bool MyListItr::hasMore()
{
	if(current != nullptr)
		return false;
	return true;
}

//Get the string data in the linked list node.
string MyListItr::getData()
{
	if(current != nullptr)
		return current->data;
	return NULL;
}

//Go to the beginning of the linked list.
void MyListItr::goToBeginning()
{
  //TODO: Set current appropriately
	current = list.head;
}

//Go to the end of the linked list.
void MyListItr::goToEnd()
{
  //TODO: Set current appropriately.
	current = list.tail;
}
