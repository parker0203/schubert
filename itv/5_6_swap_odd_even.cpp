/*
 *
 * swap odd and even bit
 * by parker0203
 *
 */


#include <iostream>

using namespace std;


unsigned int swap_odd_even(unsigned int n){

  unsigned int odd = n & 0xaaaaaaaa;
  unsigned int even = n & 0x55555555;

  return ((odd >> 1) | (even << 1));
}

int main(){

  unsigned int n = 0xaaaa5555; // if int, it will keep the most left bit
  unsigned int m = 0x5555aaaa;

  cout << hex << swap_odd_even(n) << endl;
  cout << hex << swap_odd_even(m) << endl;
  //	unsigned int i = 0xffffffff;
  //	cout << (i >> 1) << endl;

  return 0;

}
