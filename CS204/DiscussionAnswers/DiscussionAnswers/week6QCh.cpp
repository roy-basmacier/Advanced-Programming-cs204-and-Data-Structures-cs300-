#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

class matrix // matrix class that stores a vector of vector of ints and sizes of matrix
{
private:
	int row_size;
	int col_size;

	vector<vector<int> > m;

public:
	matrix(int rs, int cs) : row_size(rs), col_size(cs) // creates the atrix given the size and values
	{
		vector<int> v;
		v.clear();
		int x;
		for(int i=0; i < cs; i++)
		{
			for(int j=0; j < rs; j++)
			{
				v.push_back(0);
			}
			m.push_back(v);
			v.clear();
		}
	}
	matrix(int rs, int cs, string s) : row_size(rs), col_size(cs) //creates a matrix of zeros with given size
	{
		istringstream iss(s);
		vector<int> v;
		v.clear();
		int x;
		for(int i=0; i < cs; i++)
		{
			for(int j=0; j < rs; j++)
			{
				iss >> x;
				v.push_back(x);
			}
			m.push_back(v);
			v.clear();
		}

	};

	void print()
	{
		for(int i=0; i < col_size;i++)
		{
			for(int j=0; j<row_size;j++)
			{
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
	}

	matrix operator+(const matrix & rhs ) //adds 2 matrices and returns its result
	{
		matrix result(col_size,row_size);

		//checks if two matrices can be added or not (size are equal or not)
		if(col_size != rhs.col_size || row_size != rhs.row_size)
		{
			cout << "Cannot add two matrices of difference sizes!\nExiting...\n";
			exit(0);
		}
		for(int i=0; i < col_size;i++)
		{
			for(int j=0; j<row_size;j++)
			{
				result.m[i][j] += rhs.m[i][j] + m[i][j];
			}
		}
		return result;
	}


};
int main ()
{
	ifstream in;
	string file_name;

	// input file
	do
	{
	cout << "Enter file name: ";
	cin >>  file_name;
	in.open(file_name.c_str());
	}while(in.fail());

	//parsing input
	int T, N, M;
	string s1,s2;
	char tmp;
	in >> T;
	getline(in,s1); //clearing empty line
	for(int a0 = 0; a0 < T; a0++)
	{
		in >> N >> M;
		getline(in,s1);//clearing empty line
		getline(in,s1);//getting first matrixe's values
		getline(in,s2);//getting second matrixe's values

		//creating 3 matrices
		matrix first(N,M,s1);
		matrix second(N,M,s2);
		matrix result(N,M);
		result = first + second;
		result.print();
	}
	return 0;
}

