/*
 * add two list
 * checked on leetcode
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// recursive solution
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      if(l1 == NULL) return l2;
      if(l2 == NULL) return l1;
      add_list(l1, l2, 0);
      return l1;
    }
    void add_list(ListNode *L1, ListNode *L2, int carry){
      carry = L1->val + L2->val + carry;
      L1->val = L2->val = carry % 10;
      carry /= 10;
      if(L1->next == NULL && L2->next == NULL && carry == 0) return;
      else{
        if(L1->next == NULL) L1->next = new ListNode(0);
        if(L2->next == NULL) L2->next = new ListNode(0);
      }
      add_list(L1->next, L2->next, carry);
    }
};

// iterative solution
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      if(l1 == NULL) return l2;
      if(l2 == NULL) return l1;
      ListNode *L1 = l1, *L2 = l2;
      int carry = 0;
      while(1){
        carry = L1->val + L2->val + carry;
        L1->val = L2->val = carry % 10;
        carry /= 10;
        if(L1->next == NULL && L2->next == NULL && carry == 0) break;
        else{
          if(L1->next == NULL) L1->next = new ListNode(0);
          if(L2->next == NULL) L2->next = new ListNode(0);
        }
        L1 = L1->next;
        L2 = L2->next;
      }
      return l1;
    }
};
