https://leetcode.com/problems/subtree-of-another-tree/
LEETCODE


class Solution {
public:
bool flag=false;

    bool isEqual(TreeNode* root,TreeNode* subroot){
        if(!root && !subroot) return true;
        if(!root || !subroot) return false;
        return root->val==subroot->val && isEqual(root->left,subroot->left) && isEqual(root->right,subroot->right);
    }

    bool search(TreeNode* root,TreeNode* subroot){
        if(!root) return false;
        if(root->val==subroot->val){
            flag= isEqual(root,subroot);
            if(flag) return flag;
        }
        return search(root->left,subroot) || search(root->right,subroot);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return search(root,subRoot);
    }
};
