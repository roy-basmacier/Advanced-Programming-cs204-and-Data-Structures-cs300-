/* author : k 
   we want the threads print the numbers in 
   increasing order. the solution is wrong. 
   how can you fix it? 
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

int counter = 0;
int maxi = 300;
mutex m;
//TODO: the code stalls, the numbers must be in increasing order
//there are two things to change
//Hint 1; once a thread prints something it needs to give the chance to the other threads
//Hint 2; the increment operation inside cout can create problems

void print3k(int mod) {

  while(counter <= maxi) { 
	  
    if(counter % 3 == mod) {
	  m.lock();
      cout << counter++ <<endl;
	  m.unlock();
	  //this_thread::yield();
    }
	
  }
  
}

int main()  {
  thread thr0(print3k, 0);
  thread thr1(print3k, 1);
  thread thr2(print3k, 2);
  
  thr0.join();
  thr1.join();
  thr2.join();
  
  return 0;    
}
