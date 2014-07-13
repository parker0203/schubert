/*
 * class name hiding
 */

#include <iostream>

using namespace std;

class Base{
  public:
    void func(double, double){cout << "BASE" << endl;}
    void func(int i, int j){cout << "BASE int" << endl;}
};

class Derived: public Base{
  public:
    using Base::func;
    void func(int i, int j){cout << "DERIVED" << endl;}
};

int main(){

  Derived d;
  d.func(3.14, 3.14);     // BASE 
  d.func(3, 3);           // DERIVED 
}
