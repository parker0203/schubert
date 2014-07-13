/*
 *
 * find first common ancestor
 * based on 4_5.cpp
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

bool covers(tree_node *root, tree_node *t){

  if(root == NULL) return false;
  if(root == t) return true;
  return covers(root->left, t) || covers(root->right, t);
}

tree_node *tree_common_ancestor(tree_node *root, tree_node *first, tree_node *second){

  if(covers(root->left, first) && covers(root->left, second)){
    return tree_common_ancestor(root->left, first, second);
  }
  if(covers(root->right, first) && covers(root->right, second)){
    return tree_common_ancestor(root->right, first, second);
  }
  return root;
}

tree_node *LCA(tree_node *root, tree_node *p, tree_node *q) {
  if (!root || !p || !q) return NULL;
  if (max(p->item, q->item) < root->item)
    return LCA(root->left, p, q);
  else if (min(p->item, q->item) > root->item)
    return LCA(root->right, p, q);
  else
    return root;
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

  cout << endl;
  cout << "check the first common ancestor" << endl;
  tree_node *first = root->left->right->left->right; // element 10
  tree_node *second = root->left->right->right->right; // element 14
  tree_node *third = root->left->left->left->right; // element 2 
  tree_node *fourth = root->right->right->left->right; // element 26
  tree_node *fifth = root->right->right->right->right; // element 30

  cout << tree_common_ancestor(root, first, second)->item << endl;
  cout << tree_common_ancestor(root, third, second)->item << endl;
  cout << tree_common_ancestor(root, fourth, fifth)->item << endl;
  cout << tree_common_ancestor(root, first, fourth)->item << endl;


  cout << endl;
  cout << "LCA common ancestor from leetcode" << endl;
  cout << LCA(root, first, second)->item << endl;
  cout << LCA(root, third, second)->item << endl;
  cout << LCA(root, fourth, fifth)->item << endl;
  cout << LCA(root, first, fourth)->item << endl;
  return 0;
}
