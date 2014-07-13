/*
 *
 * implement  * - / with +
 * by parker0203
 *
 */




#include <iostream>
#include <cassert>

using namespace std;

int nega(int a){

  int d = a < 0 ? 1 : -1;
  int res = 0;
  while(a != 0){
    res += d;
    a += d;
  }

  return res;
}

int myminus(int a, int b){

  a += nega(b);
  return a;
}

int mymulti(int a, int b){

  if(a == 0 || b == 0) return 0;
  if(b < 0){
    int d = 1;
    a = nega(a);
    int tmp = a;
    while(b != -1){
      a += tmp;
      b += d;
    }
  }else if(b > 0){
    int d = -1;
    int tmp = a;
    while(b != 1){
      a += tmp;
      b += d;
    }
  }

  return a;
}

int abs(int a){

  if(a < 0) return nega(a);
  else return a;
}

int mydevide(int a, int b){

  assert(b != 0);
  if(a == 0) return 0;
  int a_devide = abs(a);
  int b_devide = abs(b);
  int temp = b_devide;
  int i = 0;

  while(a_devide >= b_devide){
    b_devide += temp;
    i += 1;
  }

  if(mymulti(a, b) > 0) return i;
  else return nega(i);
}


int main(){

  cout << myminus(10, -7) << endl;
  cout << endl;

  cout << mymulti(10, -7) << endl;
  cout << mymulti(-10, 7) << endl;
  cout << mymulti(10, 7) << endl;
  cout << mymulti(-10, -7) << endl;
  cout << endl;

  cout << mydevide(10, -2) << endl;
  cout << mydevide(-10, 2) << endl;
  cout << mydevide(10, 2) << endl;
  cout << mydevide(-10, -2) << endl;
  cout << endl;


  return 0;
}
