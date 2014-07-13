/*
 *
 * get random set in array
 * by parker0203
 *
 */


#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int &a, int &b){

  int temp = a;
  a = b;
  b = temp;
}

int *rand_set(int a[], int a_size, int set_size){

  if(a_size < set_size) return NULL;

  int temp[a_size];
  for(int i = 0; i < a_size; ++i){
    temp[i] = a[i];
  }
  int *res = new int[set_size];
  int element;
  for(int i = 0; i < set_size; ++i){
    element = rand() % (a_size - i) + i;
    res[i] = a[element];
    swap(a[i], a[element]);
  }

  return res;
}

int main(){

  srand(time(NULL));
  int origin[20];
  for(int i = 0; i < 20; ++i){
    origin[i] = rand() % 100;
    cout << origin[i] << " ";
    if(i % 10 == 9){
      cout << endl;
    }
  }
  cout << endl;

  int *res;
  res = rand_set(origin, 20, 10);
  for(int i = 0; i < 10; ++i){
    cout << res[i] << " ";
    if(i % 10 == 9){
      cout << endl;
    }
  }


  return 0;
}
