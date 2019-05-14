#ifndef CHILD_H
#define CHILD_H
#include "parent.h"

class Child
{
public:
	string name; //name
	Parent & parent;//shared parent to access parents account
	Child(string, Parent &);//constructor
	void displayAccountInfo();//displays breif info of account
	void spendMoney(double);//spends money only upto 200
};
#endif