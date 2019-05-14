#include <iostream>
#include <chrono>

using namespace std; 

/*	Roy Basmacier
	roy@sabanciuniv.edu
	24813
	 __          
	 )_) _       
	/ \ (_) (_(  
			  _) 
*/

#define FIRSTDATATYPE unsigned int// choose a data type here
#define SECONDDATATYPE unsigned short// choose a data type here

FIRSTDATATYPE powmod(FIRSTDATATYPE a, FIRSTDATATYPE b, FIRSTDATATYPE m) // a ^ b % m
{
	unsigned long long res = 1, y = a;
	/*
	//fast power mod function
	while(b>0)
	{
		if(b%2 == 1)
		{
			res = (res*y) % (unsigned long long)m;
		}
		y = (y*y) % (unsigned long long)m;
		b /= 2;
	}
	*/
	
	//slow powermod function
	for (unsigned int i = 0; i < b; i++)
	{
		res = res * (unsigned long long) (a);
		res = res % (unsigned long long)m;
	}
	
	return res % (unsigned long long)m;
}


FIRSTDATATYPE gcd(FIRSTDATATYPE a, FIRSTDATATYPE b) {
  return b == 0 ? a : gcd(b, a % b);
}

class RSA {
private:
  SECONDDATATYPE p;
  SECONDDATATYPE q;
  FIRSTDATATYPE d;
public:
  FIRSTDATATYPE e;
  FIRSTDATATYPE n;
  RSA(SECONDDATATYPE p, SECONDDATATYPE q) {
	p = p;
	q = q;
	n = p*q;
	//FIRSTDATATYPE lcm = ((p-1)*(q-1))/gcd(p-1, q-1);
	FIRSTDATATYPE r = (p-1)*(q-1);
	//lcm = r;

	//smallest coprime of phi(n)
	int i = 2;
	while(gcd(r, i) != 1 || gcd(e,r) == 1)
		i++;
	e = i;

	//finding inverse modular of e mod (phi(n))
	FIRSTDATATYPE a = (e%r) % r;
	for(unsigned int j = 1;j < r; j++)
	{
		if((a*j )% r == 1)
		{
			d = j;
			break;
		}
	}
	/*
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "n = " << n << endl;
	//cout << "lcm = " << lcm << endl;
	cout << "r = " << r << endl;
	cout << "e = " << e << endl;
	cout << "d = " << d << endl;
	*/
  }

  FIRSTDATATYPE encrypt(FIRSTDATATYPE m) {
	  return powmod(m,e,n); // returns m^e Mod n
  }

  FIRSTDATATYPE decrypt(FIRSTDATATYPE c) {
	  return powmod(c,d,n); // returns  c^d Mod n
  }

  FIRSTDATATYPE decrypt_bit(FIRSTDATATYPE c) 
  {
	  unsigned long long res = 1;
	  FIRSTDATATYPE one = 1;
	  one = one << 31;
	 /* 
	  cout << "c = " << c << endl;
	  cout << "d = " << d << endl;
	  cout << "n = " << n << endl;
	  cout << "one = " << one << endl;
	  */

	  for(int i = 0; i < 32; i++)
	  {
		  if (one & d)
		  {
			//cout << c << "^" << one << " mod "<< n << " = " << powmod(c,one,n)<<  endl;	
			res = res * (unsigned long long)c; 
			res = res % (unsigned long long)n;
			//cout << res << endl;
		  }
		  if(i != 31)
		  {
			  res = (res % (unsigned long long)n )* (res% (unsigned long long)n);
			  res = res % (unsigned long long)n;
		  }

		  one = one >> 1;
	  }
	  
	  return res % (unsigned long long)n;
  }
};


int main () {
  //RSA rsa(62137,17);
  //RSA rsa(61,53);
  //RSA rsa (311,1637);
  //RSA rsa(62137, 62141);
  RSA rsa(5, 11);
  
  auto start = std::chrono::system_clock::now();
  FIRSTDATATYPE c = rsa.encrypt(15); // change to 15 later
  auto end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end - start;
  time_t end_time = std::chrono::system_clock::to_time_t(end);
  cout << "Encryption time: " << elapsed_seconds.count() << "s -- " << " ciphertext is " << c << "\n";

  start = std::chrono::system_clock::now();
  FIRSTDATATYPE m = rsa.decrypt(c);
  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout << "Decryption time: " << elapsed_seconds.count() << "s -- " << " message is " << m << "\n";

  start = std::chrono::system_clock::now();
  FIRSTDATATYPE m_bit = rsa.decrypt_bit(c);
  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout << "Decryption time: " << elapsed_seconds.count() << "s -- " << " message is " << m_bit << "\n";



  return 0;
}