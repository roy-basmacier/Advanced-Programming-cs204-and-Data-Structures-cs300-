#include <iostream>
#include <vector>
using namespace std;

//given a set of n numbers, find the maximum difference among two of them
//the max absolute value of the given numbers will be 10000

//TODO: the code does not compile. You are only allowed to add preprocessor directives (Hint: you need five of them)
#define INF 10000
#define foreach(v, i) 


//do not modify this part
int main(){
  int n; cin >> n;
  vector<int> v(n);
  foreach(v, i) {
    io(v)[i];
  }
  int mn = INF;
  int mx = -INF;
  foreach(v, i) {
    func(mn, v[i], <); //updates the minimum element
    func(mx, v[i], >); //updates the maximum element
  }
  int ans = mx - mn;
  cout << toStr(Result =) <<' '<< ans;
  return 0;

}