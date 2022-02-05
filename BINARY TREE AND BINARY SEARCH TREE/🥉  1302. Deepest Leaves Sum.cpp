https://leetcode.com/problems/deepest-leaves-sum/




█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄



class Solution {
public:
    int helper(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        int l=helper(root->left);
        int r=helper(root->right);
        return max(l,r)+1;
    }
    
    void keeper(TreeNode* root, int hgt, int &sum)
    {
        if(root==NULL) return;
        
        //cout<<hgt<<" "<<root->val<<endl;
        if(hgt==1) {sum+=root->val; return;}
        
        keeper(root->left,hgt-1,sum);
        keeper(root->right,hgt-1,sum);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int hgt=helper(root);
        
        int sum=0;
        keeper(root,hgt,sum);
        return sum;
        
    }
};
