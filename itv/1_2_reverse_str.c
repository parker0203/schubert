/*
 * reverse the string
 * by parker0203
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_str(char *str){
  char temp;
  char *end = str;
  end +=(int)strlen(str) - 1;

  while(str < end){
    temp = *str;
    *str++ = *end;
    *end-- = temp;
  }
}

int main(){

  char str[] ="hello";
  reverse_str(str);
  printf("%s\n", str);
  return 0;
}
