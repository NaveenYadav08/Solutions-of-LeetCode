https://leetcode.com/problems/minimum-cost-to-merge-stones/

https://www.youtube.com/watch?v=r83itwwSsEQ


class Solution
{
    public:
        int mergeStones(vector<int> &stones, int k)
        {
            int n = stones.size();
            
            if ((n - k) % (k - 1)) return -1;
            
            // k + ( k - 1 )
            //     k + ( k - 1 ) + ( k- 1 ) 
                
            
            int presum[32] {};
            for (int i = 0; i < n; i++)
                presum[i + 1] = presum[i] + stones[i];
            
            int dp[32][32] {};
            
            
            for (int len = k; len <= n; len++)
            {
                for (int i = 0; i + len <= n; i++)
                {
                    int j = i + len - 1;
                    dp[i][j] = INT_MAX;

                    for (int t = i; t < j; t += (k - 1))
                        dp[i][j] = min(dp[i][j], dp[i][t] + dp[t + 1][j]);

                    if ((j - i) % (k - 1) == 0)
                        dp[i][j] += presum[j + 1] - presum[i];
                }
                
                // for(int I=0;I<stones.size();I++)
                // {
                //     for(int J=0;J<stones.size();J++)
                //     {
                //       cout<<dp[I][J]<<" ";
                //     }
                //     cout<<endl;
                // }
            }
            return dp[0][n - 1];
        }
};



// ALSO there is easier question of this INTERVIEWBIT

https://www.interviewbit.com/problems/merge-elements/

https://youtu.be/TFdclijv4Mg

int Solution::solve(vector<int> &a){
    int n = a.size();

    vector<int> prefix(n, 0);
    vector<vector<int>> dp(n, vector<int> (n, 0));
    prefix[0] = a[0];

    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + a[i];
    } 

    for(int len=1; len<n; len++){
        for(int i=0; i<n-len; i++){
            int j=i+len;
            int add = INT_MAX;
            for(int k=i; k<j; k++){
                add = min(add, dp[i][k] + dp[k+1][j]);
            }
            dp[i][j] = (prefix[j]-((i==0)? 0 : prefix[i-1])) + add;
        }
    }

    return dp[0][n-1];
}


