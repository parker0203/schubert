/*
 *
 * remove dup in list with c
 * using hash table and no buffer
 * by parker0203
 *
 */


#include <string.h>
#include <stdio.h>
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

void remove_dup_hash(node *head){

  if(head == NULL) return;
  node *temp = head;
  node *temp_next = NULL;
  bool hash_table[256] = {};
  hash_table[head->data] = 1;
  while(temp->next){
    if(hash_table[temp->next->data] == 1){
      temp_next = temp->next;
      temp->next = temp->next->next;
      free(temp_next);
    }
    else{
      hash_table[temp->next->data] = 1;
      temp = temp->next;
    }
  }
}

void remove_dup_nobuffer(node *head){

  if(head == NULL) return;
  node *check = head, *end =head, *temp = NULL;
  while(end->next){
    check = head;
    while(check != end->next){
      if(check->data == end->next->data){
        temp = end->next;
        end->next = end->next->next;
        free(temp);
        break;
      }
      else{
        check = check->next;
      }
    }
    if(check == end->next){  // if removed any, no need to point to next
      end = end->next;
    }
  }
}

int main(){

  char str[] = "Hello WHorld";
  node *head = NULL;
  head = add_sample_char(str);
 	//remove_dup_hash(head);
  remove_dup_nobuffer(head);
  print_list(head);

  return 0;

}
