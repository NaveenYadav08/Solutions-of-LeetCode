https://leetcode.com/problems/minimum-depth-of-binary-tree/


Here we can't do normal like max depth because   for left skew and right skew it will give 0 but ans in that case is length of tree
  


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        if(root->left == NULL) return (1 + minDepth(root->right));
        if(root->right == NULL) return (1 + minDepth(root->left));
        return (1 + min(minDepth(root->left), minDepth(root->right)));
    }
};

