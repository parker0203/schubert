/*
 *
 * return max sum
 * by parker0203
 *
 */



#include <iostream>

using namespace std;

int max_sum(int a[], int size){

  int maxsum = 0;
  int temp = 0;
  for(int i = 0; i < size; ++i){
    temp += a[i];
    if(temp > maxsum){
      maxsum = temp;
    }else if(temp < 0){
      temp = 0;
    }
  }

  return maxsum;
}

int main(){

  int a[] = {2, -8, 3, -2, 4, -10};
  cout << max_sum(a, 6) << endl;

  return 0;
}
