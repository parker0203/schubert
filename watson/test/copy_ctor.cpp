#include <iostream>

using namespace std;

class A{
  int a;
  public:
  A(int){cout << "ctor" << endl;} 
  A(const A &rhs){cout << "copy" << endl;}
  A &operator = (const int b){
    cout << "assign" << endl;
  }
};

class B{
  public:
    B() {cout << "B::ctor" << endl;}
    B(const char *) {cout << "B::ctor, const char *" << endl;}
    B &operator=(const char *){
      cout << "B:: assign" << endl;
    }
};	

int main(){

  A a_obj1(10);         /* ctor */
  A a_obj2 = a_obj1;    /* copy */
  A a_obj3 = 5;         /* ctor */

  B b_obj("hello");     /* B::ctor, const char *, syntax error if B constructor not have const char * */

  return 0;
}
