/* 
 * If two strings are anagrams or not
 * by parker0203
 *
 */

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
  char temp = *a;
  *a = *b;
  *b = temp;
}

char median(char a, char b, char c){
  if((a <= b && b <= c) || (a >= b && b >= c)) return b;
  if((b <= a && a <= c) || (b >= a && a >= c)) return a;
  if((a <= c && c <= b) || (a >= c && c >= b)) return c;
  return -1;
}

void quick_sort(char *str, int left, int right){
  if(left < right){
    char pivot = median(str[left], str[(left + right) / 2], str[right]);
    int i = left;
    int j = right;
    while(1){
      while(str[i] < pivot) ++i;
      while(str[j] > pivot) --j;
      if(i < j)
        if(str[i] == str[j])
          --j;
        else
          swap(&str[i], &str[j]);
      else 
        break;

    }
    //	swap(&str[i], &str[right - 1]);
    quick_sort(str, left, i - 1);
    quick_sort(str, i + 1, right);

  }
}

int anagram(char *str1, char *str2){
  quick_sort(str1, 0, strlen(str1) - 1);
  quick_sort(str2, 0, strlen(str2) - 1);
  return strcmp(str1, str2);
}

int anagram_2(char *str1, char *str2){

  int i, hash_table[256] = {};
  for(i = 0; i < strlen(str1); ++i)
    ++hash_table[str1[i]];

  for(i = 0; i < strlen(str2); ++i)
    --hash_table[str2[i]];

  for(i = 0; i < 256; ++i)
    if(hash_table[i] != 0) 
      return 1;

  return 0;
}

int main(){

  char str1[] = "abcdfeg";
  char str2[] = "agbcdef";

  //	int result = 0;
  //	str1[3] = 'k';
  if(strlen(str1) != strlen(str2)) return 0;
  int result = anagram_2(str1, str2);
  //	quick_sort(str2, 0, strlen(str2) - 1);
  printf("%s\n", str1);
  printf("%s\n", str2);

  printf("%d\n", result);

  return 0;
}
