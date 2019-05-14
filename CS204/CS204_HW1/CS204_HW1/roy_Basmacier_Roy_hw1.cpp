#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

/*	Roy Basmacier
	roy@sabanciuniv.edu
	24813
	 __          
	 )_) _       
	/ \ (_) (_(  
			  _) 
*/
/*
	This program takes a txt file as input
	reads file and extracts the info into 
	a structure containing matrices and the
	sum of a matrix. after it prompts the user
	for a k value then finds the combinaitions of
	k matrices that the sum is equal to one of the matrix
	in the vector of matrix.
*/

struct matrices // stores a matrix and its sum
{
	vector<vector<int> > m;
	int total;
	void sum()
	{
		int result = 0;
		for(unsigned int i = 0;i < m.size();i++)
			for(unsigned int j = 0;j < m[i].size();j++)
				result += m[i][j];
		this->total = result;
	}
}; 

vector <int> in(int a, vector<int> v) // returns vector of indexes of a in v if a is not in v returns empty vector
{
	vector <int> indexesOfSum;
	for(unsigned int i = 0;i < v.size();i++)
	{
		if (v[i] == a)
			indexesOfSum.push_back(i);
	}
	return indexesOfSum;
}

bool check(vector<matrices> tensor, vector<int> indexes, int indexOfSum) // checks if the given indexes of matrices sums are equal to the indexOfSum matrix
{
	int tempSum = 0;
	for(int i = 0; i < tensor[0].m.size(); i++) // iterate through rows
	{
		for(int j = 0; j < tensor[0].m[0].size(); j++) // iterate through columns
		{
			for(int k = 0; k < indexes.size(); k++) // iterate through indexes of matices that could be an answer
				tempSum += tensor[indexes[k]].m[i][j];

			if(tempSum != tensor[indexOfSum].m[i][j]) // check if their sume is equal to the given matrix
				return false;

			tempSum = 0;
		}
	}

	return true;
}

void comb(int N, int K, vector<int> v, vector<matrices> tensor) // Adapted from http://rosettacode.org/wiki/Combinations#C.2B.2B
															    // I changed this function from the internet for my own use
															    // Finds combination C(N, k)
{
    string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

	vector<int> indexes; // storing indexes of matrix that can possibly be the wanted output
	indexes.clear();

	int s = 0, cnt = 0;
    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
			// first checks if the total sum of two matrices are equal to any other matrix
            if (bitmask[i]) s += v[i];
        }
		vector <int> indexesOfSum = in(s, v);
		if ( indexesOfSum.size() > 0)
		{
			for(int j = 0; j < N; ++j)
					if (bitmask[j]) indexes.push_back(j);

			for(int z = 0; z < indexesOfSum.size(); z++)
			{
				// if the actual matrix sum is correct then print output
				if (check(tensor, indexes, indexesOfSum[z]))
				{
					cnt ++;
					cout << "Matrix " << indexesOfSum[z] << " can be written as the sum of matrices";
					for(int j = 0; j < N; ++j)
						if (bitmask[j]) cout << " " << j ;
					cout << endl;
				}
			}
		}
		indexes.clear();
		s = 0;
    } while (prev_permutation(bitmask.begin(), bitmask.end()));

	if (cnt < 1)
		cout << "There are no valid combinations in the given input file" << endl;
}

int main()
{
	cout << "Please enter the input file name: ";
	string fileName;
	cin >> fileName;
	ifstream iFile;
	iFile.open(fileName.c_str());

	// Until valid file is given
	while (iFile.fail())
	{
		cout << "Invalid file name. Please enter again: ";
		cin >> fileName;
		iFile.open(fileName.c_str());
	}
	string line;
	int N, rows, cols, rowCnt = 0, colCnt = 0;

	// getting how many matrices there will be (N)
	getline(iFile, line);
	istringstream issN(line);
	issN >> N ;

	// getting size of matrices
	getline(iFile, line);
	istringstream issS(line);
	issS >> rows >> cols;

	//removing first space line
	getline(iFile, line);

	vector<matrices> tensor(N); // stores each matrix in a structure 
	vector<vector<int> > m(rows); // matrix
	vector<int> v(cols); // vector

	//clears initialized variables
	v.clear();
	m.clear();
	tensor.clear();
	int elm;
	bool isInvalid = false;
	// reading file and saving them to vector also checking if file has valid matrices
	while( getline(iFile, line))
	{
		// reading line
		istringstream iss(line);
		if (line != "")
		{
			// reading each elm in string stream and pushing it back into v vector also keeping count of cols
			while(iss >> elm) 
			{
				colCnt++;
				v.push_back(elm);
			}

			// checking if input is valid (cols)
			if (colCnt != cols)
				isInvalid = true;

			// pushing back v vector into m, clearing v and keeping count of rows
			colCnt = 0;
			m.push_back(v);
			rowCnt++;
			v.clear();
		}
		else
		{
			if (rowCnt != rows)
				isInvalid = true;
			rowCnt = 0;
			matrices temp;
			temp.m = m;
			temp.sum();
			tensor.push_back(temp);
			m.clear(); 
		}
	}
	// checks last matrix
	if (rowCnt != rows)
		isInvalid = true;
	matrices temp;
	temp.m = m;
	temp.sum();
	tensor.push_back(temp);

	// checking if there are N amount of matrices
	if(N != tensor.size())
		isInvalid = true;

	if(isInvalid)
		cout << "Invalid file." << endl;
	else
	{
		//continue with program
		int k;
		cout << "Enter k: ";
		cin >> k;
		
		// making vector of all sums 
		vector<int> sums;
		for(unsigned int i = 0; i < tensor.size();i++)
			sums.push_back(tensor[i].total);

		// this function first finds the total sum of matrices (order of number in matrix doesnt matter)
		// then it checks if the order in the matrices are correct
		comb(N, k, sums, tensor);

	}
	return 0;
}
