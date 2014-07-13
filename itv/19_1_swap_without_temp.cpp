/*
 *
 * swap without temporary variables
 * by parker0203
 *
 */



#include <iostream>

using namespace std;

void swap_int(int &a, int &b){

  a = b - a;
  b = b - a;
  a = b + a;
}

void swap_xor(int &a, int &b){

  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

void test(){

  int a = 5, b = 6;
  cout << (a ^ b) << endl;
  cout << (a & b) << endl;
  cout << (a | b) << endl;
}

int main(){

  test();
  int a = 3, b = 4;
  int c = 5, d = 6;

  swap_int(a, b);
  swap_xor(c, d);

  cout << a << " " << b << endl;
  cout << c << " " << d << endl;

  return 0;
}
