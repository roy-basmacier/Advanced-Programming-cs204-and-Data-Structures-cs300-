#include "MinHeap.h"
#ifndef MinHeap_CPP
#define MinHeap_CPP




template<class T>
MinHeap<T>::MinHeap(T* a, int s) : arr(a), size(s), capacity(s)
{
	for(int i = size/2; i > 0; i--)
		perculateDown(i);
}

template<class T>
MinHeap<T>::~MinHeap()
{

}

template<class T>
T MinHeap<T>::getMin()
{
	return arr[1];
}

template<class T>
void MinHeap<T>::deleteMin()
{
	swap(arr[1], arr[size-1]);
	size--;
	perculateDown(1);
}

template<class T>
void MinHeap<T>::insert(T x)
{
	if(!isFull())
	{
		size++;
		int temp = size-1;
		while(temp > 1 && x <arr[temp/2])
		{
			arr[temp] = arr[temp/2];
			temp /= 2;
		}
		arr[temp] = x;
	}

}


template<class T>
void MinHeap<T>::decreaseElements(int x)
{
	for(int i = 1; i < size; i++)
		arr[i] - x;

}

template<class T>
void MinHeap<T>::perculateDown(int i)
{
	
	while(2*i < size)
	{
		int leftChild = i*2;
		int rightChild = i*2 + 1;
		int smallerChild = leftChild;
		// checking if right exists and if its smaller than left
		if (rightChild < size && arr[rightChild] < arr[leftChild])
			smallerChild = rightChild;
		
		// checking if smaller child is smaller than parent
		if (arr[smallerChild] < arr[i])
		{
			swap(arr[smallerChild], arr[i]);
			i = smallerChild;
		}
		else
			break;
	}

}

template<class T>
bool MinHeap<T>::isFull(){ return size >= capacity;}

template<class T>
bool MinHeap<T>::isEmpty(){ return size != 1;}
#endif