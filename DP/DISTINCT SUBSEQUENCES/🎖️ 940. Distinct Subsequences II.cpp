// LINK https://leetcode.com/problems/distinct-subsequences-ii/
https://www.youtube.com/watch?v=9UEHPiK53BA&t=898s&ab_channel=Pepcoding

// CODE 


// remove count of char before the duplicate 
//""abcbac

//so 2nd b ke all me sae remove first b ke prev ke elements


class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1e9+7;
        int n = s.size();
        vector< long long int > dp(n+1,0);
        //n+1 bcz of blank 
        
        dp[0] = 1;
        // empty subseq
        
        map<char,int> mp;
        
        for(int i = 1 ; i <= n ;i++){
            dp[i] = (2*dp[i-1])% mod;   // include that i or not 2X cases
            
            char a = s[i-1];
            if(mp.count(a)){
                // if that char is there it store index
                int j = mp[a];
                dp[i] = (dp[i] - dp[j-1])% mod;
            }
             mp[a]=i; 
            
        }
        
        if(dp[n]<0) dp[n]+=mod;
        
        return dp[n]-1; // subtract 1 for 1st NULL subseq case
    }
};
