#include <vector>

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
  TreeNode* dfs(vector<int>& inorder, int i_start, int i_end, vector<int>& postorder, int p_start, int p_end){
    if(i_start > i_end || p_start > p_end)  return nullptr;
    
    TreeNode* root = new TreeNode(postorder[p_end]);
    if(p_start == p_end)    return root;
    
    int i = i_start;
    while(inorder[i] != postorder[p_end]) ++i;
    
    root->left = dfs(inorder, i_start, i-1, postorder, p_start, p_start + i-1-i_start);
    root->right =dfs(inorder, i+1, i_end, postorder, p_start + i-1-i_start+1, p_end-1);
    return root;
  }
    
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    return dfs(inorder, 0, n-1, postorder, 0, n-1);
  }
};