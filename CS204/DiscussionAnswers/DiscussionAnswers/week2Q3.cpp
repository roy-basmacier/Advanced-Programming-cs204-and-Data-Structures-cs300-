/*

The output of the code below is:

firstvalue is 10
secondvalue is 20

//

#include <iostream>
using namespace std;


int main ()

{
	int firstvalue = 5, secondvalue = 15;
	int * p1, * p2;
	p1 = &firstvalue;
	p2 = &secondvalue;
	*p1 = 10;
	*p2 = *p1;
	p1 = p2;
	*p1 = 20;
	cout << "firstvalue is " << firstvalue << '\n';
	cout << "secondvalue is " << secondvalue << '\n';
	return 0;

}
*/