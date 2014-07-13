/*
 *
 * create a binary tree with min height with given sorted array
 * by parker0203
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct bi_node{
  int value;
  bi_node *left;
  bi_node *right;
};

void min_height_tree(int sorted_array[], int first, int last, bi_node * & root){

  if(first > last) return;

  int mid = (first + last) / 2;
  bi_node *t = new bi_node;
  t->value = sorted_array[mid];
  root = t;
  min_height_tree(sorted_array, first, mid - 1, root->left);
  min_height_tree(sorted_array, mid + 1, last, root->right);
}

void print_tree(bi_node *root){

  if(root == NULL) return;

  print_tree(root->left);
  cout << root->value << " ";
  print_tree(root->right);

}

int max_tree_height(bi_node *t){

  if(t == NULL) return 0;

  return 1 + max(max_tree_height(t->left), max_tree_height(t->right));
}

int main(){

  int a[31];
  for(int i = 0; i < 31; ++i){
    a[i] = i;
  }

  bi_node *root;
  min_height_tree(a, 0, 30, root);
  print_tree(root);
  cout << endl;

  cout << "height is: " << max_tree_height(root) << endl;

  return 0;
}
