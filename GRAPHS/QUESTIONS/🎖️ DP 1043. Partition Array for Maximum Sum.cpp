https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
private:
    int findMaxSum(vector<int>& arr, int n, int idx, int k, vector<int>& dp){
        if(idx >= n)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int sum = 0, maxTillNow = 0, len = 0;
        for(int i = idx; i < min(n, idx + k); ++i){
            ++len;
            maxTillNow = max(maxTillNow, arr[i]);
            int cost = maxTillNow * len + findMaxSum(arr, n, i + 1, k, dp);
            
            sum = max(sum, cost);
        }
        
        return dp[idx] = sum;
    }
    
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int > dp(n + 1, -1);
        int maxSum = findMaxSum(arr, n, 0, k, dp);
        
        return maxSum;
    }
};
