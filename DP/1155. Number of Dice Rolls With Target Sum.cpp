// LINK https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

// CODE 

class Solution {
public:
int mod=1e9+7;
int dp[31][1001]; // dice , target
    
    
// d = no of die,k faces,target
int solve(int d,int f,int sum)
{
    if(d==0 && sum==0) return 1;
    if(d<=0 || sum<=0) return 0;
   
    if(dp[d][sum]!=-1)
        return dp[d][sum];
    
    int ways=0;
    for(int i=1;i<=f;i++)
    {
        // if(d>0 && sum>=i)
        // {
            ways =(ways%mod + (solve(d-1,f,sum-i))%mod)%mod;  
        //}
    }
    
    return dp[d][sum] = ways;
}

int numRollsToTarget(int n, int k, int target) {
    
    memset(dp,-1,sizeof(dp));
    
    int ans=solve(n,k,target);
    
    return ans%mod;
}
    
};
