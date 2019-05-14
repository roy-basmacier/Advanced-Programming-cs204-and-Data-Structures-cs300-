#include <sstream> 
#include <iostream> 
#include <mutex> 
#include <string> 
#include <thread> 

using namespace std;

class Fork { 
public: 
  Fork(){}
  Fork(int id){ID = id;}
  int ID;
  recursive_mutex m; 
}; 

//TODO: Deadlocks... They happen when a cyclic waiting
//dependency is formed among the threads. For the dining
//philosopher problem... (please read 
//https://en.wikipedia.org/wiki/Dining_philosophers_problem)

//TODO: try to understand how a deadlock occurs here.
//TODO: read slides 68-69 for in the ppt file (Locking multiple mutexes)
//TODO: try to apply the solution here. 


void eat(Fork &leftFork, Fork &rightFork, int philID) { 
  stringstream ss;
  
  leftFork.m.lock();
  ss << "Philosopher " << philID << " picked fork " << leftFork.ID << endl; 
  
  this_thread::sleep_for(chrono::seconds(1));
  
  rightFork.m.lock();
  ss << "Philosopher " << philID << " picked fork " << rightFork.ID << endl; 
  
  ss << "Philosopher " << philID << " finished eating.\n"; 
  
  leftFork.m.unlock();
  rightFork.m.unlock();
  cout << ss.str();
}

int main()  { 
  const int noPhil = 20; 
  Fork forks[noPhil]; 
  thread philosophers[noPhil]; 
  
  for (int i = 0; i < noPhil; i++) { 
    forks[i].ID = i;
  }
  
  philosophers[0] = thread(eat,  std::ref(forks[noPhil - 1]),  std::ref(forks[0]), 1); 
  
  for (int i = 1; i < noPhil; i++) { 
    philosophers[i] = thread(eat,  std::ref(forks[i-1]),  std::ref(forks[i]), i+1); 
  } 
  
  for(thread& p: philosophers) {
    p.join();
  }
} 
