//Modified by Gizem Gezici
//Modified Date: 21.03.2012
#include <iostream>
#include "DynIntQueue.h"
using namespace std;

//************************************************
// Constructor. Generates an empty queue         *
//************************************************
DynIntQueue::DynIntQueue()
{
	front = nullptr;
	rear = nullptr;   
	#ifdef _DEBUG
		cout << "An empty queue has been created\n";
	#endif
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
void DynIntQueue::enqueue(int num)
{       
	if (isEmpty())   //if the queue is empty
	{	//make it the first element
		front = new QueueNode(num);
		rear = front;
	}
	else  //if the queue is not empty
	{	//add it after rear
		rear->next = new QueueNode(num);
		rear = rear->next;
	} 
	#ifdef _DEBUG
		cout << num << " enqueued\n";
	#endif
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
void DynIntQueue::dequeue(int &num)
{
	QueueNode *temp;
	if (isEmpty())
	{
		cout << "Attempting to dequeue on empty queue, exiting program...\n";
		exit(1);
	}
	else //if the queue is not empty
	{	//return front's value, advance front and delete old front
		num = front->value;
		temp = front;
		front = front->next;
		delete temp;
	}
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
bool DynIntQueue::isEmpty() const
{
	if (front == nullptr)
		return true;
	else 
		return false;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************
void DynIntQueue::clear()
{
	int num;   // Dummy variable for dequeue

	while(!isEmpty())
		dequeue(num); //delete all elements
	#ifdef _DEBUG
		cout << "queue cleared\n";
	#endif
}
