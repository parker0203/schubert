/*
 * Amazon intership 3rd round phone itv code
 *
 */


#include <iostream>
#include <cmath>

using namespace std;

bool is_jolly_jumper(int *array, int size){
  //if(size == 1) return true;
  if(size == 0) return false;
  if(array == NULL) return false;
  int *hash_table = new int[size]();
  for(int i = 1; i < size; ++i){
    int diff = abs(array[i] - array[i - 1]);
    if(diff > size - 1 || diff == 0) return false;

    ++hash_table[diff];
    if(hash_table[diff] > 1){
      return false;
    }
  }
  return true;
}

int main(){
  int array[4] = {1, 4, 2, 3};
  cout << is_jolly_jumper(array, 4) << endl;
  int array2[4] = {1, 6, 2, 3};
  cout << is_jolly_jumper(array2, 4) << endl;

}
