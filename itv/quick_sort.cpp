/*
 * quick_sort with median pivot
 */

#include <iostream>

using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

int median(int a, int b, int c){
  if((a <= b && b <= c) || (a >= b && b >= c)) return b;
  if((b <= a && a <= c) || (b >= a && a >= c)) return a;
  if((a <= c && c <= b) || (a >= c && c >= b)) return c;
}

// quick_sort, median as pivot
void quick_sort(int *array, int left, int right){
  if(left >= right){ return ;}
  int pivot = median(array[left], array[right], array[(left + right) / 2]);
  int i = left;
  int j = right;
  while(true){
    while(array[i] < pivot) ++i;
    while(array[j] > pivot) --j;
    if(i < j){
      if(array[i] == array[j]){
        --j;
      }else{
        swap(array[i], array[j]);
      }
    }else{
      break;
    }

    quick_sort(array, left, i - 1);
    quick_sort(array, i + 1, right);
  }
}

//quick_sort, first as pivot
void qs_first_as_pivot(int *input, int left, int right){    
  if(left >= right) { return; }
  //swap(input[left], input[right]); // right as pivot
  int pivot = input[left];
  int i = left;
  int j = i + 1;
  for( ; j <= right ; ++j){
    if(pivot > input[j]){
      swap(input[i + 1], input[j]);
      ++i;
    }
  }
  swap(input[left], input[i]);
  qs_first_as_pivot(input, left, i - 1);
  qs_first_as_pivot(input, i + 1, right);    
}

int main(){
  int array[20];
  for(int i = 0; i < 20; ++i){
    array[i] = 25 - i;
    cout << array[i] << " ";
  }
  cout << endl;

  //quick_sort(array, 0, 19);
  qs_first_as_pivot(array, 0, 19);
  for(int i = 0; i < 20; ++i){
    cout << array[i] << " ";
  }
  cout << endl;

}
