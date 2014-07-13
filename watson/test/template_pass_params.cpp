/*
 * pass params, similar to get params
 */

#include <iostream>

using namespace std;

template <typename T>
int out(const T &v){
  cout << v << endl;
}

template <typename ...Ts>
void pass(const Ts &... params){
}

template <typename ...Ts>
void foo(const Ts &...params){
  pass(out(params)...);
}

int main(){

  foo(1, 1.3, 1.6); // will print 1.6 1.3 1

  return 0;
}
