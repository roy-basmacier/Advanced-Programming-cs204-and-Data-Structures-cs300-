#include "Stack.h"

using namespace std;


Stack::Stack() : top(nullptr) {}


void Stack::push(string tag)
{
	stackNode *tmp = new stackNode(tag);
	if(isEmpty())
		top = tmp;
	else
	{
		tmp->next = top;
		top = tmp;
	}
}

void Stack::pop(string &tag)
{
	if(!isEmpty())
	{
		tag = top->tag;
		stackNode *tmp = top;
		top = top->next;
		delete tmp;
	}
}

bool Stack::isEmpty()
{
	if (top)
		return false;
	return true;
}
