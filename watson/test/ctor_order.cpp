/*
 * order of calling constructor
 * print below
 
  A::A(11)
  M::M(2)
  M::M(1)
  M::M()
  A::A(0)
  B::B(1234)
  M::operator=(const M &), 0=1
  B::~B(1234)
  A::~A(), val=0
  M::~M(), val=1
  M::~M(), val=1
  M::~M(), val=2
  A::~A(), val=11

 */
  
#include <stdio.h>
struct M {
    M() : val(0) { printf("M::M()\n"); }
    M(int v) : val(v) { printf("M::M(%d)\n", val); }
    M &operator=(const M &m) {
        printf("M::operator=(const M &), %d=%d\n", val, m.val);
        this->val = m.val;
    }
    ~M() { printf("M::~M(), val=%d\n", val); }
    int val;
};

struct A {
    A(int i = 0) : val(i) { printf("A::A(%d)\n", i); }
    ~A() { printf("A::~A(), val=%d\n", val); }
    const int val;
};
struct B : public A {
    B(int i) : A(11), val(i), m1(1), m2(2) {
        printf("B::B(%d)\n", i);
        m3 = m1;
    }
    ~B() { printf("B::~B(%d)\n", val); }
    const int val;
    M m2, m1;
    M m3;
    A a;
};

int main() {
    B b(1234);
}
