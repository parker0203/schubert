/*
 *
 * merge array a and b, a has enough buffer
 * by parker0203, solution in career cup
 *
 */


#include <iostream>

using namespace std;

int a[20];
int b[9];

void init_array(){

  for(int i = 0; i < 10; ++i){
    a[i] = i * 3;
    cout << a[i] << " ";
  }
  cout << endl;
  for(int i = 0; i < 9; ++i){
    b[i] = i * 2;
    cout << b[i] << " ";
  }
  cout << endl;
}

//It can merge only when a has enough buffer to restore b
void merge(int a[], int b[], int size_a, int size_b){

  int size_merge = size_a + size_b - 1; //last index
  --size_a;
  --size_b;
  while(size_a >= 0 && size_b >= 0){
    if(a[size_a] > b[size_b]){
      a[size_merge--] = a[size_a--];
    }
    else{
      a[size_merge--] = b[size_b--];
    }
  }

  while(size_b >= 0){ // need not consider size_a, because it is same as size_merge
    a[size_merge--] = b[size_b--];
  }

}

int main(){

  init_array();
  merge(a, b, 10, 9);

  for(int i = 0; i < 19; ++i){
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}
