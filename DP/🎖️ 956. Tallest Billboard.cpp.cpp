https://leetcode.com/problems/tallest-billboard/

🎖️ 956. Tallest Billboard.cpp

class Solution {
public:
    int dp[5001][21];
    int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof(dp));
        return solve(rods)/2;
    }
    
    int solve(vector<int>& rods, int i=0, int diff=0){
        if(i==rods.size()){
            if(diff==0){
                return 0;
            }
            return -1e7;
            
        }
        
        if(dp[diff][i]!=-1){
            return dp[diff][i];
        }
        
        int add=solve(rods, i+1, diff+rods[i]);
        int sub=solve(rods, i+1, abs(diff-rods[i]));
        int net=solve(rods, i+1, diff);
        
        return dp[diff][i]=max(net, rods[i]+max(add, sub));
    }
    
};
