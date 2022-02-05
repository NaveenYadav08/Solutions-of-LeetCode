https://leetcode.com/problems/binary-tree-pruning/


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄



class Solution {

    // TC : O(n)
    // SC : O(H = logn)
    public:
    
    bool canDeleteNode(TreeNode* root){
        if(root->left == NULL && root->right == NULL && root->val == 0){
            return true;
        } else {
            return false;
        }
    }
    
    
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (canDeleteNode(root)) return NULL;
        return root   ;
    }

};
