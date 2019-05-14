#include <iostream>
#include "complexLinkedList.h"
using namespace std;

/*	Roy Basmacier
	roy@sabanciuniv.edu
	24813
	 __          
	 )_) _       
	/ \ (_) (_(  
			  _) 
*/

complexlinkedlist::complexlinkedlist() // constructor for complexlinkedlist
{
	for(int i = 0; i < SIZE; i++)
		head[i] = nullptr;
}

void complexlinkedlist::printList(int index, complexlinkedlist cll[])
{
	// creates a temp node at the end with a INT_MAX value, in order to print the list if the last node is a merged node
	for(int a = 0; a < SIZE; a++ )
		cll[a].insertNode(a, INT_MAX);
	complexNode *ptr = head[index];
	
	
	if(ptr == nullptr || (ptr && ptr->num == INT_MAX)) //  if there is no nodes in the list
		cout << "List is empty!" << endl;
	else
	{
		// prints out each node from head to nullptr
		while(ptr != nullptr)
		{
			// dont print the temp node i made
			if(ptr->num != INT_MAX)
			{
				// if node is mergred find original merged node and print accordingly
				if(ptr->type == "M")
				{
					for(int i = 0; i < SIZE; i++)
						if(ptr->nexts[i])
						{
							cout << ptr->type << i << "-" << ptr->num << " ";
							break;
						}
				}
				// prints standard nodes
				else
					cout << ptr->type << "-" << ptr->num << " ";
				}
			ptr = ptr->nexts[index];
		}
	}
	cout << endl;
	//for(int a = 0; a < SIZE; a++ )
	//	cll[a].deleteNode(a, INT_MAX);
	//deleteNode(index, INT_MAX);
}

void complexlinkedlist::insertNode(int index, int n) // Inserts a complexNode to the end of the complexlinkedlist(cll) with the value n 
													 // index is the index of which nexts[] will point to
{
	complexNode *ptr = head[index];
	complexNode *temp = new complexNode(n); // our pointer pointing to a new complexNode with value n

	// if the cll is empty, points head to the new complexNode
	if (head[index] == nullptr) 
		head[index] = temp;

	// else goes to the end of the list and makes the nexts[index] point to the new complexNode
	else
	{
		while(ptr->nexts[index] != nullptr)
			ptr = ptr->nexts[index];
		ptr->nexts[index] = temp;
	}
}

void complexlinkedlist::deleteNode(int index, int n)
{
	complexNode *currPtr, *prevPtr;
	currPtr = head[index];
	prevPtr = nullptr;

	//  if there is no nodes in the list
	if(currPtr == nullptr || (currPtr && currPtr->num == INT_MAX)) 
		cout << "List is empty!" << endl;
	else
	{
		// if the list has only one node
		if(head[index]->nexts[index] == nullptr && head[index]->num == n)
		{
			delete head[index];
			head[index] = nullptr;
		}

		else
		{
			// iterates through the whole lists saves the previous node as prevPtr
			// sets the previous pointer as current pointer and sets current pointer as the next[index] pointer
			for(currPtr = head[index];
				currPtr != nullptr;
				prevPtr = currPtr,  currPtr = currPtr->nexts[index])
			{
				if(currPtr->num == n)
				{
					if(prevPtr == nullptr) // If the node we want to delete is the first node
					{
						head[index] = currPtr->nexts[index];
					}
					else // If the node we want to delete is between two nodes or last node
					{
						prevPtr->nexts[index] = currPtr->nexts[index];
					}
					if(currPtr->type == "S")
						delete currPtr; // deallocates the wanted node
					else
					{
						int cnt = 0;
						currPtr->nexts[index] = nullptr;
						for(int i = 0; i < SIZE; i++)
							if(currPtr->nexts[i] != nullptr)
								cnt ++;
						if (cnt <= 1)
							currPtr->type = "S";

					}

					return;
				}
			}
		}
	}
}


