/*
 * the catched reference is not the same address
 */

#include <iostream>

using namespace std;

void foo(){
  throw 10;
  cout << "here" << endl;
}

int main(){
  try{
  foo();
  
  cout << "end " << endl;
  }catch(int a){
    cout << a << endl;
  }
  
  try{
    int a;
    cout << &a << endl;
    throw a;
  }catch(int &a){
    cout << &a << endl; // different to above address
  }
  
}
