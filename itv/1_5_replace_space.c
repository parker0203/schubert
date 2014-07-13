/*
 * replace all space in a string with "%20"
 * by parker0203
 *
 */


#include <stdio.h>
#include <string.h>

void replace_space(char *str_old, char *str_new){
  int i = 0, j = 0;

  for(i = 0; i < strlen(str_old); ){
    if(str_old[i] == ' '){
      str_new[j++] = '%';
      str_new[j++] = '2';
      str_new[j++] = '0';
      ++i;
    }
    else
      str_new[j++] = str_old[i++];
  }
}


int main(){

  char str_old[] = "Hello world it is great";
  int count_old = strlen(str_old);
  int count_new = count_old;
  for (int i = 0; i < count_old; ++i) // make sure have enough space
    if(str_old[i] == ' ')
      count_new += 2;

  char str_new[count_new];
  //	str_new[count_new] = 0;
  replace_space(str_old, str_new);
  printf("%d %d\n", count_old, count_new);
  printf("%s\n", str_new);

  return 0;
}

