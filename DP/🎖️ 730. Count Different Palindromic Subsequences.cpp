// LINK  https://leetcode.com/problems/count-different-palindromic-subsequences/

// CODE 


// https://www.youtube.com/watch?v=x3OxiEc523Y&t=289s&ab_channel=happygirlzt

// dp[i][j] = ans from i to j of string 

class Solution {
public:
    
    int countPalindromicSubsequences(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            dp[i][i] = 1; // for all of len 1 and is 1 
        }
        
        for(int gap = 2;gap<=n;gap++){  // gap 
            for(int i=0; i<=n-gap; i++){   // i is starting point
                int j = i+gap-1;  // j is end point 
                
                if(s[i]==s[j])
                { // if start and end are same 
                    // aba -> dabad 
                    // if start and end same 
                    // dp[i+1,j-1]*2 comoon 
                    // then iske baad 3 cases hae 
                    // lets say start = end = d 
                    int low = i+1;
                    int high = j-1;
                    
                    // these are to find the d ( same char ) inside the box
                    while(low<=high && s[low]!=s[i])
                        low++;
                    while(low<=high && s[high]!=s[i])
                        high--;
                    
                    
                    // if no same char inside box  add +2 = d, dd
                    if(low>high){
                        dp[i][j] = 2*dp[i+1][j-1] + 2;
                    } // if only 1 is in the box =  dd , +1
                    else if(low==high){
                        dp[i][j] = 2*dp[i+1][j-1] + 1;
                    } // if more than = to 2 are there in box 
                    // minus the ans[left+1][right-1]
                    else{
                        dp[i][j] = 2*dp[i+1][j-1] - dp[low+1][high-1];
                    }
                }
                else
                { // if start and end char are not same then ans = i+1,j + i,j-1 - common(i+1,j-1);
                    dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                }
                
                dp[i][j] = (dp[i][j]<0 ? dp[i][j]+1000000007 : dp[i][j]) %1000000007;
            }
        }
        
        return dp[0][n-1];
    }
};
