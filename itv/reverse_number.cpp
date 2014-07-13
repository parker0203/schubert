/*
 * reverse a nunmer
 * from leetcode
 */

#include <iostream>
#include <cassert>

using namespace std;

int reverse_num(int num){
  assert(num >= 0);
  int res = 0;
  while(num != 0){
    res = res * 10 + num % 10;
    num /= 10;
  }
  return res;
}


int main(){
  int test = 123456789;
  int test2 = 120;
  cout << reverse_num(test) << endl;
  cout << reverse_num(test2) << endl;
}
