// LINK - https://leetcode.com/problems/partition-equal-subset-sum/

// CODE - 


▀█▀ █▀█ █▀█   █▀▄ █▀█ █░█░█ █▄░█
░█░ █▄█ █▀▀   █▄▀ █▄█ ▀▄▀▄▀ █░▀█

class Solution {
    vector<vector<int>> mem;
    bool subsetSum(vector<int>& nums,int n,int pos,int sum)
    {
        if(sum==0)  //Sum found
            return true;
        else if(pos>=n || sum<0) //Out of bounds
            return false;
        if(mem[pos][sum]!=-1)
            return mem[pos][sum];
        
        return mem[pos][sum] = subsetSum(nums,n,pos+1,sum-nums[pos]) || subsetSum(nums,n,pos+1,sum);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;++i)
            sum += nums[i];
        
        if(sum & 1)     //ODD sum
            return false;
        
        mem.clear();
        mem.resize(n+1,vector<int>(sum/2+1,-1));
        return subsetSum(nums,n,0,sum/2);
    }
};



█▄▄ █▀█ ▀█▀ ▀█▀ █▀█ █▀▄▀█   █░█ █▀█
█▄█ █▄█ ░█░ ░█░ █▄█ █░▀░█   █▄█ █▀▀

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;++i)
            sum += nums[i];
        
        if(sum & 1)     //ODD sum
            return false;
        
        bool dp[n+1][sum/2+1];
        //Fill DP table (Subset Sum Problem code)
        for(int i=0;i<=n;++i)
        for(int j=0;j<=sum/2;++j)
        {
            if(i==0 || j==0)    //Base Case
                dp[i][j] = false;
            else if(nums[i-1] > j)    //SkIP case
                dp[i][j] = dp[i-1][j];
            else if(nums[i-1]==j)
                dp[i][j] = true;
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
        }
        return dp[n][sum/2];
    }
};
