#ifndef _SET_H
#define _SET_H
#include<string>

template <class itemType>
struct node
{
	itemType val;
	node<itemType> *next;

	//default constructor
	node(itemType value = 0, node<itemType> *nextptr = nullptr) : val(value), next(nextptr) {}

};

template <class itemType>
class linkedList
{
public:
	node<itemType> *head;

	linkedList(node<itemType> * = nullptr); // default constructor

	linkedList(const linkedList<itemType> &); // constructor
	node<itemType> *createClone() const; // copy contructor helper

	linkedList(itemType[], int); // makes a linked list with array and size

	void add2end(itemType); // adds node to end of list

	bool operator==(const linkedList<itemType> &); // compares lists
	//~linkedList();
};

template<class itemType>
struct setNode
{
	setNode<itemType> *next;
	linkedList<itemType> *listptr;

	//default constructor
	setNode( linkedList<itemType> *lptr = nullptr, setNode<itemType> *nextptr = nullptr) : next(nextptr), listptr(lptr) {}
};

template <class itemType>
class Set
{
public:
	setNode<itemType> *head; // want to make private

	Set(setNode<itemType> *headptr = nullptr) : head(headptr) {} // default constructor

	Set(const Set<itemType> &); // copy constructor
	setNode<itemType> *createClone() const; // copy constructor helper
	
	Set<itemType> operator+(const Set<itemType> &); // union
	Set<itemType> operator%(const Set<itemType> &); // intersection
	Set<itemType> operator/(const Set<itemType> &); // difference

	bool hasList(linkedList<itemType> *); // returns true if the given set is in the set

	void addSet(itemType[], int); // makes a linked list with given array and adds it to the end of the set
	void addSet(linkedList<itemType>); // adds given linked list to the end of the set
	
	//~Set();
};
#include "set.cpp"
#endif