LLETCODE 
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

TREE + BACKTRACKING


░█████╗░░█████╗░██████╗░███████╗
██╔══██╗██╔══██╗██╔══██╗██╔════╝
██║░░╚═╝██║░░██║██║░░██║█████╗░░
██║░░██╗██║░░██║██║░░██║██╔══╝░░
╚█████╔╝╚█████╔╝██████╔╝███████╗
░╚════╝░░╚════╝░╚═════╝░╚══════╝

class Solution {
public:
    void helper(TreeNode* root, string ans, vector<string>& storage)
    {
        if(root==NULL) {return;}
        
        ans+=root->val==1?'1':'0';
        if(root->left==NULL and root->right==NULL) storage.push_back(ans);
        helper(root->left,ans,storage);
        helper(root->right,ans,storage);
        ans.pop_back();
    }
    
    int sumRootToLeaf(TreeNode* root) {
        string ans="";
        vector<string> storage;
        helper(root, ans, storage);
        // for(auto x:storage)
        //     cout<<x<<" ";
        // cout<<endl;
        
        int ANS=0;
        for(auto x:storage)
        {
            string z=x;
            int pp=0;
            for(int i=z.size()-1;i>=0;i--)
            {
                ANS+=z[i]=='1'?(1<<pp):0;
                pp++;
            }
            //cout<<endl;
        }
        return ANS;
        
        
        
    }
};
