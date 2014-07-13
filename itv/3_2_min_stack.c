/*
 *
 * return min in stack, using restore min every step
 * this solution waste space, we can improve using only store min value in min stack (this will add some op in pop)
 * by parker0203
 * 
 */



#include <stdio.h>

//#define stack_size  100

enum {stack_size = 100};

int mystack[stack_size];
int mymin[stack_size];
int stack_pointer = -1;


void push_stack(int val){

  if(stack_pointer == stack_size - 1){
    printf("no space to restore element\n");
    return;
  }
  mystack[++stack_pointer] = val;
  if(stack_pointer == 0){                // the first element
    mymin[stack_pointer] = val;
  }else if(mymin[stack_pointer - 1] > val){
    mymin[stack_pointer] = val;
  }else{
    mymin[stack_pointer] = mymin[stack_pointer - 1];
  }
}

int pop_stack(){

  if(stack_pointer < 0){
    printf("no any element in stack\n");
    return 0;
  }
  return mystack[stack_pointer--]; 
}

int display_min(){

  return mymin[stack_pointer];
}

void print_stack(){

  for(int i = 0; i <= stack_pointer; ++i){
    printf("%d ", mystack[i]);
  }
  printf("\n");
}

int main(){

  for(int i = 1; i < 10; ++i){
    push_stack(i * 7 % 10);
  }
  print_stack();
  printf("%d \n", stack_pointer);
  for(int i = 1; i < 9; ++i){
    printf("%d ", pop_stack());
    printf("min is: %d\n", display_min());
  }

  return 0;
}
