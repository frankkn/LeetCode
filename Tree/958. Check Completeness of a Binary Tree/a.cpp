#include <deque>

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

  bool isCompleteTree(TreeNode* root) {
    deque<TreeNode*> q;
    q.push_back(root);
    while(q.front() != nullptr){
      TreeNode* cur = q.front(); q.pop_front();
      q.push_back(cur->left);
      q.push_back(cur->right);
    }
    while(!q.empty() && q.front()== nullptr){
      TreeNode* cur = q.front(); 
      q.pop_front();
    }

    return q.empty();
  }
};