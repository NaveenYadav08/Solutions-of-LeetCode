same as coding ninja but diff is last line ko exclude kro 

https://practice.geeksforgeeks.org/problems/word-wrap1646/1   SAME Q ONLY DIFF EXCLUDE ANS OF LAT LINE 


CODE 

class Solution {
public:

int solve(int i, int filled, vector<int> &nums, int n, int k, vector<vector<int>> &dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][filled] != -1)
        {
            return dp[i][filled];
        }
        if(filled!=0)
        {
            int temp1 = 1e9, temp2;
            if(filled+1+nums[i] <= k)
            {
                temp1 = solve(i+1, filled+1+nums[i], nums, n, k, dp);
            }
            int count = k-filled;
            temp2 = count*count+solve(i, 0, nums, n, k, dp);
            return dp[i][filled] = min(temp1, temp2);
        }
        else
        {
            return dp[i][filled] = solve(i+1, nums[i], nums, n, k, dp);
        }
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(0, 0, nums, n, k, dp);
    }
};

