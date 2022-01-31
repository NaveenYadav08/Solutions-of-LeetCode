TREE + TWO SUM PROBLEM 


CODE -


class Solution {
public:
    unordered_set<int> m;
    
    void helper(TreeNode* root, int k, bool& ans)
    {   if(root==NULL) return;
        helper(root->left, k, ans);
            if(m.find(k-root->val)!=m.end()) {ans=true;  return;}
            m.insert(root->val);
        helper(root->right, k, ans);
    }
    
    
    bool findTarget(TreeNode* root, int k) {
        m.clear();
        bool ans=false;
        helper(root,k,ans);
        return ans;
    }
};
