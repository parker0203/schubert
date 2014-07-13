/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * is a symmetric tree(mirror)
 * tested on leetcode
 */

class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      if(root == NULL) return true;
      return is_mirror(root->left, root->right);
    }
    bool is_mirror(TreeNode *l, TreeNode *r){
      if(l == NULL && r == NULL) return true;
      else if(l == NULL || r == NULL) return false;
      else if(l->val == r->val){
        return is_mirror(l->left, r->right) && is_mirror(l->right, r->left);
      }else return false;
    }
};
