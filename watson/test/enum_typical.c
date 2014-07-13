/*
 * enum typical use
 * it also can used(and it is better) for global const like macro(#define ...)
 */

#include <stdio.h>

typedef enum {red = 1, blue, green = 0, yellow} Color;

int main(){

  Color a = blue;
  printf("%d\n", a);
  Color b = yellow;
  printf("%d\n", b);

  return 0;
}
