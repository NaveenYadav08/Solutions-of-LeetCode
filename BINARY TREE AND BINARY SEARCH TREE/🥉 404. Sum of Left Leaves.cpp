https://leetcode.com/problems/sum-of-left-leaves/




class Solution {
public:
    void helper(TreeNode* root, int &sum)
    {
        if(root==NULL) return;
        
        if(root->left and root->left->left==NULL and root->left->right==NULL)
            sum+=root->left->val;
        helper(root->left,sum);
        helper(root->right,sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        return sum;
    }
};
