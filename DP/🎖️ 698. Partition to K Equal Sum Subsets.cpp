// LINK - https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

// CODE 

// BITSET DP 

class Solution {
public:
    int dp[1<<16];
    
bool sol(vector<int>& nums, int k, int sum, int tar, int mask){
        if(k==1)return true; 
    // since we are left only with last subset and k-1 subset has already been found
        if(sum>tar) return false;
        if(dp[mask]!=-1)return dp[mask];
        if(sum==tar){
            return dp[mask]=sol(nums,k-1,0,tar,mask);
        }
    
        for(int i=0;i<nums.size();i++){
            if(mask&(1<<i))continue;
            if(sol(nums,k,sum+nums[i],tar,mask|(1<<i))) return dp[mask]=true;
        }
        return dp[mask]=false;
}
    
    
    
bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(dp,-1,sizeof dp);
        int n=nums.size();
        if (n<k)return false;
        int s=accumulate(nums.begin(),nums.end(),0);  // SUM 
        if (s%k)return false;
        //        nums, k, currsum, target, mask
        return sol(nums,k,0,s/k,0);
        
}
    
    
};
