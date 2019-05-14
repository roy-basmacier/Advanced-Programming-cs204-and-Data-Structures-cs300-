/* Author: Zeynep Dogmus
 * Date: April 2013
 * Templated Vector Example
*/
#include"MyVector.h"
#include <string>
#include <iostream>
using namespace std;


// Default Constructor
template <class T>
MyVector<T>::MyVector()
{
	myVector = nullptr;
}

// Constructor with Dynamic Allocation
template <class T>
MyVector<T>::MyVector(int newSize,T value)
{
	size = newSize;
	myVector = new T[size];
	for(int i = 0; i < size; i++)
		myVector[i] = value;
    //TODO: create an array of T objects
    //assign all the elements to the value
}

// Displays the elements in the vector
//TODO: make this method templated
template <class T>
void MyVector<T>::display()
{
	for(int i = 0; i < size; i++){
		cout << myVector[i] << " ";
	}
	cout << endl << endl;
}

// Adds val to every element of the vector
template <class T>
void MyVector<T>::increaseElements(T value)
{
	for (int i = 0; i < size; i++){
		myVector[i] = myVector[i] + value;
	}
}

//Destructor
template <class T>
MyVector<T>::~MyVector()
{
	delete [] myVector;
	//TODO: delete the vector
}
