// BOTTOM UP Upproach 

class Solution {
public:
    
    int dp[1001][1001];
    int rec(string s1, string s2)
    {
        int m=s1.size();
        int n=s2.size();
        
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0; j<=n; j++)
            {
              if(i==0 or j==0)
                  dp[i][j]=0;
                
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            
            
        }
        
        return dp[m][n];
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        
        
        return rec(s1,s2);
    }
};
