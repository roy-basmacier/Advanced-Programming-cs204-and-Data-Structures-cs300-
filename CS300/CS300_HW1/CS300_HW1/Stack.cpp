#include "Stack.h"
#ifndef STACK_CPP
#define STACK_CPP

/*	Roy Basmacier
	roy@sabanciuniv.edu
	24813
	 __          
	 )_) _       
	/ \ (_) (_(  
			  _) 
*/


//Default Constructor
template <class T>
Stack<T>::Stack() : top(nullptr) {}


//Destructor
template <class T>
Stack<T>::~Stack()
{
	T _;
	while(!isEmpty())
		pop(_);
}


template <class T>
void Stack<T>::push(T val) // adds val to the top of the stack
{
	stackNode<T> * tmp = new stackNode<T>(val);
	if (isEmpty())
		top = tmp;
	else
	{
		tmp->next = top;
		top = tmp;
	}

}

template <class T>
void Stack<T>::pushToBottom(T val) // adds val to the end (bottom) of the stack
{
	if (isEmpty())
	{
		push(val);
		return;
	}
	T x;
	pop(x);
	pushToBottom(val);
	push(x);
}


template <class T>
void Stack<T>::pop(T &val) // removes the top node of stack and references the value as val
{
	if (isEmpty())
		return;

	stackNode<T> * tmp = top;
	val = top->value;
	top = top->next;
	delete tmp;

}

template <class T>
void Stack<T>::reverse() // reverses the stack order
{
	if(isEmpty())
		return;
	T x;
	pop(x);
	reverse();
	pushToBottom(x);
}

template <class T>
void Stack<T>::remove(T del) // removes all del values from stack
{
	if(isEmpty())
		return;
	T x;
	pop(x);
	remove(del);
	if (x != del)
		push(x);
}

template <class T>
void Stack<T>::rprint() // prints stack in a reverse order
{
	if(isEmpty())
		return;
	T x;
	pop(x);	
	rprint();
	cout << x;
	push(x);
}

template <class T>
void Stack<T>::print() // prints stack
{
	if(isEmpty())
		return;
	T x;
	pop(x);
	cout << x;
	print();
	push(x);
}

template <class T>
bool Stack<T>::isEmpty() // checks if stack is empty
{
	if (top == nullptr)
		return true;
	return false;
}


//Pop and Push (lhs to rhs)
template <class T>
void Stack<T>::operator>>(Stack<T>* rhs) // pops from left hand stack and pushes it to rhs stack
{
	T x;
	pop(x);
	rhs->push(x);
}
#endif