#include "parent.h"


Parent::Parent(string s, Account & a) : name(s), acc(a){}
void Parent::printAccountInfo()//detailed account infos
{
	cout << "\n******************************\nThe account balance is: " << acc.balance
		<< "TL.\nThe account debt is: " << acc.debt
		<< "TL.\nThe account limit is: " << acc.limit
		<< "TL.\nThe available account limit is: " << acc.limit - acc.debt
		<< "TL.\n******************************\n";
}

//	assuming money > 0 for all other functionss
void Parent::depositMoney(double money)//add money to balance 
{
	cout << name << " has deposited " << money << " TL.\n";
	acc.balance += money;
}

void Parent::spendMoney(double money)//spends money according to account limits
{
	if(acc.balance >= money)
	{
		cout << name << " has successfully spent " << money << "TL.\n";
		acc.balance -= money;
	}
	else if ( money - acc.balance + acc.debt > acc.limit)
	{
		cout << name << " cannot spend " << money << "TL. :(\n";
	}
	else
	{
		cout << name << " has successfully spent " << money << "TL.\n";
		acc.debt += money - acc.balance;
		acc.balance = 0;
	}


}

void Parent::payDebt(double money)//pays debt according
{
	if (money > acc.debt)
		cout << name << " attempts to pay more than debt. No payment is done.\n";
	else
	{
		cout << name << " payed " << money << "TL of debt.\n";
		acc.debt -= money;
	}


}
