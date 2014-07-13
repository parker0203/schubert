/*
 * some exception use
 */

#include <stdio.h>

void foo() {
  throw 1;
}
void goo() {
  try {
    foo();
  } catch (int i) {
    i = 2;
    throw i;
  }
}
int main() {

  //foo(); // terminated if not catched

  try {
    goo();
  } catch (int i) {
    printf("%d\n", i);
  }
}
