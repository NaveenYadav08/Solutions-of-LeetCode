// LINK -  https://leetcode.com/problems/word-break/

// CODE -

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>mp;
        for(auto x:wordDict)
        {
            mp.insert(x);
            // put all elements in map to check
            
         
        }
        
        int len=s.size();
        bool dp[len+1];
        memset(dp, false, sizeof(dp));
        
        dp[0]=true;
        
        // dp[i] pssble to make from pst 0 to i
        // of string s
        
        // check string s pst by pst
        for(int i=1;i<=len;i++)
        {
            for(int j=i-1; j>=0; j--)
            {   // string 
                if(dp[j]==true and mp.find(s.substr(j,i-j))!=mp.end())
                {
                    dp[i]=true;
                    continue;
                }
            }
        }
        
        return dp[len];
        
    }
};

// TC = S^2
SC = S

