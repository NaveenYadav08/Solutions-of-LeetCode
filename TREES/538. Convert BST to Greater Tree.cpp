https://leetcode.com/problems/convert-bst-to-greater-tree/

class Solution {
public:
    void convert(TreeNode* root,int &sum){
        if(root==NULL)
            return;
        convert(root->right,sum);
        sum+=root->val;
        root->val=sum;
        convert(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        convert(root,sum);
        return root;
    }
};
