#include "account.h"

//constructor / default constructor
Account::Account(double bal = 0, double lim = 0, double deb = 0) 
			  : balance(bal), limit(lim), debt(deb) {}