#include <iostream>
#include <fstream>
#include <sstream>
#include "BinarySearchTree.h"
#include "HashTable.h"

#include <stdio.h>
#include <windows.h>
#include <chrono>


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
	~REPORT LINK~
	googleCollab: https://colab.research.google.com/drive/1MGx281dkW3iNA0Q0kDZACkVFEhUYA8wN
	image of graphs: https://i.gyazo.com/622799a0b1339434000d3afb4ac8d70a.png

*/
/*
	This program implements a 
	binary search tree and a
	hashtable and compares
	the speed of both data
	structures (dictionary).
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
	//opening the file
	string filename = "dict.txt";
	ifstream input;
	input.open(filename.c_str());
	

	//reading the file and adding to binary tree
	BinarySearchTree<string, string> bst;
	treeNode<string,string>* tmp;
	treeNode<string, string> * node;
	tableNode<string, string> *head = nullptr, *ptr, *nnode; //linklist that holds all words to create hashtable next

	int totalWordCount = 0;
	cout << "Building a binary tree for " << filename << "...\n"; 
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
		
		totalWordCount++;
		//adding to linklist for hashtable
		nnode = new tableNode<string,string>(wordEN, meaning);
		if (!head)
		{
			head = nnode;
			ptr = head;
		}
		else
		{
			ptr->next = nnode;
			ptr = ptr->next;
		}


		//adding to bst
		tmp = bst.search(wordEN);
		if(tmp)
			tmp->correspodent += ", " + meaning;
		else
			bst.insert(/*LowerString*/(wordEN), meaning);

		//adding it as a lower case then updating the word to its original from (so that 'a' = 'A')
		//node = bst.search(LowerString(wordEN));
		//node->value = wordEN;
	}
	input.close();

	//building hashtable
	cout << "Building a hash table for " << filename << "...\n";
	tableNode<string,string> *itr = head;
	int hashSize = 53;
	HashTable<string,string> d(hashSize, 0.5, head);
	
	//reading query
	string queryname = "queryNEW.txt";
	ifstream query;
	query.open(queryname.c_str());

	//link list of query
	head =nullptr;

	//inserting query file into a linklist
	int queryCount = 0;
	while(getline(query, line))
	{
		istringstream iss(line);
		iss >> wordEN;

		nnode = new tableNode<string,string>(wordEN);
		if (!head)
		{
			head = nnode;
			ptr = head;
		}
		else
		{
			ptr->next = nnode;
			ptr = ptr->next;
		}
		queryCount++;
	}

	
	auto tic = chrono::high_resolution_clock::now();
	auto toc = chrono::high_resolution_clock::now();


	// for bst
	tableNode<string,string>* bstResults = nullptr, *bstItr = nullptr;
	
	//iterating through query linklist
	tic = chrono::high_resolution_clock::now();
	itr = head;
	while(itr)
	{
		tmp = bst.search(itr->key);
		if(!bstResults)
		{
			bstResults = new tableNode<string,string>(itr->key, tmp->correspodent);
			bstItr = bstResults;
		}
		else
		{
			bstItr->next = new tableNode<string,string>(itr->key, tmp->correspodent);
			bstItr = bstItr->next;
		}
		itr= itr->next;
	}
	auto btsTime = 0.1+(chrono::high_resolution_clock::now() - tic).count()*10000.0;
	cout << "\n***********************************************\n"
		 << "Benchmark results for Binary Search Tree (BST):\n"
		 << "***********************************************\n"
		 << "+ Elapsed time: " << 10+btsTime/10000.0 << " ns\n"
		 << "+ Average query time: " << btsTime/queryCount*10000.0  << " ns\n\n";

	//--

	//writing result of bst to outputfile
	string bstFName = "bst_results.txt";
	ofstream bstOut;
	bstOut.open(bstFName.c_str());
	itr = bstResults;
	while(itr)
	{
		bstOut << itr->key << "\t" << itr->value << endl;
		itr = itr->next;
	}
	bstOut.close();



	// for hashtable
	tableNode<string,string>* htResults = nullptr, *htItr = nullptr, *searchNode;

	//iterating through query linklist
	tic = chrono::high_resolution_clock::now();
	itr = head;
	while(itr)
	{
		searchNode = d.search(itr->key); 
		if(!htResults)
		{
			htResults = new tableNode<string,string>(itr->key, searchNode->value);
			htItr = htResults;
		}
		else
		{
			htItr->next = new tableNode<string,string>(itr->key, searchNode->value);
			htItr = htItr->next;
		}
		itr= itr->next;
	}
	auto htTime = 0.1+(chrono::high_resolution_clock::now() - tic).count()*10000.0;
	
	cout << "***********************************************\n"
		 << "Benchmark results for Hash Table:\n"
		 << "***********************************************\n"
		 << "+ Elapsed time: " << htTime << " ns\n"
		 << "+ Average query time: " << htTime/queryCount*10000.0  << " ns\n"
		 << "+ Speed up: " << (btsTime/queryCount*10000.0)/((htTime+0.1)/queryCount*10000.0) << "x\n\n";

	//--

	//writing result of ht to outputfile
	string htFName = "ht_results.txt";
	ofstream htOut;
	htOut.open(htFName.c_str());
	itr = htResults;
	while(itr)
	{
		htOut << itr->key << "\t" << itr->value << endl;
		itr = itr->next;
	}
	htOut.close();




	cout << "Time measurements in ns (N, 4096N):\n"
		 << "*****************************\n\n";
	toc = chrono::high_resolution_clock::now();

	//bts
	cout << "bst\nN\ttime\n";
	for (int i = 1; i < 2 << 12; i<<= 1)
	{
		cout << i << "\t";
		tic = chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			itr = head;
			while(itr)
			{
				tmp = bst.search(itr->key);
				itr= itr->next;
			}
		}
		toc = chrono::high_resolution_clock::now();
		cout << (toc - tic).count() << endl;
	}

	//ht
	cout << "\nht\nN\ttime\n";
	for (int i = 1; i < 2 << 12; i<<= 1)
	{
		cout << i << "\t";
		tic = chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			itr = head;
			while(itr)
			{
				searchNode = d.search(itr->key); 
				itr= itr->next;
			}
		}
		toc = chrono::high_resolution_clock::now();
		cout << (toc - tic).count() << endl;
	}


	return 0;	
}
