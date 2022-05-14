// LINK  https://leetcode.com/problems/longest-arithmetic-subsequence/

// CODE 

class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n=a.size();
        int dp[n+1][1010]; // bcz diff is - 500 to 500
        memset(dp,0,sizeof(dp));
        int ans=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
               int x=a[i]-a[j]+505;
               dp[i][x]=dp[j][x]+1;
            
               ans=max(ans,dp[i][x]);
        }
        
    }
    return ans+1;
    }
};




