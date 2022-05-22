

// https://leetcode.com/problems/profitable-schemes/
// 
// https://leetcode.com/problems/profitable-schemes/discuss/1715569/C%2B%2B-Recursive-greater-Memoized-Solution-or-Similar-to-01-Knapsack


// RECURSION BUT TLE 

class Solution {
public:
    int mod=1e9+7;
    int helper(int n,int minProfit,vector<int>& group, vector<int>& profit,int idx)
    {  // as this person minus value from maxprofit and if negative 0 them thats why this thing is valid
        if(n<0) return 0;
        if(idx==group.size())
        {
            if(minProfit==0) return 1;
            return 0;
        }
        int op1=helper(n,minProfit,group,profit,idx+1);
        int op2=helper(n-group[idx],max(0,minProfit-profit[idx]),group,profit,idx+1);
        return (op1+op2)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        return helper(n,minProfit,group,profit,0);
    }
};


  ///   DP 
class Solution {
public:
    int mod=1e9+7;
    int dp[101][101][101];
    int helper(int n,int minProfit,vector<int>& group, vector<int>& profit,int idx)
    { // as this person minus value from maxprofit and if negative 0 them thats why this thing is valid
        if(n<0) return 0;
        if(idx==group.size())
        {
            if(minProfit==0) return 1;
            return 0;
        }
        
        if(dp[idx][n][minProfit]!=-1) return dp[idx][n][minProfit];
        int op1=helper(n,minProfit,group,profit,idx+1);
        int op2=helper(n-group[idx],max(0,minProfit-profit[idx]),group,profit,idx+1);
        int ans =(op1+op2)%mod;
        dp[idx][n][minProfit]=ans;
        return ans;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return helper(n,minProfit,group,profit,0);
    }
};
