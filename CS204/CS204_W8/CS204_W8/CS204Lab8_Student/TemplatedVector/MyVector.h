/* Author: Zeynep Dogmus
 * Date: April 2013
 * Templated Vector Example
*/
#ifndef MYVECTOR_H_
#define MYVECTOR_H_

//TODO: make this class templated.
template <class T>
class MyVector
{
public:
	MyVector<T>();
	MyVector<T>(int, T);
	~MyVector<T>();

	void display();
	void increaseElements(T);
	
private:
	T *myVector;
	int size;
};

//TODO: Do you need to include something?
//Please think a little bit and understand why...
#include "MyVector.cpp"
#endif
