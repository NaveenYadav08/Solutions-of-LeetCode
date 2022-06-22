https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(21,vector<int>(31,-1));
        dfs(0,0,s,p,dp);
       
        if(dp[0][0]==-1)return false;
        return dp[0][0];
        
    }
    
    int dfs(int i,int j,string s,string p,vector<vector<int>> &dp){
        // cout<<i<<j<<endl;
        if(i==s.length() && j==p.length()) return 1;
        if(j>=p.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        bool m=i<s.length() && (s[i]==p[j] || p[j]=='.');
        
        if(j+1<p.length() && p[j+1]=='*'){
                dp[i][j]= dfs(i,j+2,s,p,dp)||(m && dfs(i+1,j,s,p,dp));
            return dp[i][j];
            }
        
        if(m){
            dp[i][j]= dfs(i+1,j+1,s,p,dp);
            return dp[i][j];
        }
        
        return 0;
    }
     
};


https://youtu.be/l3hda49XcDE
