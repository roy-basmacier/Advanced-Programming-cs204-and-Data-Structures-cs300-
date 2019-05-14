#include <iostream>
#include <string>
#include "linkedList.h"
int main()
{	
	linkedlist list;
	string word = "";
	cout << "Please enter a word!" << endl;
	//Ctrl-Z in order to exit from the loop
	while(cin >> word)
	{
		//Here add to beginning or end could be displayed
		//list.addToBeginning(word);
		list.addToEnd(word);
		cout << "Please enter a word!" << endl;
	}

	list.printList();
	cout << endl;
	list.printListInverse();

	system("pause");
	return 0;
}

