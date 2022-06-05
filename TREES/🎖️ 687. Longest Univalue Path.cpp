https://leetcode.com/problems/longest-univalue-path/



// 1- We need to find the longest path containing same value.
// 2- we will make dfs call and check for certain condition -
//  a-  if root is null or (root->left && root->right) null  we will return 0;
// b- if both root left and right are there with all same value as root we will update our answer ans return maximum of (value from left and value from right)+2;
// c- if root and root->left have same value again we will update our answer and return l+1.
// d- if root and root->right have same value again we will update our answer and return r+1.
// else we will return 0;
class Solution {
public:
    int ans=0;
    int solve(TreeNode *root)
    {
        if(!root) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
    if(root->left && root->right && root->val==root->left->val && root->val==root->right->val)
    {
        ans=max(ans,l+r+2);
        return max(l,r)+1;
    }
        else if(root->left && root->val==root->left->val)
        {
            ans=max(ans,l+1);
            return l+1;
        }
        else if(root->right && root->val == root->right->val)
        {
            ans=max(ans,r+1);
            return r+1;
        }
        else 
        {
            ans=max(ans,(max(l,r)));
        }        
    return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        if(!root->left &&!root->right) return 0;
        solve(root);
        return ans;
    }
};
