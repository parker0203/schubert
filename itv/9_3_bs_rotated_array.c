/*
 *
 * binary search in rotated sorted array
 * assume no duplicated element 
 * by parker0203
 *
 */


#include <stdio.h>

int bin_search(int a[], int element, int left, int right){

  if(left > right) return -1;
  int m = (left + right) / 2;

  if(a[m] == element) return m;

  if(a[m] >= a[left]){
    if(element >= a[left] && element <= a[m]){
      return bin_search(a, element, left, m - 1);
    }else{
      return bin_search(a, element, m + 1, right);
    }
  }else{
    if(element >= a[m] && element <= a[right]){
      return bin_search(a, element, m + 1, right);
    }else{
      return bin_search(a, element, left, m - 1);
    }
  }
}

int main(){

  int a[100];
  int i;
  for(i = 0; i < 100; ++i){
    a[i] = (i + 70) % 100;
    printf("%d ", a[i]);
    if(i % 10 == 9)
      printf("\n");
  }

  int index1 = bin_search(a, 98, 0, 99);
  int index2 = bin_search(a, 10, 0, 99);
  int index3 = bin_search(a, 57, 0, 99);

  printf("%d %d %d\n", index1, index2, index3);
}
