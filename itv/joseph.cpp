/*
 * joseph problem
 * g(n, k) = (g(n - 1, k) + k) % n
 * g(1, k) = 0
 * refer from wiki
 */

#include <iostream>

using namespace std;

int joseph_recursive(int n, int k){
  if(n == 1) return 0;
  else return ((joseph_recursive(n - 1, k) + k) % n);
}

int joseph(int n, int k){
  int fn = 0;
  for(int i = 2; i <= n; ++i){
    fn = (fn + k) % i;
  }
  return fn;
}


int main(){
  cout << joseph(10, 3) << endl;
  cout << joseph_recursive(10, 3) << endl;

  cout << joseph(8, 3) << endl;
  cout << joseph_recursive(8, 3) << endl;
}
