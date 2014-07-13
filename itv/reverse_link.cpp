/*
 * reverse link
 */

Node *reverse_1(Node *x){ 
  Node *t, *y = x, *r = NULL;  // r, y, t
  while(y != NULL){
    t = y->next;
    y->next = r;
    r = y;
    t = t;
  }
  return r;
}

Node *reverse_2(Node *head){
  if(head == NULL) return head;
  if(head->next == NULL) return head;
  Node *ph = reverse(head->next);
  head->next->next = head;
  head->next = NULL;
  return ph;
}

Node *reverse_3(Node *head){
  if(head == NULL) return head;
  Node *p = head;
  Node *previous = NULL;
  while(p->next != NULL){
    p->next = previous;
    previous = p;
    p = p->next;
  }
  p->next = previous;
  return p;
}
