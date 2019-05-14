#include <iostream>
#include <string>
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
/*
	this programs makes SIZE amount of linkedlists using the
	complexNode. The program asks the user for a command and
	does the command. Commands are inserting a node (end of 
	the list), merging the lists, printing the list/lists, 
	deleteing a node and exiting the program.
*/


void printLists(complexlinkedlist cll[]) // prints out all lists in the complexlinkedlist array
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << "***** LIST " << i << " *****" << endl;
		cll[i].printList(i,cll);
	}
}


void mergeLists(complexlinkedlist cll[]) // merges all linked list's same elements to reduce memory
{
	complexNode *ptr; // i = points to the nodes in list 0th to SIZE-1th	 iterates through all but last list's nodes
	complexNode *currPtr; // points at the i+1th list to last list			 iterates through all the nodes after the ptr's list
	complexNode *prevPtr; // points to the prevoius node of currPtr
	bool shouldDelete;
	for(int i = 0; i < SIZE-1; i++) // looping through all lists but the last one
	{
		ptr = cll[i].head[i];

		while(ptr != nullptr) // going through all the elements in the ith list
		{
			//cout << "head's num is: " << ptr->num << endl;
			shouldDelete = false;
			for(int j = i + 1; j < SIZE; j++ ) // looping through all of the lists after ith list
			{
				currPtr = cll[j].head[j];
				prevPtr = nullptr;
				while(currPtr != nullptr) // going through all elements in the jth list
				{
					//cout << "Comparing PTR " << ptr->num << " with TEMP " << currPtr->num << endl;

					if(ptr->num == currPtr->num && ptr->num != INT_MAX)
					{
						//cout << ptr->num << " ==  " << currPtr->num << endl<<endl;
						/*
						8 9 7
						4 8 3
						4 8 5
						*/

						// changing type of node to M
						ptr->type = "M";
						
						// for the common value node (8), adds a pointer to its nexts[j] and points to the next node of j list (3) 
						ptr->nexts[j] = currPtr->nexts[j]; 
						
						// if the first node has the same element change the head pointer to merged node
						if(prevPtr == nullptr)
							cll[j].head[j] = ptr;
						else
							prevPtr->nexts[j] = ptr; // updates previous node (4) to point at the merged node (8)

						// checking id nexts has any other pointers if not delete that node
						int cnt = 0;
						for(int k = 0; k < SIZE; k++)
						{
							if (currPtr->nexts[k] != nullptr)
								cnt++;
						}
						if (cnt == 1)
							shouldDelete = true;
							//cll[j].deleteNode(j,currPtr->num);
						//printLists(cll);
					}
					prevPtr = currPtr;
					/* CRASHES THE PROGRAM IDK HOW TO DELETE NODE WITHOUT CRASHING
					if (shouldDelete)
						delete currPtr;
					*/
					currPtr = currPtr->nexts[j];
					//printLists(cll);

				}
	
			}
			ptr = ptr->nexts[i];
		}

	}
	cout << endl;
}


void message()
{
	cout << "1 - Insert a new node" << endl 
	  	 << "2 - Merge lists" << endl 
		 << "3 - Print list" << endl 
		 << "4 - Print all lists" << endl 
		 << "5 - Delete node" << endl 
		 << "6 - Exit" << endl << endl
		 << "Enter your choice:";
}

bool checkIndex(int i) // checks if index is out of range or not
{
	if (i < SIZE && i >=0)
		return 1;
	else
		cout << "Selection out of range!" << endl;
	return 0;
}


int main()
{
	complexlinkedlist cll[SIZE]; // list of complex linked lists
	
	int cmd;
	// promps user for a cmd and runs that cmd until 6 is entered
	do
	{
		int index, n;
		
		message();
		cin >> cmd;
		if(cmd == 1)
		{
			cout << "Please enter which list you want to add to: ";
			cin >> index;
			if(checkIndex(index))
			{
				cout << "Please enter the element you want to add: ";
				cin >> n;
				cll[index].insertNode(index, n);
			}
			cout << endl;
		}
		else if(cmd == 2)
			mergeLists(cll);
		else if(cmd == 3)
		{
			cout << "Please enter the list you want to print: ";
			cin >> index;
			if(checkIndex(index))
				cll[index].printList(index, cll);
			else
				cout << endl;
		}
		else if (cmd == 4)
			printLists(cll);
		else if (cmd == 5)
		{
			cout << "Please enter which list you want to delete from: ";
			cin >> index;
			if(checkIndex(index))
			{
				cout << "Please enter the number you want to delete: ";
				cin >> n;
				cll[index].deleteNode(index, n);
			}
			cout << endl;
		}


	}while(cmd != 6);

	/* SPECIAL TEST CASES
	CASE ONE
	cll[0].insertNode(0, 1);
	cll[0].insertNode(0, 4);
	cll[0].insertNode(0, 8);
	cll[1].insertNode(1, 4);
	cll[1].insertNode(1, 8);
	cll[1].insertNode(1, 3);
	
	CASE TWO
	cll[3].insertNode(3, 2);
	cll[3].insertNode(3, 7);
	cll[3].insertNode(3, 9);
	cll[2].insertNode(2, 9);
	cll[2].insertNode(2, 7);

	CASE THREE
	cll[0].insertNode(0, 9);
	cll[0].insertNode(0, 8);
	cll[0].insertNode(0, 7);
	cll[1].insertNode(1, 4);
	cll[1].insertNode(1, 8);
	cll[1].insertNode(1, 3);
	cll[2].insertNode(2, 4);
	cll[2].insertNode(2, 8);
	cll[2].insertNode(2, 5);

	CASE FOUR
	cll[0].insertNode(0, 4);
	cll[1].insertNode(1, 4);
	cll[2].insertNode(2, 4);
	cll[3].insertNode(3, 4);
	//cll[0].insertNode(0, 99);
	
	cout << "------BEFORE MERGING -------\n\n";
	printLists(cll);
	mergeLists(cll);
	cout << "~~~~~~~~AFTER MERGING ~~~~~~~\n\n";
	printLists(cll);
	*/


	return 0;
}
