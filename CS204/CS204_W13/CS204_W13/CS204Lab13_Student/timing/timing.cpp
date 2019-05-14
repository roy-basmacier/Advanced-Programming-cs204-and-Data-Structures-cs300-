#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <atomic>

using namespace std;

//a dummy job 
void dummy(atomic_int& sum) {
  /* this dummy task just does some operations */ 
  int tsum = 0;
  for(long long i = 0; i < 160000000; i++) {
    tsum += i * i;
  }
  sum = tsum;
}

//a task which does 2 dummy jobs in a for loop (this is sequential) no threads...
void task() {
  atomic_int sum;
  for(int i = 0; i < 8; i++) {
    dummy(sum);
  }
  cout << "sequential task: " << sum << endl;
}

//TODO: implement a parallel version with 8 threads where each thread computes one
//dummy function... press esc + ctrl + shift (windows only) once your are done
void par_task() {
  atomic_int sum;
  vector<thread> values;
  for(int i = 0;i < 8;i++)
	  values.push_back(thread(dummy, ref(sum)));
  for(thread &t : values)
	  t.join();

  //TODO: Fill the rest


  cout << "parallel task: " << sum << endl;
}

int main(){
  cout << "system_clock" << endl;
  //num/den is the ratio for accuracy 
  cout << chrono::system_clock::period::num << endl;
  cout << chrono::system_clock::period::den << endl;
  cout << "steady = " << boolalpha << chrono::system_clock::is_steady << endl << endl;
  
  cout << "high_resolution_clock" << endl;
  cout << chrono::high_resolution_clock::period::num << endl;
  cout << chrono::high_resolution_clock::period::den << endl;
  cout << "steady = " << boolalpha << chrono::high_resolution_clock::is_steady << endl << endl;
  
  cout << "steady_clock" << endl;
  cout << chrono::steady_clock::period::num << endl;
  cout << chrono::steady_clock::period::den << endl;
  cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;
  
  // Store the time difference between start and end using steady_clock
  auto start = chrono::steady_clock::now();
  task();
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  cout << chrono::duration <double> (diff).count() << " secs" << endl;
  cout << chrono::duration <double, nano> (diff).count() << " ns" << endl;
  cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
  
  //now we will measure the time for the parallel task with various number of threads
  //plase observe the time changes
  start = chrono::steady_clock::now();
  par_task();
  end = chrono::steady_clock::now();
  diff = end - start;
  cout << chrono::duration <double> (diff).count() << " secs" << endl;
  return 0;    
}
