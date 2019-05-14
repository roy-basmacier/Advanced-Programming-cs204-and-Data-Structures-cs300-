#include <iostream>
#include <string>
#include "linkedListTemplate.h"
using namespace std;

//default constructor
template <class itemType>
LinkedList<itemType>::LinkedList ()
{
	head = NULL;
	size = 0;
}

//Copy constructor for shallow copy.
//You may either have this of deep copy version below.
//You may also delete both and the definition in class definition
//to see the default copy constructor works exactly as this shallow one.
/*template <class itemType>
LinkedList<itemType>::LinkedList (const LinkedList<itemType> & copy)
{
	head = copy.head;
	size = copy.size;
}*/


//Copy constructor for deep copy
template <class itemType>
LinkedList<itemType>::LinkedList (const LinkedList<itemType> & copy)
{
	head = copy.createClone();
	size = copy.size;
}

//destructor function visits all nodes and returns to heap
//TODO:: complete the first two lines of the descructor definition 
//template...
//........
template <class itemType>
LinkedList<itemType>::~LinkedList()
{
    node<itemType> * ptr = head;
    while (ptr != NULL) 
	{
		node<itemType> * temp = ptr->next;
		delete ptr;
		ptr = temp;
	}
}

template <class itemType>
void LinkedList<itemType>::addToBeginning (itemType n)
{
	node<itemType> *ptr = new node<itemType>(n,head);
    head = ptr;	
	size++;
}	

template <class itemType>
void LinkedList<itemType>::printList () const
{
	node<itemType> * ptr = head;
    while (ptr != NULL) 
	{
		cout << ptr ->info << endl;
		ptr = ptr->next;
	}
	cout << endl;
}

template <class itemType>
void LinkedList<itemType>::deleteList ()
{
	node<itemType> * ptr = head;
    while (ptr != NULL) 
	{
		node<itemType> * temp = ptr->next;
		delete ptr;
		ptr = temp;
	}
	head = NULL;
	size = 0;
}

template <class itemType>
const LinkedList<itemType> & LinkedList<itemType>::operator = (const LinkedList<itemType> & rhs)
{
	if (this != &rhs)
	{
		deleteList(); // same as this->deleteList()
		head = rhs.createClone();
		size = rhs.size;
	}
	return *this;
}


//generates a clone of the linked list object by generating new copies of
//each node and connecting them as in the original.
//Returns the head of the clone list.
template <class itemType>
node<itemType> * LinkedList<itemType>::createClone () const
{
	if (head == NULL)  //if list is empty
		return NULL;   //clone is empty as well
	
	//first generate the first clone node and connect to head of clone
	//TODO::dynamically allocate a node and store it with a pointer named headClone
	node<itemType> * headClone = new node<itemType>(head->info, head->next);
	node<itemType> * ptr = head->next;  //second node in orig.
	node<itemType> * ptrClone = headClone; //to track the clone list
    while (ptr != NULL) 
	{
		ptrClone->next = new node<itemType> (ptr->info, NULL);
		ptr = ptr->next;
		ptrClone = ptrClone->next;
	}
	return headClone;
}
