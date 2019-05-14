#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
/*
	Roy Basmacier

	1) Translation unit that corresponds to source.cpp

int strlen(const char* string);

int strlen(const char* string)
{
	int length = 0;
	while(string[length]) ++length;
	return length + 5;
}
	It returns 5 + the length of a given string 
*/

//	2) output is 11

/*
#ifdef NDEBUG
foo();
#endif
*/

//	3) It gives a compile time error

/*	4) output is 

-7
23

*/

// CHALLENGE QUESTION

int saveThePrisoner(int n, int m, int s) {
    int res = ((m + s-1) % n);
    if (res == 0)
        return s;
    return res;

}

int main ()
{
	ifstream in;
	string filename, line;
	int t, m, n, s;
	cout << "Enter file name: ";
	cin >> filename;
	in.open(filename.c_str());
	if (in.fail())
		cout << "Invalid File!" << endl;
	else
	{
		getline(in, line);
		istringstream iss(line);
		iss >> t;
		for (int i = 0; i < t; i++)
		{
			getline(in, line);
			istringstream iss(line);
			iss >> n >> m >> s;
			cout << saveThePrisoner(n,m,s) << endl;
		}

	}


	return 0;
}
