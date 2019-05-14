#ifndef STACK_H
#define STACK_H
#include <string>

using namespace std;

struct stackNode
{
	string tag;
	stackNode *next;

	stackNode(string s = "", stackNode *ptr = nullptr) : tag(s), next(ptr) {}
};

class Stack
{
private:
	stackNode *top;

public:
	Stack();

	void push(string);
	void pop(string &);
	bool isEmpty(void);
};


#endif