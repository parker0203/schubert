/*
 * some virtual function use
 */

#include <stdio.h>


class Base {
  public:
    virtual void foo() { printf("Base\n"); }
};
class Derived : public Base {
  public:
    virtual void foo() { printf("Derived\n"); }
};

int main(){
  Derived d;
  Base b;
  Base &br1(d), &br2(b), *bp = 0;
  bp = &b;
  bp->foo();  //Base
  bp = &d;
  bp->foo();  //Derived
  bp->Base::foo(); //Base
  br1.foo();  //Derived
  br2.foo();  //Base

}
