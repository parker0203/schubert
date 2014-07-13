/*
 *
 * return min and max without if and comparison operator
 * by parker0203
 *
 */



#include <iostream>

using namespace std;


int find_max(int a, int b){

  int c = a - b;
  int k = (c >> 31) & 1;
  return a - k * c;
}

int find_min(int a, int b){

  int c = a - b;
  int k = (c >> 31) & 1;
  return b + k * c;
}

int main(){

  cout << find_max(3, 9) << endl;
  cout << find_min(3, 9) << endl;

  return 0;
}
