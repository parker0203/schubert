/*
 * return the max sum
 * checked at leetcode
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max_sum = INT_MIN;
        max_path_sum(root, max_sum);
        return max_sum;
    }
    int max_path_sum(TreeNode *root, int &max_sum){
        if(root == NULL) return 0;
        int left = max_path_sum(root->left, max_sum);
        int right = max_path_sum(root->right, max_sum);
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        if(left + right + root->val > max_sum) max_sum = left + right + root->val;
        if(left > right) return left + root->val;
        else return right + root->val;
        
    }
};
