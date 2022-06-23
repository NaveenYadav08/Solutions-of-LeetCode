https://leetcode.com/problems/combination-sum/

Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
  
  
  
class Solution {
public:
    
void helper(vector<vector<int>>& ans, vector<int>& nums, int i, int sum, int &target, vector<int> &cand)
    {
        
        if(i<=cand.size() and target==sum)
        {
            ans.push_back(nums);
            return;
        }
        
        if(i>=cand.size() or sum>target) return;
        
        helper(ans, nums, i+1, sum, target, cand);
    
        nums.push_back(cand[i]);
        helper(ans, nums, i, sum+cand[i], target, cand);
        nums.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        int sum=0;
        int i=0;
        vector<vector<int>> ans;
        vector<int> nums;
        helper(ans, nums, i, sum, target, cand);
        return ans;
    }
};
