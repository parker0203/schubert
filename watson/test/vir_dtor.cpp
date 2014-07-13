/*
 * we need virtual distructor, 
 * when delete derived object by base pointer
 */

#include <iostream>

using namespace std;

class A{
  public:
    A(){cout << "A::ctor" << endl;}
    virtual ~A(){cout << "A::~dtor" << endl;}
    //~A(){cout << "A::~dtor" << endl;}
};

class B:public A{
  public:
    B(){cout << "B::ctor" << endl;}
    ~B(){cout << "B::~dtor" << endl;}
};


int main(){
  A *a = new B;
  delete a;
}
