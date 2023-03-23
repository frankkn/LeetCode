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
  TreeNode* dfs(vector<int>& preorder, int pr_start, int pr_end, vector<int>& postorder, int po_start, int po_end){
    if(pr_start > pr_end || po_start > po_end)  return nullptr;
    
    TreeNode* root = new TreeNode(preorder[pr_start]);
    if(pr_start == pr_end)  return root;
    
    int i = po_start;
    while(postorder[i] != preorder[pr_start+1]) ++i;
    
    root->left = dfs(preorder, pr_start+1, pr_start+1+ i-po_start, postorder, po_start, po_start+i-po_start);
    root->right = dfs(preorder, pr_start+1+ i-po_start+1, pr_end, postorder, i+1, po_end-1);
    return root;
  }
  
  TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n = preorder.size();
    return dfs(preorder, 0, n-1, postorder, 0, n-1);
  }
};