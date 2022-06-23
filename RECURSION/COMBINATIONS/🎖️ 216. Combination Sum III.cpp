https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    
        vector<bool> used;
        vector<vector<int>> ans;
    
    
    void help(vector<int> &nums, int k, int n, int sum, int i)
    {
        if(i<=10 and sum==n and nums.size()==k)
        {
            ans.push_back(nums);
            return;
        }
        if(i>=10 or sum>=n or nums.size()>=k) return;
        
        help(nums, k, n, sum, i+1);
        if(!used[i])
        {
            used[i]=1;
            nums.push_back(i);
            help(nums, k, n, sum+i, i+1);
            used[i]=0;
            nums.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        used.clear();
        used.resize(11,0);
        ans.clear();
        vector<int> nums;
        int i=0;
        int sum=0;
        help(nums,k,n,sum, 1);
        return ans;
        
    }
};
