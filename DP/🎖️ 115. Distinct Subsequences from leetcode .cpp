Well, a dynamic programming problem. Let's first define its state dp[i][j] to be the number of distinct subsequences of t[0..i - 1] in s[0..j - 1]. Then we have the following state equations:

General case 1: dp[i][j] = dp[i][j - 1] if t[i - 1] != s[j - 1];
General case 2: dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] if t[i - 1] == s[j - 1];
Boundary case 1: dp[0][j] = 1 for all j;
Boundary case 2: dp[i][0] = 0 for all positive i.
Now let's give brief explanations to the four equations above.

If t[i - 1] != s[j - 1], the distinct subsequences will not include s[j - 1] and thus all the number of distinct subsequences will simply be those in s[0..j - 2], 
which corresponds to dp[i][j - 1];
If t[i - 1] == s[j - 1], the number of distinct subsequences include two parts: those with s[j - 1] and those without;
An empty string will have exactly one subsequence in any string :-)
Non-empty string will have no subsequences in an empty string.

// https://leetcode.com/problems/distinct-subsequences/

 

class Solution {
public:
    int numDistinct(string s, string b) {
        int m=s.size();
        int n=b.size();
        int t[m+1][n+1];
        for(int i=1;i<=n;i++){
            t[0][i]=0;
        }
        for(int i=0;i<=m;i++){
            t[i][0]=1;
        }
        int mod = 1000000007;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]!=b[j-1]){
                    t[i][j]=t[i-1][j];
                }
                else{
                    t[i][j]=(t[i-1][j-1]+t[i-1][j])%mod;
                }
            }
        }
        return t[m][n]%mod;
    }
};
