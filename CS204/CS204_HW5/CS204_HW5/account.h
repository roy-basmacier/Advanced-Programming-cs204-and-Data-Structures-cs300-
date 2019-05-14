#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <iostream>
using namespace std;
class Account
{
public:
	double balance, limit, debt; //account details
	Account(double,double,double);//constructor
};
#endif