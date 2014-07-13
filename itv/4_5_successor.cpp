/*
 *
 * find the successor of given node in binary search tree
 * by parker0203
 *
 */



#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

struct tree_node{

  int item;
  tree_node *left;
  tree_node *right;
  tree_node *parent;
  tree_node(int new_item, tree_node *l, tree_node *r, tree_node *p):
    item(new_item), left(l), right(r), parent(p){}
};

void tree_insert(int new_item, tree_node * & t, tree_node * p){

  if(t == NULL){
    cout << "in tree_insert" << endl;
    t = new tree_node(new_item, NULL, NULL, p);
  }else if(new_item < t->item){
    tree_insert(new_item, t->left, t);
  }else if(new_item > t->item){
    tree_insert(new_item, t->right, t);
  }else{
    cout << "duplicated item, just return" << endl;
  }

}

void tree_print(tree_node *t){

  if(t == NULL){
    return;
  }else{
    tree_print(t->left);
    cout << t->item << " ";
    tree_print(t->right);
  }
}

void min_height_tree(int sorted_array[], int first, int last, tree_node * & t, tree_node * p){

  if(first > last) return;

  int mid = (first + last) / 2;
  tree_insert(sorted_array[mid], t, p);
  min_height_tree(sorted_array, first, mid - 1, t->left, t);
  min_height_tree(sorted_array, mid + 1, last, t->right, t);

}

int tree_max_depth(tree_node *t){

  if(t == NULL) return 0;

  return 1 + max(tree_max_depth(t->left), tree_max_depth(t->right));

}

tree_node *tree_most_left(tree_node *t){

  if(t == NULL) return NULL;
  while(t->left != NULL){
    t = t->left;
  }
  return t;
}

tree_node *tree_successor(tree_node *t){

  assert(t != NULL);
  tree_node *p = NULL;
  if(t -> parent == NULL || t->right != NULL){
    p = tree_most_left(t->right);
  }else{
    while((p = t->parent) != NULL){
      if(p->left == t){
        break;
      }
      t = p;
    }
  }
  return p;
}


int main(){

  int a[31];
  for(int i = 0; i < 31; ++i){
    a[i] = i;
  }

  tree_node *root = NULL;
  min_height_tree(a, 0, 30, root, NULL);
  tree_print(root);
  cout << endl;
  cout << "max height is: " << tree_max_depth(root) << endl;

  cout << endl;

  cout << "check the tree" << endl;
  cout << root->left->left->parent->item << endl;
  cout << root->right->right->right->parent->item <<endl;
  cout << root->right->right->left->parent->item <<endl;
  cout << endl;


  cout << "check the successor" << endl;
  cout << tree_successor(root->left->left)->item << endl;
  cout << tree_successor(root)->item << endl;
  cout << tree_successor(root->left->left->left->left)->item << endl;
  cout << tree_successor(root->left->right->right->right)->item << endl;

  if(tree_successor(root->right->right->right->right) == NULL){
    cout << "NULL" << endl;
  }




  return 0;
}
