in constanat space not usig hashmap
https://leetcode.com/problems/find-mode-in-binary-search-tree/

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int mxFreq=INT_MIN;
        int cnt=0;
        int prev=-1;
        inorder(root,ans,mxFreq,cnt,prev);
        return ans;
    }
    void inorder(TreeNode* root,vector<int> &ans,int &mxFreq,int &cnt,int &prev){
        if(root==NULL)return;
        inorder(root->left,ans,mxFreq,cnt,prev);
        if(root->val==prev)cnt++;
        else cnt=1;
        
        if(cnt>mxFreq){
            ans.clear();
            ans.push_back(root->val);
            mxFreq=cnt;
        }
        else if(cnt==mxFreq)
            ans.push_back(root->val);
        prev=root->val;
        inorder(root->right,ans,mxFreq,cnt,prev);
    }
};
