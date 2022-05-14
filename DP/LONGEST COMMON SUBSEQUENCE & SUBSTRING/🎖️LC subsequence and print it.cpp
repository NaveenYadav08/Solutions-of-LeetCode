// LINK https://leetcode.com/problems/longest-common-subsequence/
// CODE

// for LCS print i will go in direction of larger len

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
                
                
                // if same ans = 1 + (i-1,j-1)
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                
                // else ans = max{ (i-1,j), (i,j-1) }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            
            
        }
        
        return dp[m][n];
    }
    

    string Lcs(string &s1,string &s2,int m,int n){
        //if either of string length is 0 then we don't have any common lcs so empty string
        if(n==0 or m==0){
            return "";
        }
        //if you find charachter match then append the charachter in answer
        if(s1[m-1]==s2[n-1]){
            return Lcs(s1,s2,m-1,n-1)+s1[m-1];
        }
        //if there is mismatch
        else{
            //now we check which one of 2 we included in line 40 so we append the one which return
            //greater answer
            if(dp[m-1][n]>dp[m][n-1])
            {
                return Lcs(s1,s2,m-1,n);
            }
            else{
                return Lcs(s1,s2,m,n-1);
            }
        }
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        
        
        int tk = rec(s1,s2);
        cout<<Lcs(s1,s2,s1.size(),s2.size());
        return tk;
    }
};
