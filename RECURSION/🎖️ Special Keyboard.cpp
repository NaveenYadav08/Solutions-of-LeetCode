https://www.youtube.com/watch?v=c_y7H7qZJRU
https://practice.geeksforgeeks.org/problems/special-keyboard3018/1#


class Solution{
public:

long long helper(int N)
{
    if(N<=6)
    return N;
    
    long long dp[N+1]={0};
    for(int i=0;i<=6;i++)
    dp[i]=i;
    
    for(int i=7; i<=N; i++)
    {
        long long ans=i;
        for(int j=i-3; j>0; j--)
        {
            ans=max(ans, dp[j]*(i-j-1) );
        }
        dp[i]=ans;
    }
    return dp[N];
}

    long long int optimalKeys(int N){
        // code here
        return helper(N);
        
    }
};
