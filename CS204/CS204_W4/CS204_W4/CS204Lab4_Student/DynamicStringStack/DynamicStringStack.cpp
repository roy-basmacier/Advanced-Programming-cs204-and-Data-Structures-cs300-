/*
Modified by Gizem Gezici
Date: 13.03.2012
Print member function was added
The name of the public clear function was modified
(in order to prevent function overloading)
*/


#include <iostream>
#include "DynamicStringStack.h"
using namespace std;

//Constructor
DynamicStringStack::DynamicStringStack()
{
	top=nullptr;
}

StackNode* DynamicStringStack::GetTopPointer(DynamicStringStack myStack)
{
	return myStack.top;
}

//Push back elements to the stack
void DynamicStringStack::push(string elmt)
{
	StackNode *newNode;

	newNode = new StackNode;
	newNode->value = elmt;

	if(isEmpty())
	{
		top = newNode;
		top->next = nullptr;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}
//Pop up elements from the stack
void DynamicStringStack::pop(string &elmt)
{
	StackNode *temp;

	if(isEmpty())
	{
		cout<<"Stack is empty!\n";
	}

	else 
	{
		elmt = top->value;
		temp = top;
		top = top->next;
		delete temp;
	}
}

//If the stack is empty check function
bool DynamicStringStack::isEmpty()
{
	bool status;

	if(top==nullptr)
		status=true;

	else 
		status=false;

	return status;
}
