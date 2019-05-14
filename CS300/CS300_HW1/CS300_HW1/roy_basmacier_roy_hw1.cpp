#include <iostream>
#include <string>
#include "Stack.h"

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
	This program gets an input and manipulates
	it accordingly to the given rules only 
	using a stack structure.
	3 moves the cursor to the left
	4 moves the cursor to the right
	5 reverses the left side of the cursor
	6X removes all Xs from left side of cursor 
*/

int main()
{
	string input;
	cout << "Enter input string: ";
	cin >> input;
	char _;
	Stack <char>* lhs = new Stack<char>; // stack for the left hand side of cursor
	Stack <char>* rhs = new Stack<char>; // stack for the right hand side of cursor

	for(int i = 0; i < input.length(); i++)
	{
		if(input[i] == '1')
			break;

		// removes first character from lhs
		else if (input[i] == '2')
			lhs->pop(_);

		// moves cursor to the left by poping from lhs and pushing to rhs
		else if (input[i] == '3')
			*lhs>>rhs;

		// moves cursor to the right by poping from rhs and pushing to lhs
		else if (input[i] == '4')
		{
			if (! rhs->isEmpty())
				*rhs>>lhs;
		}

		// reverses the left hand side
		else if (input[i] == '5')
			lhs->reverse();

		// removes next letter of input from the lhs
		else if (input[i] == '6')
		{
			lhs->remove(input[i+1]);
			i++;
		}

		// adds to lhs
		else 
			lhs->push(input[i]);
	}

	// OUTPUT
	lhs->rprint();// prints the left hand side
	rhs->print(); // prints the right hand side in reverse order
	cout << endl;
}
