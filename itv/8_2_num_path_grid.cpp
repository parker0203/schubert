/*
 *
 * number of path in grid
 * by parker0203
 *
 */



#include <iostream>

using namespace std;

int num_path(int x, int y, int num_x, int num_y){

  if((x == num_x) || (y == num_y)){
    return 1;
  }
  return num_path(x + 1, y, num_x, num_y) + num_path(x, y + 1, num_x, num_y);
}

int main(){

  cout << num_path(0, 0, 1, 1) << endl;
  cout << num_path(0, 0, 2, 2) << endl;
  cout << num_path(0, 0, 3, 2) << endl;
  cout << num_path(0, 0, 3, 3) << endl;
  cout << num_path(0, 0, 4, 4) << endl;
  cout << num_path(0, 0, 1, 8) << endl;
  cout << num_path(0, 0, 2, 8) << endl;
  cout << num_path(0, 0, 2, 3) << endl;

  return 0;
}
