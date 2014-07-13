/*
 * Convert BST to linked list
 * from MS100
 */

// in-order
Node *tree_to_linked_list(Node * root){
  Node *head, *tail;
  helper(head, tail, root);
  return head;
}

void helper(Node * &head, Node * &tail, Node *root){
  Node *lt, *rh; // left tail and right head
  if(root == NULL){
    head = NULL, tail = NULL;
    return;
  }

  helper(head, lt, root->left);
  helper(rh, tail, root->right);

  if(lt != NULL){
    lt->right = root;
    root->left = lt;
  }else{
    head = root;
  }

  if(rh != NULL){
    root->right = rh;
    rh->left = root;
  }else{
    tail = root;
  }

}


////////////// pre-order //////////////
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void tree_to_list(TreeNode *root, TreeNode *&tail){
  if(root == NULL) return;
  TreeNode *ll, *rr;
  ll = root->left, rr = root->right;
  if(tail != NULL){
    tail->right = root;
  }
  root->left = tail;
  tail = root;
  tree_to_list(ll, tail);
  tree_to_list(rr, tail);
}

void flatten(TreeNode *root) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  TreeNode *tail = NULL;
  tree_to_list(root, tail);
}
