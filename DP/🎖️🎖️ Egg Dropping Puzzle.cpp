https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

// EGG DROP 

// k floor N eggs

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int solve(int n,int k)
    {
        if(n==1)
            return k;
            
        if(k==0)
            return 0;
            
        if(dp[n][k]!=-1)
            return dp[n][k];
        
        int ans=INT_MAX;    // i am throwing from topmost to bottom order
        for(int i=1;i<=k;++i)
           {
               int broken=solve(n-1,i-1);
               int notbroken=solve(n,k-i);
               int maxval=max(broken,notbroken);
               ans=min(ans,maxval+1);
           }
        
        return dp[n][k]=ans;
    }
    int eggDrop(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};
