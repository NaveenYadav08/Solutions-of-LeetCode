https://leetcode.com/problems/delete-nodes-and-return-forest/


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄

class Solution {
    TreeNode* dfs(TreeNode* root, unordered_set<int> &del ,vector<TreeNode*> &ans) {
        if(!root) return nullptr;
        root->left = dfs(root->left, del, ans);
        root->right = dfs(root->right, del, ans);
        if(del.find(root->val) != del.end()) {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return nullptr;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        if(dfs(root, del, ans))
            ans.push_back(root);
        for(auto x:ans)
            cout<<x->val<<endl;
        
        return ans;
    }
};
