#ifndef _COMPLEXLINKEDLIST_H
#define _COMPLEXLINKEDLIST_H

#include <string>
using namespace std;

/*	Roy Basmacier
	roy@sabanciuniv.edu
	24813
	 __          
	 )_) _       
	/ \ (_) (_(  
			  _) 
*/


#define SIZE 4

struct complexNode
{
	int num;
	string type; // S for standard M for merged
	complexNode* nexts[SIZE];

	complexNode(int n = 0) : num(n) 
	{
		for(int i = 0; i < SIZE; i++)
			nexts[i] = nullptr;
		type = "S";
	}
};

class complexlinkedlist
{
	// all of them are public because I implemented my merge function in main.cpp
public:	
	complexNode *head[SIZE];
	complexlinkedlist();
	void printList(int index, complexlinkedlist cll[]);
	void insertNode(int index, int n);
	void deleteNode(int index, int n);

};

#endif
