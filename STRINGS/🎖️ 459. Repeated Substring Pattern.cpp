// link https://leetcode.com/problems/repeated-substring-pattern/

// lps nikala 
// now lps[n-1] = longest suffix also prefic 
// so n - lps[n-1] = len of repeatng part 

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n=s.length();
        vector<int> dp(n,0);
        
        int i=1;
        int len=0;
        
        for(i=1;i<n;)
        {
            if(s[i]==s[len])
            {
                len++;
                dp[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len=dp[len-1];
                }
                else
                {
                    dp[i]=0;
                    i++;
                }
            }
        }
        
        // lps computed
        
        return dp[n-1] && (n%(n-dp[n-1])==0);
    }
};
