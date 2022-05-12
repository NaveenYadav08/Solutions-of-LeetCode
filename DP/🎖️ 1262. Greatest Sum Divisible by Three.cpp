// LINK - https://leetcode.com/problems/greatest-sum-divisible-by-three/

// CODE 

class Solution {
public:
    int maxSumDivThree(vector<int>& a) {
        int n=a.size();
        
        vector<vector<int>> dp(n,vector<int>(3,0));  // dp[n][3]=0;
        dp[0][a[0]%3] = a[0];
        
        for(int i=1;i<n;i++)
        {
            int x = dp[i-1][0]+a[i];
            int y = dp[i-1][1]+a[i];
            int z = dp[i-1][2]+a[i];
            
            dp[i]=dp[i-1]; // full copy  //
            dp[i][x%3] = max(x,dp[i][x%3]);
            dp[i][y%3] = max(y,dp[i][y%3]);
            dp[i][z%3] = max(z,dp[i][z%3]);
            cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
        }
        return dp[n-1][0];
    }
};
