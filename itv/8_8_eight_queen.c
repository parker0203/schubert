/*
 *
 * Eight queen problem, using recursive method
 * by parker0203, solution with career cup
 *
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int column_row[8];
int num = 0;

int check_column(int row){

  for(int i = 0; i < row; ++i){
    int diff = abs(column_row[row] - column_row[i]);
    if(diff == 0 || diff == row - i){
      return 0;
    }
  }
  return 1;
}

void print_column(int num){

  printf("The %dth way is:", num);
  for(int i = 0; i < 8; ++i){
    printf("%d ", column_row[i]);
  }
  printf("\n");
}

void place_queen(int row){

  if(row == 8){
    print_column(++num);
    return;
  }

  for(int i = 0; i < 8; ++i){
    column_row[row] = i;
    if(check_column(row)){
      place_queen(row + 1);
    }
  }
}


int main(){

  place_queen(0);

  return 0;
}
