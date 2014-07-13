/*
 *
 * check whether the tree is balanced
 * by parker0203
 *
 */


#include <iostream>
#include <algorithm>

using namespace std;

struct bi_node{
  int item;
  bi_node *left;
  bi_node *right;
  bi_node(int new_item, bi_node *l, bi_node *r):
    item(new_item), left(l), right(r){}

};

// assume no duplicated element in the tree
class bi_search_tree{


  public:
    bi_node *root;
    bi_search_tree();
    //		~bi_search_tree();

    //		T find_min();
    //		T find_max();
    //		bool is_empty();
    void print_tree(bi_node * & t);
    void insert(int, bi_node * & t);
    int max_depth(bi_node * t);
    int min_depth(bi_node * t);
    //		void remove(T);

};

bi_search_tree::bi_search_tree(){
  root = NULL;
}

void bi_search_tree::insert(int new_item, bi_node * & t){

  if(t == NULL){
    t = new bi_node(new_item, NULL, NULL);
  }else if(new_item < t->item){
    insert(new_item, t->left);
  }else if(new_item > t->item){
    insert(new_item, t->right);
  }else{
    cout << "duplicated item, just return" << endl;
  }
}

void bi_search_tree::print_tree(bi_node * & t){

  if(t == NULL){
    //cout << "no any element in tree" << endl;
    return;
  }else{
    print_tree(t->left);
    cout << t->item << endl;
    print_tree(t->right);
  }

}

int bi_search_tree::max_depth(bi_node *t){

  if(t == NULL) return 0;

  return 1 + max(max_depth(t->left), max_depth(t->right));
}

int bi_search_tree::min_depth(bi_node *t){ // not correct, see below leetcode version

  if(t == NULL) return 0;

  return 1 + min(min_depth(t->left), min_depth(t->right));
}

/**
 * leetcode, the balanced condition is slightly different to careercup 4.1 
 * checked at leetcode online judge
 * 
 * A height-balanced binary tree is defined as a binary tree in which 
 * the depth of the two subtrees of every node never differ by more than 1.
 * That means {1,2,2,3,3,3,3,4,4,4,4,4,4,#,#,5,5} is a balanced tree
 * but using above solution, it returns false
 *
 * Definition for binary tree
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    bool isBalanced(TreeNode *root) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      if(root == NULL) return true;
      if(abs(max_depth(root->left) - max_depth(root->right)) < 2){
        return isBalanced(root->left) && isBalanced(root->right);
      }
      return false;
    }
    int max_depth(TreeNode *root){
      if(root == NULL) return 0;
      return 1 + max(max_depth(root->left), max_depth(root->right));
    }

};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * min depth of tree
 * careercup is not correct
 */
class Solution {
  public:
    int minDepth(TreeNode *root) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      if(root == NULL) return 0;
      if(root->left == NULL && root->right != NULL)
        return 1 + minDepth(root->right);   // if the node have child, it is not leaf so the depth is going on
      else if(root->left != NULL && root->right == NULL)
        return 1 + minDepth(root->left);
      else return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
///////////////////// leetcode end ////////////////////////////////////////




int main(){

  bi_search_tree my_tree;
  my_tree.insert(10, my_tree.root);
  my_tree.insert(7, my_tree.root);
  my_tree.insert(14, my_tree.root);
  my_tree.insert(2, my_tree.root);
  my_tree.insert(1, my_tree.root);


  //	cout << "main" << my_tree.root->item << endl;
  cout << "max depth is:" << my_tree.max_depth(my_tree.root) << endl;
  cout << "min depth is:" << my_tree.min_depth(my_tree.root) << endl;

  my_tree.print_tree(my_tree.root);

  return 0;
}
