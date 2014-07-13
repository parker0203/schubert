/*
 * memset is set every byte, not every bit
 * can used to set 0, or char
 */

#include <stdio.h>
#include <string.h>

int main(){

  int a[5] = {};
  //memset(a, 1, sizeof(a));
  memset(a, 1, sizeof(int));
  int i = 0;
  for(i = 0; i < 5; ++i){
    printf("%d ", a[i]);
  }

    printf("\n");
  
}
