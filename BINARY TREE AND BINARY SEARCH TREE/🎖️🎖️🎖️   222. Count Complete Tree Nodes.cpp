LEETCODE - https://leetcode.com/problems/count-complete-tree-nodes/



algo    
if curr tree is not flll bt ,  check left and right bt 



█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄





class Solution {
public:
 int countNodes(TreeNode* root) { // o(n)
        if(!root) return 0;
    return countNodes2(root);
        //return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    int countNodes2(TreeNode *root) { // log(n)
        if(!root) return 0;
        int left = 0, right = 0;
        TreeNode *l = root; TreeNode *r = root;
        while(l) l = l->left, left++;
        while(r) r = r->right, right++;
        if(left == right) return pow(2, left) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
