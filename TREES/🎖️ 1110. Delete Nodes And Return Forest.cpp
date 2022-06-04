https://leetcode.com/problems/delete-nodes-and-return-forest/


class Solution {
public:
    
    unordered_map<int,int> m;
    TreeNode* util(TreeNode* root, vector<TreeNode*> &ans)
    {
        if(root==NULL)
            return NULL;
        
        root->left = util(root->left,ans);
        root->right = util(root->right,ans);
        
        if(m.find(root->val)!=m.end())
        {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return NULL;
        }
        else
            return root;
     }
    
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto x:to_delete)
            m[x]++;
        
        vector<TreeNode*> ans;
        
        if(util(root,ans)) ans.push_back(root);
        return ans;
        
        
    }
};
