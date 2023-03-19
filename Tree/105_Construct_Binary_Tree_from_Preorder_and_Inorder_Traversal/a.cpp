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
  TreeNode* dfs(vector<int>& preorder, int p_start, int p_end, vector<int>& inorder, int i_start, int i_end){
    if(i_start > i_end || p_start > p_end) return nullptr;
    
    TreeNode* root = new TreeNode(preorder[p_start]);
    if(p_start == p_end)    return root;
    
    int i = i_start;
    while(inorder[i] != preorder[p_start]){
        ++i;
    }
    
    root->left = dfs(preorder, p_start+1, p_start+1+i-1-i_start, inorder, i_start, i-1);
    root->right = dfs(preorder, p_start+1+i-1-i_start+1, p_end, inorder, i+1, i_end);
    return root;
  }
  
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    return dfs(preorder, 0, n-1, inorder, 0, n-1);
  }
};