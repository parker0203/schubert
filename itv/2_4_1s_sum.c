/*
 *
 * 1's sum, (not consider last flow)
 * by parker0203
 *
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}node;

node *first_list(){

  node *temp = NULL;
  for(int i = 9; i >= 0; --i){
    node *head = (node *)malloc(sizeof(node));
    head->data = i;
    head->next = temp;
    temp = head;
  }
  return temp;
}

node *second_list(){

  node *temp = NULL;
  for(int i = 16; i >= 5; --i){
    node *head = (node *)malloc(sizeof(node));
    head->data = i % 10;
    head->next = temp;
    temp = head;
  }
  return temp;
}

void print_list(node *head){

  node *temp = head;
  while(temp){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

node *add_list(node *first_head, node *second_head, int carry){
  if(first_head == NULL && second_head == NULL)
    return NULL;
  node *added = (node *)malloc(sizeof(node));
  int value = carry;
  if(first_head != NULL){
    value += first_head->data;
  }
  if(second_head != NULL){
    value += second_head->data;
  }
  added->data = value % 10;
  added->next = add_list(first_head == NULL ? NULL : first_head->next,
      second_head == NULL ? NULL : second_head->next,
      value > 10 ? 1 : 0);
  return added;
}

int main(){

  node *first_head = first_list();
  node *second_head = second_list();
  print_list(first_head);
  print_list(second_head);

  node *added_node = add_list(first_head, second_head, 0);
  print_list(added_node);

  return 0;
}
