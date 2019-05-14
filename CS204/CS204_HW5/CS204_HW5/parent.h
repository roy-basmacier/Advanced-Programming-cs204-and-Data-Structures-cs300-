#ifndef PARENT_H
#define PARENT_H
#include "account.h"

class Parent
{
public:
	string name;//name
	Account & acc;//shared account
	Parent(string, Account&);//constructor
	void printAccountInfo();//prints detailed account info
	void depositMoney(double);//deposits money
	void spendMoney(double);//spends money only if there is enough debt limit
	void payDebt(double);// pays debt onl if payment is smaller or equal to debt
};

#endif