https://leetcode.com/problems/flip-equivalent-binary-trees/



█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄



class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        
        if(root1==NULL and root2==NULL) return true;
        if(root1==NULL or root2==NULL) return false;
        
        if(root1->val!=root2->val) return false;
        
        bool cond1=flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
        bool cond2=flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);
        return cond1||cond2;
    }
};

