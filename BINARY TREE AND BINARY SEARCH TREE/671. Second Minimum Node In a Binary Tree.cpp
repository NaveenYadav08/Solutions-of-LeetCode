https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

CODE 

class Solution {
public:
    void helper(TreeNode* root, long& min1, long& min2)
    {
        if(root==NULL) return;
        min1 = min(min1,(long)root->val);
        long jj=min(min2,max(min1,(long)root->val));
        if(jj!=min1)
            min2=jj;
        
        helper(root->left, min1, min2);
        helper(root->right, min1, min2);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        long  min1=LONG_MAX;
        long min2=LONG_MAX;
        helper(root,min1,min2);
        cout<<min1<<" "<<min2<<endl;
        if(min2==LONG_MAX)
            return -1;
        return (int)min2;
    }
};
