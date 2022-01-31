https://leetcode.com/problems/path-sum-iii/
LEETCODE 


▄▀█ █░░ █▀▀ █▀█
█▀█ █▄▄ █▄█ █▄█

I know how to find target sum root to leaf so for ths consider each node as your root node.



█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄


class Solution {
public:
    int cnt = 0;
    void helper(TreeNode *root, int targetSum) {
        if (root == NULL) {
            return;
        }
       
        if (targetSum == root->val) {
            cnt++;
        }
        helper(root->left, targetSum - root->val);
        helper(root->right, targetSum - root->val);
    }
    
    void Func(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return;
        }
        if ((root->left == NULL) && (root->right == NULL) && (root->val != targetSum)) {
            return;
        }

        helper(root, targetSum);
        Func(root->left, targetSum);
        Func(root->right, targetSum);
    }
    
// FUNCTION //    
    int pathSum(TreeNode* root, int targetSum) {
        Func(root, targetSum);
        return cnt;
    }
    
};
