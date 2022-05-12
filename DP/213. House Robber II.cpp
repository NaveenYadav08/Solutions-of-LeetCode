// LINK - https://leetcode.com/problems/house-robber-ii/

CODE 

class Solution {
public:

    

    
    
int solve(vector<int> &ans, vector<int> &dp, int i){
if(i >= ans.size())
return 0;
if(dp[i] != -1)
return dp[i];
return dp[i] = max(solve(ans,dp,i+1),ans[i]+solve(ans,dp,i+2));
}

int rob(vector<int>& nums) {
    if(nums.size() == 1)
        return nums[0];
    vector<int> dp1(nums.size(),-1);
    vector<int> dp2(nums.size(),-1);
    vector<int> ans1(nums.begin()+1,nums.end()); //rob HOUSE 1, skip last house
    vector<int> ans2(nums.begin(),nums.end()-1);//rob HOUSE end, skip house - 1
    
    return max(solve(ans1,dp1,0),solve(ans2,dp2,0));
        
}
    
    
};
