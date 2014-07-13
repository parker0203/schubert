#include <stdio.h>

#define COLORS \
  T(RED),\
  T(GREEN),\
  T(BLUE)

#undef T
#define T(c) c##_C
typedef enum {COLORS} Color;

#undef T
#define T(c) #c
const char *colors[] = {COLORS};

int main(){

  Color c = BLUE_C;
  printf("c = %d\n", c);

  return 0;
}
