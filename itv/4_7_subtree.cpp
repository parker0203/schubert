/*
 *
 * check whether is a sub tree
 * by parker0203
 *
 */



#include <iostream>

using namespace std;

struct tree_node{

  int item;
  tree_node *left;
  tree_node *right;
  tree_node(int new_item, tree_node *l, tree_node *r):
    item(new_item), left(l), right(r){}
};


void tree_insert(int new_item, tree_node * & t){

  if(t == NULL){
    t = new tree_node(new_item, NULL, NULL);
  }else if(new_item < t->item){
    tree_insert(new_item, t->left);
  }else if(new_item > t->item){
    tree_insert(new_item, t->right);
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

void min_height_tree(int sorted_array[], int first, int last, tree_node * & t){

  if(first > last) return;

  int mid = (first + last) / 2;
  tree_insert(sorted_array[mid], t);
  min_height_tree(sorted_array, first, mid - 1, t->left);
  min_height_tree(sorted_array, mid + 1, last, t->right);

}

int tree_max_depth(tree_node *t){

  if(t == NULL) return 0;

  return 1 + max(tree_max_depth(t->left), tree_max_depth(t->right));

}

bool match_tree(tree_node *big_tree, tree_node *sub_tree){

  if(big_tree == NULL && sub_tree == NULL) return true;
  //	if(sub_tree == NULL) return true; //is it a sub tree? // this is wrong, this is match_tree, not sub_tree
  if(big_tree == NULL || sub_tree == NULL) return false;
  if(big_tree->item != sub_tree->item) return false;

  return (match_tree(big_tree->left, sub_tree->left) && 
      match_tree(big_tree->right, sub_tree->right));
}

bool contain(tree_node *big_tree, tree_node *sub_tree){

  if(big_tree == NULL) return false;
  if(sub_tree == NULL) return true; // this line is needed by logical, though check_sub will check sub_tree, but 
  if(big_tree->item == sub_tree->item){
    if(match_tree(big_tree, sub_tree)) return true;
  }

  return (contain(big_tree->left, sub_tree) || contain(big_tree->right, sub_tree));

}

bool check_sub(tree_node *big_tree, tree_node *sub_tree){

  if(sub_tree == NULL) return true;
  else return contain(big_tree, sub_tree);
}


int main(){

  int a[63];
  for(int i = 0; i < 63; ++i){
    a[i] = i;
  }
  tree_node *big_tree = NULL;
  min_height_tree(a, 0, 62, big_tree);
  cout << "first tree info" << endl;
  tree_print(big_tree);
  cout << endl;
  cout << tree_max_depth(big_tree) << endl;
  cout << endl;


  int b[15];
  for(int i = 0; i < 15; ++i){
    b[i] = i;
  }
  tree_node *sub_tree = NULL;
  min_height_tree(b, 0, 14, sub_tree);
  cout << "sub tree info" << endl;
  tree_print(sub_tree);
  cout << endl;
  cout << tree_max_depth(sub_tree) << endl;
  cout << endl;

  tree_node *third_tree = NULL;
  tree_insert(31, third_tree);
  tree_insert(15, third_tree);
  tree_insert(47, third_tree);
  tree_insert(7, third_tree);
  tree_insert(23, third_tree);
  tree_insert(39, third_tree);
  cout << "third tree info" << endl;
  tree_print(third_tree);
  cout << endl;
  cout << tree_max_depth(third_tree) << endl;
  cout << endl;

  int c[15];
  for(int i = 48; i < 63; ++i){
    c[i] = i;
  }
  tree_node *fourth_tree = NULL;
  min_height_tree(c, 48, 62, fourth_tree);
  cout << "fourth tree info" << endl;
  tree_print(fourth_tree);
  cout << endl;
  cout << tree_max_depth(fourth_tree) << endl;
  cout << endl;


  tree_node *fifth_tree = NULL;
  tree_insert(15, fifth_tree);
  tree_insert(31, fifth_tree);
  tree_insert(47, fifth_tree);
  tree_insert(7, fifth_tree);
  tree_insert(23, fifth_tree);
  tree_insert(39, fifth_tree);
  cout << "fifth tree info" << endl;
  tree_print(fifth_tree);
  cout << endl;
  cout << tree_max_depth(fifth_tree) << endl;
  cout << endl;

  if(check_sub(big_tree, fourth_tree)){
    cout << "sub_tree is a sub tree" << endl;
  }else{
    cout << "sub_tree is not a sub tree" << endl;
  }

  if(check_sub(big_tree, third_tree)){ //see check_sub
    cout << "third_tree is a sub tree" << endl;
  }else{
    cout << "third_tree is not a sub tree" << endl;
  }

  if(check_sub(big_tree, fourth_tree)){
    cout << "fourth_tree is a sub tree" << endl;
  }else{
    cout << "fourth_tree is not a sub tree" << endl;
  }

  if(check_sub(big_tree, fifth_tree)){
    cout << "fifth_tree is a sub tree" << endl;
  }else{
    cout << "fifth_tree is not a sub tree" << endl;
  }

  return 0;
}
