/*
 *
 * find loop started point using fast and slow runner
 * by parker0203
 *
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}node;

node *create_list(){

  node *temp = NULL;
  for(int i = 9; i >= 0; --i){
    node *head = (node *)malloc(sizeof(node));
    head->data = i;
    head->next = temp;
    temp = head;
  }
  return temp;
}

//make loop with position loop
void make_loop(node *head, int loop){

  if(head == NULL) return;
  node *tail = head;
  while(tail->next){
    tail = tail->next;
  }
  node *temp = head;
  while(--loop && temp){
    temp = temp->next;
  }
  tail->next = temp;
}

void print_list(node *head){

  node *temp = head;
  int max = 30;
  while(temp && --max){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

node *find_loop(node *head){

  if(head == NULL) return NULL;
  node *fast = head;
  node *slow = head;
  // finding catch up point
  while(fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
      break;
    }
  }

  if(fast->next == NULL || fast->next->next == NULL){
    printf("no loop\n");
    return NULL;
  }

  //finding loop start point
  slow = head;
  while(slow != fast){
    slow = slow->next;
    fast = fast->next;
  }

  return fast;
}

int main(){

  node *head = create_list();
  make_loop(head, 8);
  print_list(head);

  node *loop_point = find_loop(head);
  if(loop_point != NULL){
    printf("loop start from %d\n", loop_point->data);
  }
  return 0;
}
