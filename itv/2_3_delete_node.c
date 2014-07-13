/*
 *
 * delete a node
 * using list structure
 * by parker0203
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
  char data;
  struct node *next;
}node;

node* add_sample_char(char *str){  //create a list with string

  node *temp = NULL;
  node *head = NULL;
  printf("%s\n", str);
  for(int i = strlen(str) - 1; i >= 0; --i){
    head = (node *)malloc(sizeof(node));
    head->data = str[i];
    head->next = temp;
    temp = head;
  }
  return head;
}

void print_list(node *head){

  node *temp = head;
  while(temp){
    printf("%c", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void delete_node(node *p){

  if(p == NULL || p->next == NULL)
    return;
  node *temp = p->next;
  p->data = temp->data;
  p->next = temp->next;
  free(temp);
}

int main(){

  char str[] = "Hello WHorld";
  node *head = NULL;
  head = add_sample_char(str);
  print_list(head);
  node *temp = head;
  for(int i = 0; i < 7; ++i){
    temp = temp->next;
  }
  delete_node(temp);
  print_list(head);

  return 0;

}

