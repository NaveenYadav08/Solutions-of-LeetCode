https://leetcode.com/problems/path-sum-iii/

class Solution {
public:
    unordered_map<int,int> mp;
    long long sum = 0;
    int ans=0;
    void findPaths(TreeNode* root, int target){
        if(root==NULL)
            return;
        
        sum+=root->val;
        if(sum==target)
            ans++;
        
        if(mp.find(sum-target)!=mp.end())
            ans+=mp[sum-target];
        
        mp[sum]++;
        findPaths(root->left,target);
        findPaths(root->right,target);
        mp[sum]--;
        sum-=root->val;
        
        if(mp[sum]==0)
            mp.erase(sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        findPaths(root,targetSum);
        return ans;
    }
};
