/*
 * heap insert and delete min with array
 * start with array[1], not array[0]
 * index == size
 */

#include <iostream>

using namespace std;

enum {SIZE = 30};
int array[SIZE] = {};

void insert_heap(int *array, const int x, int index){
  if(index >= SIZE){
    cout << "out of range" << endl;
  }
  for( ; index > 1 && x < array[index / 2]; index /= 2){
    array[index] = array[index / 2];
  }
  array[index] = x;
}

void delete_min(int *array, int size){
  int hole= 1;
  int child = hole * 2;
  while(hole * 2 <= size){
    child = hole * 2;
    if(child < size && array[child + 1] < array[child]){
      ++child;
    }
    array[hole] = array[child];
    hole = child;
  }
  array[child] = array[size];
}

int main(){
  int index = 1;
  for( ; index < 24; ++index){
    insert_heap(array, index * 5 % 24, index);
  }
  --index;

  for(int i = 1; i < 24; ++i){
    cout << array[i] << " ";
  }
  cout << endl;

  for( ; index > 0; --index){
    cout << array[1] << " ";
    delete_min(array, index);
  }
  cout << endl;
}
