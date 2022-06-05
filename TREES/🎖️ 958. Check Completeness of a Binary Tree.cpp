https://leetcode.com/problems/check-completeness-of-a-binary-tree/

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool end=false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* r=q.front();
            q.pop();
            if(!r) end=true;
            else if(end) return false;
            if(r){
                q.push(r->left);
                q.push(r->right);
            }
            
        }
        return true;
    }
};
