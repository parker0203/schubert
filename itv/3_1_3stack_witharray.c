/*
 *
 * use a single array to implement three stacks
 * by parker0203
 *
 */


#include <stdio.h>


int stack_size = 20;
int stack[60];
int stack_pointer[3] = { -1, -1, -1};

void push_stack(int stack_num, int value){

  if(stack_num > 2) return;
  if(stack_num < 0) return;
  int index = stack_num * stack_size + stack_pointer[stack_num] + 1;
  stack_pointer[stack_num]++;
  stack[index] = value;
}

void pop_stack(int stack_num){

  if(stack_num > 2) return;
  if(stack_num < 0) return;
  int index = stack_num * stack_size + stack_pointer[stack_num];
  int value = stack[index];
  stack_pointer[stack_num]--;
  printf("%d\n", value);
}


void print_stack(){

  for(int i = 0; i < 3; ++i){
    printf("line %d numbers is: ", i);
    for(int j = 0; j <= stack_pointer[i]; ++j){
      printf("%d ", stack[i * stack_size + j]);
    }
    printf("\n");
  }
}

void make_dummy_stack(){

  for(int i = 0; i < 9; ++i){
    push_stack(i % 3, i + 3);
  }
}

int main(){

  make_dummy_stack();
  print_stack();

  pop_stack(2);
  print_stack();
  push_stack(1, 23);
  print_stack();
  push_stack(2, 45);
  print_stack();
  pop_stack(1);
  print_stack();
  push_stack(1, 32);
  print_stack();
  pop_stack(2);
  print_stack();

  return 0;
}
