#ifndef MINHEAP_H
#define MINHEAP_H

template<class T>
class MinHeap
{
public:
	MinHeap(T*, int);
	~MinHeap();
	T getMin();
	void deleteMin();
	void insert(T);
	void decreaseElements(int);
	bool isFull();
	bool isEmpty();
	
//private:
	void perculateDown(int);
	T *arr;
	int size; // current size
	int capacity;
};
#include "MinHeap.cpp"
#endif