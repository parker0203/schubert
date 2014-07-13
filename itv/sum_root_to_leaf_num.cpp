/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * tested on leetcode
 */

class Solution {
  public:
    int sumNumbers(TreeNode *root) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      if(root == NULL) return 0;
      vector<int> vec;
      push_to_vector(root, 0, vec);
      int sum = 0;
      for(int i = 0; i < vec.size(); ++i){
        sum += vec[i];
      }
      return sum;
    }
    void push_to_vector(TreeNode *node, int parent, vector<int> &vec){
      parent = parent * 10 + node->val;
      if(node->left == NULL && node->right == NULL){
        vec.push_back(parent);
        return;
      }
      if(node->left != NULL){
        push_to_vector(node->left, parent, vec);
      }
      if(node->right != NULL){
        push_to_vector(node->right, parent, vec);
      }
      return;
    }
};
