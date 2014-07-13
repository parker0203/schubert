/*
 * all element of the union declaration
 * occupy the same physical space in memory
 */

#include <iostream>

using namespace std;

int main(){

  union U{
    char c;
    int i;
    char b;
  }my_u;

  my_u.c = 'a';
  cout << my_u.c << " " << my_u.i << " " << my_u.b << endl;  // a 97 a

  my_u.i = 100;
  cout << my_u.c << " " << my_u.i << " " << my_u.b << endl;  // d 100 d

  my_u.b = 'k';
  cout << my_u.c << " " << my_u.i << " " << my_u.b << endl;  // k 107 k

  cout << endl;

  return 0;
}
