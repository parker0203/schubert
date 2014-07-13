/*
 *  function pointer
 */

#include <stdio.h>

struct A{
  char c;
  double x;
  int array[1];
};

char f() {return 'a';}
char (*fp)() = f;

int foo(double k){}
int (*pfoo)(double k) = foo;

int main(){

  struct A a1;
  printf("size is: %ld\n", sizeof(a1));
  printf("f size is: %ld\n", sizeof(fp));
  printf("pfoo size is: %ld\n", sizeof(pfoo));
  printf("\n");

  char *p;
  char array[20];
  printf("%zd, %zd, %zd\n", sizeof p, sizeof array, sizeof "hello");

  return 0;
}
