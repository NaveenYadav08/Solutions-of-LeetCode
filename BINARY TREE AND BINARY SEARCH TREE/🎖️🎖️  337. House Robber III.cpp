LEETCODE - https://leetcode.com/problems/house-robber-iii/

ALGO 
may or may not include current node
if curr include go to grand child 
if exclude go to the child

█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄


  
  
  class Solution {

private:
    unordered_map<TreeNode*,int>memo;
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        
        if (memo.count(root)){
            return memo[root];
        } 
    
        int ans_including_root = root->val;
    
        if (root->left != NULL) {
              ans_including_root += helper(root->left->left) + helper(root->left->right);
        }
    
        if (root->right != NULL) {
              ans_including_root += helper(root->right->left) + helper(root->right->right);
        }
        
        int ans_excluding_root = helper(root->left) + helper(root->right);
    
        int ans = max(ans_including_root , ans_excluding_root);
        
        memo[root]=ans;
    
        return ans;
   }
    
public:
    int rob(TreeNode* root) {
        return helper(root);
    }    
};
