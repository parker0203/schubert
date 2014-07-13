/*
 * check rotation of substring
 * by parker0203
 *
 */


#include <stdio.h>
#include <string.h>
#include <malloc.h>

int isSubstring(char *str1, char *str2){

  int i = 0, j = 0;
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  while(i < len1 && j < len2){
    if(str1[i] == str2[j]){++i, ++j;}
    else{
      i = i - j + 1;
      j = 0;
    }
  }
  return j == len2;
}

int isRotation(char *str1, char *str2){

  int len1 = strlen(str1);
  int len2 = strlen(str2);
  printf("%s\n", str2);

  if(len1 == len2 && len1 > 0){
    char *strtmp = (char*)malloc(sizeof(char) * len1 * 2);
    strcpy(strtmp, str1);
    strcat(strtmp, str1);
    printf("%s\n", str2);
    printf("%s\n", strtmp);
    return isSubstring(strtmp, str2);
  }
  return 0;
}

int main(){

  char str1[] = "helloworld";
  char str2[] = "oworldhell";

  int isRot = isRotation(str1, str2);
  //	int isSub = isSubstring(str1, str2);

  printf("%d\n", isRot);

  //	printf("%d\n", isSub);

  return 0;
}
