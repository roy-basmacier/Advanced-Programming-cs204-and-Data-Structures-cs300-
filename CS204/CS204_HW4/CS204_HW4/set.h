#ifndef _SET_H
#define _SET_H
#include<string>

struct node
{
	int val;
	node *next;

	//default constructor
	node(int value = 0, node *nextptr = nullptr) : val(value), next(nextptr) {}

};

class linkedList
{
public:
	node *head;

	linkedList(node*); // default constructor

	linkedList(const linkedList &); // constructor
	node *createClone() const; // copy contructor helper

	linkedList(int[], int); // makes a linked list with array and size

	void add2end(int); // adds node to end of list

	bool operator==(const linkedList &); // compares lists
	//~linkedList();
};

struct setNode
{
	setNode *next;
	linkedList *listptr;

	//default constructor
	setNode( linkedList *lptr = nullptr, setNode *nextptr = nullptr) : next(nextptr), listptr(lptr) {}
};

class Set
{
public:
	setNode *head; // want to make private

	Set(setNode *headptr = nullptr) : head(headptr) {} // default constructor

	Set(const Set &); // copy constructor
	setNode *createClone() const; // copy constructor helper
	
	Set operator+(const Set &); // union
	Set operator%(const Set &); // intersection
	Set operator/(const Set &); // difference

	bool hasList(linkedList *); // returns true if the given set is in the set

	void addSet(int[], int); // makes a linked list with given array and adds it to the end of the set
	void addSet(linkedList); // adds given linked list to the end of the set
	
	//~Set();
};
#endif