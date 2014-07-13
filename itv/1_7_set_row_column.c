/*
 *
 * set row and column to 0 if one element is 0
 * by parker0203
 *
 */


#include <stdio.h>
#include <string.h> 
void set_zero(int matrix[][5], int n){

  int row[n], column[n];
  memset(row, 0, sizeof(row));
  memset(column, 0, sizeof(column));
  int i, j;
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
      if(matrix[i][j] == 0){
        row[i] = 1;
        column[j] = 1;
      }

  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
      if(row[i] == 1 || column[j] == 1){
        matrix[i][j] = 0;
      }

}

void print_matrix(int matrix[][5], int n){

  int i, j;
  for(i = 0; i < n; ++i){
    for(j = 0; j < n; ++j)
      printf("%d ", matrix[i][j]);
    if(j == n) printf("\n");
  }
  printf("\n");
}

int main(){

  int matrix[][5] = {{1, 2, 3, 4, 5}, 
    {6, 7, 8, 9, 10},
    {11,0,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25}};
  print_matrix(matrix, 5);
  //	rotate_matrix_buffer(matrix, 5);
  set_zero(matrix, 5);
  print_matrix(matrix, 5);


  return 0;
}
