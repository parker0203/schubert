/*
 *
 * search element in sorted matrix
 * by parker0203
 *
 */


#include <iostream>
#include <utility>

using namespace std;

pair<int, int> p;

void search_sorted_matrix(int a[][5], int element, int row_size, int col_size){

  int row = 0;
  int col = col_size - 1; //search from right top
  while(row < row_size && col >= 0){
    if(a[row][col] == element){
      p = make_pair(row, col);
      return;
    }else if(a[row][col] > element){
      --col;
    }else{
      ++row;
    }
  }

  p = make_pair(-1, -1);
}

void print_matrix(int matrix[][5], int row, int col){

  for(int i = 0; i < row; ++i){
    for(int j = 0; j < col; ++j){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(){

  int matrix[][5] = {{1, 2, 3, 4, 5}, 
    {6, 7, 8, 9, 10},
    {11,12,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25}};
  print_matrix(matrix, 5, 5);
  search_sorted_matrix(matrix, 16, 5,5);
  cout << p.first << " " << p.second << endl;

  return 0;
}
