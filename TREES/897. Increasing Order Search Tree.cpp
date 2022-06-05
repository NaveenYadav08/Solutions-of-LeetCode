
https://leetcode.com/problems/increasing-order-search-tree/

class Solution {
    TreeNode* cur;
    void solve(TreeNode* root){
        if(!root)
            return;
        
        solve(root->left);
        root->left=NULL;
        cur->right=root;
        cur=cur->right;
        
        solve(root->right);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        cur=new TreeNode(0);
        TreeNode* ans = cur;
        solve(root);
        return ans->right;
    }
};
