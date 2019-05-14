#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "Queue.h"
#include <iostream>
using namespace std;

template<class T>
Queue<T>::Queue() : front(nullptr), end(nullptr) {}

template<class T>
void Queue<T>::enqueue(T obj)
{
	queueNode<T> *nnode = new queueNode<T>(obj);
	if(isEmpty())
	{
		front = nnode;
		end = front;
	}
	else
	{
		end->next = nnode;
		end = end->next;
	}
}

template<class T>
void Queue<T>::dequeue(T &obj)
{
	queueNode<T> *tmp = front;
	obj = tmp->data;
	if(!isEmpty())
	{
		front = front->next;
		//delete tmp;
	}
}

template<class T>
bool Queue<T>::isEmpty()
{
	if(front)
		return false;
	return true;
}

template<class T>
void Queue<T>::clear()
{
	queueNode<T> _;
	while(front != end)
	{
		dequeue(_);
	}

}
#endif