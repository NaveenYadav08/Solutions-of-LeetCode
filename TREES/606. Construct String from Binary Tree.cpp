
https://leetcode.com/problems/construct-string-from-binary-tree/

class Solution {
public:
    
    void helper(TreeNode* root, string& ans)
    {
        if(root==NULL) return;
        ans+='(';
        ans+=to_string(root->val);
        if(root->left)
        helper(root->left, ans);
        else if(root->right)
            ans+="()";
        helper(root->right,ans);
        ans+=')';
    }
    
    string tree2str(TreeNode* root) {
        string ans="";
        helper(root, ans);
        ans.pop_back();
        string hmm=ans.substr(1);
        return hmm;
    }
};
