/*
 *
 * determine the number of bits required to convert 
 * by parker0203
 *
 */


#include <iostream>

using namespace std;

bool get_bit(int n, int index){

  return n & (1 << index);
}

void test(){

  int n = 0x8d9;
  cout << get_bit(n, 0);
  cout << get_bit(n, 1);
  cout << get_bit(n, 2);
  cout << get_bit(n, 3);
  cout << get_bit(n, 4);
  cout << endl;

}

int num_convert(int a, int b){

  int res = 0;
  for(int i = 0; i < 32; ++i){
    if(get_bit(a, i) != get_bit(b, i)){
      ++res;
    }
  }
  return res;
}

int num_convert2(int a, int b){

  int res = 0;
  for(int c = a ^ b; c != 0; c = c >> 1){
    res += c & 1;
  }
  return res;
}

int main(){

  int n = 0x8d9;
  test();

  cout << num_convert(31, 14) << endl;
  cout << num_convert2(31, 14) << endl;


  return 0;

}
