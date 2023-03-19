struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 

class Solution {
public:
  bool inorder(TreeNode* root, TreeNode* &pre){
    if(!root)   return true;

    // line 7 needs to be able to set 'pre' such that it persists after 
    // this call return, so we need to pass 'prev' by &
    if(!inorder(root->left, pre)){
      return false;
    }
    if(pre && root->val <= pre->val){
      return false;
    }
    pre = root;
    return inorder(root->right, pre);
  }

  bool isValidBST(TreeNode* root) {
    TreeNode* pre = nullptr;
    return inorder(root, pre);
  }
};