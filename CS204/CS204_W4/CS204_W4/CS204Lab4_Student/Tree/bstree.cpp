#include "bstree.h"
#include <iostream>
#include "DynStack.h"

using namespace std;

bstree::bstree() {
	root = nullptr;
}

void bstree::dhelper(tnode* node) {
	if (node != nullptr) {
		dhelper(node->left);
		dhelper(node->right);
		delete node;
	}
}

bstree::~bstree() {
	dhelper(root);
}

bool bstree::shelper(int val, tnode* node) {
	if (node == nullptr)
		return false;
	else if (node->val == val)
		return true;
	else if (node->val > val)
		return (shelper(val, node->left));
	else if (node->val < val)
		return (shelper(val, node->right));
	else
		return false;
}

bool bstree::search(int val) {
	return (shelper(val, root));
}

bool bstree::ihelper(int val, tnode * &node) {
	if (node == nullptr) {
		node = new tnode;
		node->val = val;
		node->left = nullptr;
		node->right = nullptr;
		return true;
	} else if (node->val > val) {
		return (ihelper(val, node->left));
	} else  if (node->val < val) {
		return (ihelper(val, node->right));
	} else  if (node->val == val) {
		return false;
	}
}

void bstree::insert(int val) {
	if( (ihelper(val, root))) {
		cout << val << " is inserted." << endl;
	} else {
		cout << val << " already exists." << endl;	
	}
}

void bstree::phelper(tnode* node) {
	if(node)
	{
		phelper(node->left);
		cout << node->val << endl;
		phelper(node->right);
	}
}

void bstree::printInOrderRecursive() {
	phelper(root);
	cout << endl;
}

void bstree::printInOrderIterative() {
	DynStack stack;
	tnode* node = root;
	while (!stack.isEmpty() || node) {
		if (node) {
			stack.push(node);
			node = node->left;
		} else {
			stack.pop(node);
			cout << node->val << " ";
			node = node->right;
		}
	}
	cout << endl;
}

int main() {
	bstree mytree;

	mytree.insert(100);
	mytree.insert(3);
	mytree.insert(3);
	mytree.insert(5);
	mytree.insert(6);
	mytree.insert(9);
	mytree.insert(5);
	mytree.insert(8);
	cout << endl;

	cout << "Querying 3" << endl;
	if(mytree.search(3)) {
		cout << "3 is in the tree " << endl;
	} else {
		cout << "Could not find 3 " << endl;
	}
	cout << "Querying 51" << endl;
	if(mytree.search(51)) {
		cout << "51 is in the tree " << endl;
	} else {
		cout << "Could not find 51 " << endl;
	}

	cout << endl << endl;
	cout << "Printing recursive in order " << endl;
	mytree.printInOrderRecursive();
	cout << "Printing iterative in order " << endl;
	mytree.printInOrderIterative();	
	system("pause");
}