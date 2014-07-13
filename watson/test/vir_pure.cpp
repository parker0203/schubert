/*
 * pure virtual func
 */

#include <iostream>

using namespace std;

struct Base{
  virtual void func() = 0;
  int a;
};


struct Derived:public Base{
  virtual void func(){
    cout << "Derived" << endl;
  }
};

int main(){

  //Base a;   // syntax error if not commented out
  Derived d;
  d.func();
}
