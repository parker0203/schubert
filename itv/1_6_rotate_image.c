/*
 * Rotate image by 90 degrees
 * by parker0203
 *
 */


#include <stdio.h>

void rotate_matrix(int matrix[][5], int n){

  int i, j, temp;
  for(i = 0; i < n / 2; ++i){
    for(j = i; j < n - 1 - i; ++j){
      temp = matrix[i][j];
      matrix[i][j] = matrix[n - 1 - j][i];
      matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
      matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
      matrix[j][n - 1 - i] = temp;

    }
  }
}

void rotate_matrix_buffer(int matrix[][5], int n){

  int temp[n*n];
  int i, j, k = 0;
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
      temp[k++] = matrix[i][j];

  k = 0;
  for(j = n - 1; j >= 0; --j)
    for(i = 0; i < n; ++i)
      matrix[i][j] = temp[k++];
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
    {11,12,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25}};
  print_matrix(matrix, 5);
  //	rotate_matrix_buffer(matrix, 5);
  rotate_matrix(matrix, 5);
  print_matrix(matrix, 5);


  return 0;
}
