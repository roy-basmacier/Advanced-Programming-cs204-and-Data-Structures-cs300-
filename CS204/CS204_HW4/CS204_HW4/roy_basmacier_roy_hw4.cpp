#include <iostream>
#include <string>
#include "set.h"

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
	This program has a set class which
	contains linked list with simple operations 
	such as union, intersection, difference
	and output streaming

*/

// free function for ostream << overloading
ostream & operator<<(ostream & os, const Set & rhs)
{
	setNode *set_ptr = rhs.head;
	node * node_ptr = nullptr;
	os << "{ ";
	while(set_ptr)
	{
		node_ptr = set_ptr->listptr->head;
		os << "{";
		while(node_ptr)
		{
			if(node_ptr->next == nullptr)
			{
				os << node_ptr->val << "}";
				break;
			}
			else
				os << node_ptr->val << ", ";
			node_ptr = node_ptr->next;
		}
		if(set_ptr->next == nullptr)
		{
			os << " }\n";
			break;
		}
		else
			os << ", ";
		set_ptr = set_ptr->next;
	}
	return os;
}

int main()
{
	Set set1, set2;

	int arr1[6] = {0,1,2,3,4,5};
	int arr2[5] = {0,1,2,3,4};
	int arr3[4] = {0,1,2,3};
	int arr4[3] = {0,1,2};
	int arr5[2] = {0,1};


	set1.addSet(arr1,6);
	set1.addSet(arr2,5);
	set1.addSet(arr3,4);

	set2.addSet(arr2,5);
	set2.addSet(arr3,4);
	set2.addSet(arr4,3);
	set2.addSet(arr5,2);

	cout << "Set1: " << set1 << endl;
	cout << "Set2: " << set2 << endl;


	// Assignment Test
	Set set3 = set2;
	cout <<"Set3 = Set2: " << set3 << endl;

	//Self assignment test
	set3 = set3;
	cout <<"Set3 = Set3: " << set3 << endl;

	//Intersection test
	Set set4 = set2 % set1;
	cout << "Set4 = Set2 % Set1: " << set4 << endl;

	//Difference test
	Set set5 = set2 / set1;
	cout << "Set5 = Set2 / Set1: " << set5 << endl;
	
	//Union test
	Set set6 = set2 + set1;
	cout << "Set6 = Set2 + Set1: " << set6 << endl;
	
	return 0;
}
