// link  https://leetcode.com/problems/combination-sum-iv/

// code

//TOP DOWN 

class Solution {
private:
    unordered_map<int, int> m;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0) return 1;
        if(m.count(target) > 0) return m[target];
        int ways = 0;
        for(auto  x: nums)
        {  if(target >= x)
                ways += combinationSum4(nums, target - x); }
        return m[target] = ways;
        
    }
};

// BOTTOM UP 

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long double>dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(auto it:nums)
            {
                if(i-it>=0)
                {
                    dp[i]+=dp[i-it];
                }
            }
        }
        return (int)dp[target];
    }
};
