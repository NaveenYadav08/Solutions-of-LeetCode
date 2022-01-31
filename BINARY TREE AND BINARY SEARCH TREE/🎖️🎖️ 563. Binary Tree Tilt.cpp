LEETCODE -
  https://leetcode.com/problems/binary-tree-tilt/

it is similar to the sum tree



class Solution {
public:
 
int ans=0;
int helper(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int l=helper(root->left);
        int r=helper(root->right);
        
        int sum=root->val + l + r;
        root->val=abs(l-r);
        ans+=root->val;
       
        return sum;
        
    }
    
    
int findTilt(TreeNode* root) {
        helper(root);
        return ans;
    }
};
