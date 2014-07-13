/*
 * some int test
 */


#include <iostream>

using namespace std;

int main(){

  int a[10];
  *(&a[5] - 4) = 16; // a[1]
  for(int i = 0; i < 10; ++i)
    cout << a[i] << " " << endl;

  cout << 1[a] << " " << endl;  // same as a[1]


  return 0;
}
