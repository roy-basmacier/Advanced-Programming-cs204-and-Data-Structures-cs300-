#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <string>
using namespace std;

template <class Tx, class Ty>
struct treeNode
{
	Tx value; // english meaning
	Ty correspodent; // turkish meanings
	treeNode<Tx, Ty> * left;
	treeNode<Tx, Ty> * right;

	treeNode(Tx val, Ty corr, treeNode<Tx, Ty> * l = nullptr, treeNode<Tx, Ty>* r = nullptr) : value(val), correspodent(corr), left(l), right(r) {}
};

template <class Tx, class Ty>
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	
	void insert(Tx, Ty);								//public insert
	void inorder();										//public inorder
	treeNode<Tx, Ty>* search(Tx);						//public search
	treeNode<Tx, Ty>* search(treeNode<Tx, Ty>*, Tx);	//searches for a ndoe with Tx returns node
	
private:
	void inorder(treeNode<Tx, Ty>*);					//prints inorder
	treeNode<Tx, Ty>* insert(treeNode<Tx, Ty>*, Tx, Ty);//inserts a node with node value as Tx Ty
	treeNode<Tx, Ty>* root;
	
};
#include "BinarySearchTree.cpp"
#endif
