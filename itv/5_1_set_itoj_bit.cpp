/*
 *
 * set N from position i to j with N
 * by parker0203
 *
 */



#include <iostream>
#include <bitset>

using namespace std;

void set_bit(int N, int M, int i, int j){

  if(i > 32 || j > 32){
    cout << "the bit position bigger than 32" << endl;
    return;
  }
  if(i > j){
    cout << "i is bigger than j" << endl;
    return;
  }

  int set_pos = (0xFFFFFFFF << j + 1) | (0xFFFFFFFF >> (32 - i));
  cout << hex << set_pos << endl;
  N = N & set_pos;
  cout << N << endl;

  M = M << i;
  cout <<  M << endl;

  int res = N | M;
  cout << res << endl;

}

void set_bitset(bitset<32> N, bitset<32> M, int i, int j){

  if(i > 32 || j > 32){
    cout << "the bit position bigger than 32" << endl;
    return;
  }
  if(i > j){
    cout << "i is bigger than j" << endl;
    return;
  }
  for(int a = i; a <= j; ++a){
    N.reset(a);
  }

  cout << N << endl;
  M = M << i;
  cout << M << endl;
  N = N | M;
  cout << N << endl;
}


int main(){

  cout << sizeof(int) << endl;
  cout << sizeof(char) << endl;

  int N = 0x404;
  int M = 0x15;
  set_bit(N, M, 2, 6);
  cout << endl;

  bitset<32> n(N);
  cout << n << endl;
  bitset<32> m(M);
  cout << m << endl;
  set_bitset(n, m, 2, 6);

  return 0;
}
