/*
 * find two element sum to certain sum
 * if have many pairs, then just out put any one
 */

#include <iostream>
#include <cstdlib>

using namespace std;

void find_sum(int *array, int size, int sum){
  int left = 0, right = size - 1;
  int temp_sum = array[left] + array[right];
  while(temp_sum != sum && left < right){
    if(temp_sum > sum){
      temp_sum = array[left] + array[--right];
    }else{
      temp_sum = array[++left] + array[right];
    }
  }
  if(left != right){ // (sum == temp_sum) it is not correct when left == right, eg(sum = 22, left == right and array[left] == 11)
    cout << array[left] << " " << array[right] << endl;
  }
}

int main(){
  int array[15];
  for(int i = 0; i < 15; ++i){
    array[i] = i * 7 + rand() % 7;
    cout << array[i] << " ";
  }
  cout << endl;

  find_sum(array, 15, 106);
  find_sum(array, 15, 55);
}
