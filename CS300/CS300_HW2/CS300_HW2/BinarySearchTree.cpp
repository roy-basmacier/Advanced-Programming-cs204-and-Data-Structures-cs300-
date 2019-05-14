#include "BinarySearchTree.h"
#ifndef BINARYSEARCHTREE_CPP
#define BINARYSEARCHTREE_CPP


template <class Tx, class Ty>
BinarySearchTree<Tx, Ty>::BinarySearchTree(): root(nullptr) {}

template <class Tx, class Ty>
BinarySearchTree<Tx, Ty>::~BinarySearchTree()
{

}

template <class Tx, class Ty>
treeNode<Tx, Ty>* BinarySearchTree<Tx, Ty>::search(treeNode<Tx, Ty> * node, Tx x)
{
	if (node == nullptr || node->value == x)
		return node;

	if (x > node->value)
		return search(node->right, x);

	/*if (x < node->value)*/
	return search(node->left, x);
}

template <class Tx, class Ty>
treeNode<Tx, Ty>* BinarySearchTree<Tx, Ty>::search(Tx x)
{
	return search(root, x);
}


template <class Tx, class Ty>
treeNode<Tx, Ty>* BinarySearchTree<Tx, Ty>::insert(treeNode<Tx, Ty> * node, Tx x, Ty y)
{
	if (node == nullptr)
		node = new treeNode<Tx, Ty>(x, y);
	
	if (x < node->value)
		node->left = insert(node->left, x, y);

	else if (x > node->value)
		node->right = insert(node->right, x, y);

	return node;
}

template <class Tx, class Ty>
void BinarySearchTree<Tx, Ty>::insert(Tx x, Ty y)
{
	root = insert(root, x, y);
}

template <class Tx, class Ty>
void BinarySearchTree<Tx, Ty>::inorder(treeNode<Tx, Ty>* node)
{
	if(node != nullptr)
	{
		
		inorder(node->left);
		cout << node->value << " : " << node->correspodent << endl;
		inorder(node->right);
	}
}

template <class Tx, class Ty>
void BinarySearchTree<Tx, Ty>::inorder()
{
	inorder(root);
}
#endif
