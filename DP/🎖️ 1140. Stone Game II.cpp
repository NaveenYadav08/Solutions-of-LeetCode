// LINK https://leetcode.com/problems/stone-game-ii/

// CODE 

// min - max memo solution, Alex tries to maximize himself and Lee try to minimize the opponent
class Solution 
{
    public:
    int dfs(int suffix_sum[101], int dp[101][101], int l, int M, int n) 
        // l is the starting point, M as problem described and n is the border
    {
        // printf("L %d M %d ", l, M);
        if(l >= n) // out of bound, nothing to take
        {
            // printf("L >= n, return 0 \n");
            return 0; 
        }
        else if(dp[l][M] != 0) // return the cached answer if already computerd before
        {
            // printf("cached: %d\n", dp[l][M]);
            return dp[l][M];
        }
        // update the max possibilities for Alex, starting from l and take at most 2M\
             // then maximize all the possibilities when compete with Lee
        
            for(int i = 1; i <= 2 * M && l + i <= n; i++)
            {
                // printf("%d, %d call %d, %d \n", l, M,  i + l, max(M, i));
                dp[l][M] = max(dp[l][M], suffix_sum[l] - dfs(suffix_sum, dp, i + l, max(M, i), n)); // what Alex can take equals to the (suffix_sum from end to current l(start) minus all the posibilities that Lee can do starting from index i + l(since Alex has taken i stones)) 
            }
            return dp[l][M];
        
    }
    
    
    int stoneGameII(vector<int>& piles) 
    {
        int n = piles.size();
        int dp[101][101] = {0}; 
        // dp i j is the maximum value for Alex start at i and take at most M = j stones
        int suffix_sum[101] = {0};
        suffix_sum[n - 1] = piles[n -1];
        for(int i = n - 2; i >= 0; i--)
        {
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }
        return dfs(suffix_sum, dp, 0, 1, n);
        // suffixsum, dp, l is starting point , M , n 
    }
};
