/*
 * if you want disable copy ctor,
 * put copy ctor to private
 */

#include <iostream>

using namespace std;

class A{
  public:
    A(int i):a(i){cout << "constructor" << endl;};
    int a;
  private:
    //A(const A &){cout << "copy" << endl;}  //syntax error when not commented out
};

void func(A a){cout << a.a << endl;}

int main(){
  //A a(100);
  //func(a);  // this will call ctor(for temp A(100) ) and then copy ctor(for argument)
  func(100);
}
