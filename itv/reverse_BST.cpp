/*
 * reverse a BST, left < mid < right -> left > mid > right
 */

#include <iostream>

using namespace std;

void swap(Node *&left, Node *&right){
  Node *temp = left;
  left = right;
  right = temp;
}

void mirror_recursive(Node *root){
  if(root == NULL) return;
  swap(root->left, root->right);
  mirror_recursive(root->left);
  mirror_recursive(root->right);
}

void mirror_itor(Node *root){ // use stack when iteratively reverse
  if(root == NULL) return;
  stack<Node *> buf;
  buf.push_back(root);
  while(!buf.empty()){
    Node *temp = stack.top();
    stack.pop(); // pop return void in c++ STL
    swap(root->left, root->right);
    if(root->left != NULL) buf.push_back(root->left);
    if(root->right != NULL) buf.push_back(root->right);
  }
}
