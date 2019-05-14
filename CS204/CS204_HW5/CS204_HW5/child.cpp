#include "child.h"

Child::Child(string n, Parent & p) : name(n), parent(p) {}

void Child::spendMoney(double money)//can only send upto 200
{
	if(money > 200)
	{
		cout << name << " can not spend " << money
			<< "TL. Children can spend up to 200TL.\n";
	}
	else
	{
		if(parent.acc.balance >= money)
		{
			cout << name << " has successfully spent " << money << "TL.\n";
			parent.acc.balance -= money;
		}
		else if ( money - parent.acc.balance + parent.acc.debt > parent.acc.limit)
		{
			cout << name << " cannot spend " << money << "TL. :(\n";
		}
		else
		{
			cout << name << " has successfully spent " << money << "TL.\n";
			parent.acc.debt += money - parent.acc.balance;
			parent.acc.balance = 0;
		}
	}

}

void Child::displayAccountInfo()//brief account detail
{
	cout << "\n******************************\nThe account balance is: " << parent.acc.balance
		<< "TL.\nThe available account limit is: " << parent.acc.limit - parent.acc.debt <<"TL.\n******************************\n";
}


