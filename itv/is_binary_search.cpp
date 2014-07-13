/*
 * Determine if a Binary Tree is a Binary Search Tree (BST)
 * from leetcode
 */


bool isBSTHelper(BinaryTree *p, int low, int high) {
  if (!p) return true;
  if (low < p->data && p->data < high)
    return isBSTHelper(p->left, low, p->data) && 
      isBSTHelper(p->right, p->data, high);
  else
    return false;
}

bool isBST(BinaryTree *root) {
  // INT_MIN and INT_MAX are defined in C++'s <climits> library
  return isBSTHelper(root, INT_MIN, INT_MAX);  
}


// antoher solution from stackoverflow
IsValidBST(root,-infinity,infinity);

bool IsValidBST(BinaryNode node, int MIN, int MAX) 
{
  if(node == null)
    return true;
  if(node.element > MIN 
      && node.element < MAX
      && IsValidBST(node.left,MIN,node.element)
      && IsValidBST(node.right,node.element,MAX))
    return true;
  else 
    return false;
}
