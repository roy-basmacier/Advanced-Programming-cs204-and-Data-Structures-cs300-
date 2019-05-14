#ifndef STACK_H
#define STACK_H
#include <string>

/*	Roy Basmacier
	roy@sabanciuniv.edu
	24813
	 __          
	 )_) _       
	/ \ (_) (_(  
			  _) 
*/

template <class T>
struct stackNode
{
	T value;
	stackNode<T> * next;
	
	// constructor
	stackNode(T val, stackNode<T> * nxt = nullptr) : value(val), next(nxt) {}
};

template <class T>
class Stack
{
public:
	Stack();
	~Stack();
	void push(T);
	void pop(T &);

	// additional functions
	void pushToBottom(T); // inserts T to the bottom of the stack 
	void remove(T); // removes all T in stack
	void reverse(); // reverses the stack
	void print(); // prints stack
	void rprint(); // prints stack in reverse order
	bool isEmpty();

	// Overloaded operators
	void operator>>(Stack<T>*); // pops from stack and pushes to input stack

private:
	stackNode<T> * top;
};
#include "Stack.cpp"
#endif