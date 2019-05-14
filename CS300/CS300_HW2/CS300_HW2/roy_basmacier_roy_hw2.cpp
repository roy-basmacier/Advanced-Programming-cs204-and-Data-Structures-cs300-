#include<iostream>
#include<fstream>
#include <sstream>
#include "BinarySearchTree.h"

#include<stdio.h>
#include<windows.h>


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
	This program implements a bst that holds nodes with
	english meanings paired with a turkish meaning. User
	can add, update and quarry the tree.
*/

//lowers a word
void ToLower(string & s)   
{
    int len = s.length();
    for(int k=0; k < len; k++)
    {
        s[k] = tolower(s[k]);
    }
}
//returns lowered word
string LowerString(const string & s)
{
    string word = s;
    ToLower(word);
    return word;
}



int main()
{
	//setting console to turkish
	//28599
	//1254
	SetConsoleOutputCP(1254);
    SetConsoleCP(1254);

	//opening the file
	string filename = "dict.txt";
	ifstream input;
	input.open(filename.c_str());
	BinarySearchTree<string, string> bts;
	treeNode<string,string>* tmp;
	//reading the file and adding to binary tree
	treeNode<string, string> * node;
	string line, wordEN, wordTR, meaning;
	while(getline(input, line))
	{
		istringstream iss(line);
		iss >> wordEN;
		meaning = "";
		while(iss >> wordTR)
				meaning += wordTR + " ";


		//removes last space from meaning
		meaning = meaning.substr(0,meaning.length()-1);

		tmp = bts.search(wordEN);
		if(tmp)
			tmp->correspodent += ", " + meaning;
		else
			bts.insert(/*LowerString*/(wordEN), meaning);

		//adding it as a lower case then updating the word to its original from (so that 'a' = 'A')
		//node = bts.search(LowerString(wordEN));
		//node->value = wordEN;
	}
	
	//user interface
	string cmd = "";
	cout << "***Help***\nQuery: 1\nAdd new translation: 2\nAdd new word: 3\nExit: 0\n";
	string word;
	

	while (cmd != "0")
	{
		cout << "Enter Command: ";
		cin >> cmd;

		//Query a word
		if (cmd == "1")
		{
			cout << "Enter queried word: ";
			cin >> word;
			tmp = bts.search(word);

			if (tmp)
				cout << word << " ---> " << tmp->correspodent << endl;
			else
				cout << "Could not find word!\n";
		}

		//add new trnaslation to existing word
		else if (cmd == "2")
		{

			cout << "Enter queried word: ";
			cin >> word;
			tmp = bts.search(word);
			if (tmp)
			{
				cout << "Enter the new translation: ";
				cin >> word;

				tmp->correspodent += ", " + word;
				cout << "***UPDATED***\n";
			
			}
			else
				cout << "Could not find word!\n";
		}

		//adds new word with translation
		else if (cmd == "3")
		{
			cout << "Enter New Word: ";
			cin >> word;
			tmp = bts.search(word);
			if (tmp)
				cout << "Word already exists, if you want to add new translation please use command 2.\n";
			else
			{
				cout << "Enter Translations: ";
				cin >> wordTR;
				bts.insert(word, wordTR);
			}
		}
	}
	bts.inorder();
	cout << "Bye...\n";
	return 0;	
}