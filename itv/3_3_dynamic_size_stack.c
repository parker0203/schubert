/*
 *
 * increase stack size when over flow, using array pointer
 * by parker0203
 * 
 * memory leak because some element still in stack, if pop all, then no memory leak
 *
 * if we need to add popAt(int index), we just need to make the pointer
 * point the related stacks, and using stack_pointer as stack index
 *
 */



#include <stdio.h>
#include <stdlib.h>

//#define STACK_SIZE 10

enum {STACK_SIZE = 10};

int pointer = 9;
int stack_pointer = -1;
int *stacks[10];

void push_stack(int val){

  if(pointer == 9){
    stacks[++stack_pointer] = (int *)malloc(sizeof(int) * STACK_SIZE);
    pointer = -1;
    printf("next to %dth stack\n", stack_pointer);
  }

  stacks[stack_pointer][++pointer] = val;
}

int pop_stack(){

  if(stack_pointer < 0){
    printf("no element\n");
    return -1;
  }
  int val = stacks[stack_pointer][pointer--];
  if(pointer == -1){
    free(stacks[stack_pointer]);
    --stack_pointer;
    pointer = 9;
    printf("back to %dth stack\n", stack_pointer);
  }
  return val;
}

int main(){

  int i;
  for(i = 0; i < 35; ++i){
    push_stack(i);
  }
  for(i = 0; i < 16; ++i){
    printf("%d ", pop_stack());
  }
  printf("\n");

  return 0;
}

