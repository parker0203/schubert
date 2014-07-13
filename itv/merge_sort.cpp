/*
 * merge sort
 */

#include <iostream>
#include <string>

using namespace std;

void merge(int* input, int low, int high){
  int left_end = ((low + high) / 2);
  int i = 0; // temp index
  int left = low;
  int right = left_end + 1;

  // Temp array
  int temp[high - low + 1];

  while(left <= left_end && right <= high){
    if(input[left] < input[right]){
      temp[i++] = input[left++];
    }else{
      temp[i++] = input[right++];
    }
  }

  while(left <= left_end){
    temp[i++] = input[left++];
  }

  while(right <= high){
    temp[i++] = input[right++];
  }

  for(i = low; i < high + 1; ++i){
    input[i] = temp[i - low]; 
  }
}


//merge sort function
void merge_sort(int* input, int low, int high){
  if (low < high){
    int mid = ((low + high) / 2);
    merge_sort(input, low, mid);
    merge_sort(input, mid + 1, high);
    merge(input, low, high);
  }

}

/*
void merge(int *array, int *res, int left, int right, int right_end){
  int left_end = right - 1;
  int temp = left;
  int size = right_end - left + 1;

  while(left <= left_end && right <= right_end){
    if(array[left] <= array[right]){
      res[temp++] = array[left++];
    }else{
      res[temp++] = array[right++];
    }
  }

  while(left <= left_end){
    res[temp++] = array[left++];
  }

  while(right <= right_end){
    res[temp++] = array[right++];
  }

  for(int i = 0; i < size; ++i, right_end--){
    array[right_end] = res[right_end];
  }
}

void merge_sort(int *array, int *res, int left, int right){
  if(left < right){
    int center = (left + right) / 2;
    merge_sort(array, res, left, center);
    merge_sort(array, res, center + 1, right);
    merge(array, res, left, center + 1, right);
  }
}

*/
int main(){
  int a[20];
  for(int i = 0; i < 20; ++i){
    a[i] = 30 - i;
    cout << a[i] << " ";
  }
  cout << endl;

  merge_sort(a, 0, 19);
  for(int i = 0; i < 20; ++i){
    cout << a[i] << " ";
  }
  cout << endl;
}
