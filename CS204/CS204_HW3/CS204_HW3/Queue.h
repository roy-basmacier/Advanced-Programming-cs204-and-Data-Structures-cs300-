#ifndef QUEUE_H
#define QUEUE_H
#include "Stack.h"
#include <string>
using namespace std;


struct node
{
	string lectureName;
	int cap;
	node *next;

	node(string name = "", int x = -1, node *ptr = nullptr) : lectureName(name), cap(x), next(ptr) {}

};

//student node
struct queueNode
{
	string name;
	int id;
	node *lectures;
	queueNode *next;
	queueNode(string n = "", int i = 0, node *ptr = nullptr, queueNode *nxt = nullptr) : name(n), id(i), lectures(ptr), next(nxt) {}


};

class Queue
{
private:
	queueNode *front;
	queueNode *end;
public:
	
	Queue();

	void addToBeg(string);
	void addToBeg(int);
	void enqueue(queueNode *);
	void dequeue(queueNode *& );
	bool isEmpty() const;
	void clear();
	friend bool isXML(Stack s, string tag, Queue *qptr);
};

#endif