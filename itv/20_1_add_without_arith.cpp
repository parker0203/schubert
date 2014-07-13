/*
 *
 * add without arithmetic
 * by parker0203
 *
 */


#include <iostream>

using namespace std;

int add_without_arithm(int a, int b){

  if(b == 0) return a;
  int sum = a ^ b;
  int carry = (a & b) << 1;
  return add_without_arithm(sum, carry);
}

int main(){

  int a = 749, b = 9823;
  cout << add_without_arithm(a, b) << endl;
  cout << a + b << endl;

  return 0;
}
