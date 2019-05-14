/*
Author: Gizem Gezici
Date: 21.03.2012
Queue Zipper Example
*/

#include <iostream>
#include "DynIntQueue.h"
using namespace std;

void FillTheQueue(DynIntQueue & myQueue, DynIntQueue & queueZipper)
{
	int num = 0;
	myQueue.dequeue(num);
	queueZipper.enqueue(num);
}
int main()
{
	cout << "*******************************Beginning of the Program******************" << endl;
	cout << "Queues are being established..." << endl;
	cout << endl;
	DynIntQueue myOddQueue;
	DynIntQueue myEvenQueue;
	DynIntQueue myQueueZipper;

	//Odd numbered queue

	cout << "*******************************Odd Queue*********************************" << endl;
	cout << "Odd queue is being established..." << endl;
	cout << endl;
	for(int i=1; i<10; i=i+2)
	{
		myOddQueue.enqueue(i);
	}

	//Even numbered queue
	cout << "*******************************Even Queue*********************************" << endl;
	cout << "Even queue is being established..." << endl;
	cout << endl;
	for(int i=2; i<20; i=i+2)
	{
		myEvenQueue.enqueue(i);
	}

	//To store respectively from the odd and even queue to the zipper
	//until one of the queues become empty
	int num = 0;
	cout << "*******************************Zipper Queue*********************************" << endl;
	cout << "Zipper queue is being established..." << endl;
	cout << endl;
	while(!myOddQueue.isEmpty() && !myEvenQueue.isEmpty())
	{
		myOddQueue.dequeue(num);
		myQueueZipper.enqueue(num);
		myEvenQueue.dequeue(num);
		myQueueZipper.enqueue(num);
	}

	//To understand which queue became empty
	//And then continue to store the elements of non-empty queue
	while(!myOddQueue.isEmpty())
	{
		FillTheQueue(myOddQueue, myQueueZipper);
	}

	while(!myEvenQueue.isEmpty())
	{
		FillTheQueue(myEvenQueue, myQueueZipper);
	}

	cout << endl;
	//Display the zipper queue
	cout << "Zipper is being displayed..." << endl;
	cout << endl;
	int value = 0;
	while(!myQueueZipper.isEmpty())
	{
		myQueueZipper.dequeue(value);
		cout << value << " ";
	}
	system("pause");
	return 0;

}