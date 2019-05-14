#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;

template<class T>
struct queueNode
{
	T data;
	queueNode<T> *next;

	queueNode(T d, queueNode<T>* ptr = nullptr) : data(d), next(ptr) {}
};


template<class T>
class Queue
{
public:
	Queue();
	void enqueue(T);
	void dequeue(T&);
	void clear();
	bool isEmpty();

private:
	queueNode<T>* front;
	queueNode<T>* end;
};

#include "Queue.cpp"
#endif