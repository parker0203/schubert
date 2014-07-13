/*
 * When a array as a argument, the size is not checked
 * In main b and c pass as pointer
 */


//#include <iostream>
#include <stdio.h>

//using namespace std;

void func(int a[10]){
  //cout << "in func" << endl;
  printf("in func\n");
}

int main(){
  int b[10];
  int c[9];
  
  func(b);
  func(c);
  
  return 0;
}
