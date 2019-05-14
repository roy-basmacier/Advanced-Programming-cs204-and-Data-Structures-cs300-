#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() : front(nullptr), end(nullptr) {}

void Queue::addToBeg(string tag)
{
	if (end->lectures == nullptr)
	{
		end->lectures = new node(tag);
	}
	else
	{
		node *tmp = end->lectures;
		end->lectures = new node(tag);
		end->lectures->next = tmp;
	}

}

void Queue::addToBeg(int num)
{
	if (front->lectures == nullptr)
	{
		front->lectures = new node("", num);
	}
	else
	{
		node *tmp = front->lectures;
		front->lectures = new node("", num);
		front->lectures->next = tmp;
	}

}

void Queue::enqueue(queueNode *stu)
{
	if(isEmpty())
	{
		front = stu;
		end = front;
	}
	else
	{
		end->next = stu;
		end = end->next;
		//end->next = nullptr;
	}

}

void Queue::dequeue(queueNode *& stu)
{
	queueNode *tmp = front;
	stu = tmp;
	if(!isEmpty())
	{
		front = front->next;
		//delete tmp;
	}
}

bool Queue::isEmpty() const
{
	if(front)
		return false;
	return true;
}

void Queue::clear()
{
	queueNode _;
	queueNode *tmp = front;
	while(front != end)
	{
		//dequeue(_);
	}

}
