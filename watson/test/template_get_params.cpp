/*
 * get params from template argument
 * metaprogramming
 * compile with -std=c++11
 */

#include <iostream>
#include <tuple>

using namespace std;

template <int N>
void foo(){
  cout << N << endl;
}

template <int N, int M, int ... Rest>
void foo(){
  cout << N << endl;
  foo<M, Rest...>();
}


int main(){
  foo<1, 5, 7>();   // print 1 5 7
  
  cout << endl;
  
  foo<4, 9, 16, 100>();   // print 4 9 16 100

  return 0;
}
