// LINK -  https://leetcode.com/problems/word-break/

// CODE -

// MEMOISED 

class Solution {
private:
    vector<int> dp;
    bool f(string s, int start, int n, vector<string>& wordDict, set<string> &st){
        if(start == n) return true;
        if(dp[start] != -1) return dp[start]; 
        for(int i = start ;i < n; ++i){
            if(st.count(s.substr(start, i - start + 1)) && f(s, i + 1, n, wordDict, st)) return dp[start] = true;
        }
        return dp[start] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> st;
        for(auto &e : wordDict){
            st.insert(e);
        }
        dp.resize(n, -1);
        return f(s, 0, n, wordDict, st);
    }
};


















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

