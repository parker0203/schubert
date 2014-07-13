/*
 *
 * print next smaller and next bigger with same number of 1
 * did not use bitset
 * by parker2003
 *
 */



#include <iostream>

using namespace std;

bool get_bit(int n, int index){

  return ((n >> index) & 1);
}

void set_bit(int &n, int index){

  n = n | (1 << index);
}

void reset_bit(int &n, int index){

  n = n & (~(1 << index));
}

void swap_bit(int &n, int index1, int index2){

  if(get_bit(n, index1)){
    if(get_bit(n, index2)){
      return;
    }else{
      reset_bit(n, index1);
      set_bit(n, index2);
    }
  }else{
    if(get_bit(n, index2)){
      set_bit(n, index1);
      reset_bit(n, index2);
    }else
      return;
  }
}

void next_bigger(int &n){

  int i;
  for(i = 0; i < 32; ++i){
    if(get_bit(n, i)){
      for(++i ;i < 32; ++i){
        if(!get_bit(n, i)){
          set_bit(n,i);
          reset_bit(n, i - 1);
          break;
        }
      }
      break;
    }
  }
  for(int j = 0; j < (i - 1) / 2; ++j){
    swap_bit(n, j, i - 2 - j);
  }
}

void next_smaller(int &n){

  int i;
  for(i = 0; i < 32; ++i){
    if(!get_bit(n, i)){
      for(++i; i < 32; ++i){
        if(get_bit(n, i)){
          reset_bit(n, i);
          set_bit(n, i - 1);
          break;
        }
      }
      break;
    }
  }
  for(int j = 0; j < (i - 1) / 2; ++j){
    swap_bit(n, j, i - 2 - j);
  }
}

void test(){

  int n = 0x8d9;
  cout << get_bit(n, 3) << endl;
  cout << get_bit(n, 5) << endl;
  cout << get_bit(n, 6) << endl;
  set_bit(n, 1);
  cout << hex << n << endl;
  set_bit(n, 2);
  cout << n << endl;
  reset_bit(n, 1);
  cout << n << endl;
  reset_bit(n, 2);
  cout << n << endl;

  swap_bit(n, 0, 1);
  cout << n << endl;
  swap_bit(n, 0, 1);
  cout << n << endl;


  cout << endl;
  next_bigger(n);
  cout << n << endl;
  next_smaller(n);
  cout << n << endl;
  next_smaller(n);
  cout << n << endl;

}

int main(){

  test();


  cout << endl;
  int n = 0x1c;
  next_bigger(n);
  cout << n << endl;
  next_smaller(n);
  cout << n << endl;
}

