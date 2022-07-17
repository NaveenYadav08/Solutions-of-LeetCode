same as coding ninja but diff is last line ko exclude kro 

https://practice.geeksforgeeks.org/problems/word-wrap1646/1   SAME Q ONLY DIFF EXCLUDE ANS OF LAT LINE 


CODE 


class Solution {
public:
int wrapWord(int idx, vector<int> &nums, int k, vector<int> &dp) {
        int n = nums.size();
        if(idx == n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int cost = INT_MAX, sum = 0;
        for(int i = idx; i < n; i++) {
            if(i > idx) sum++;
            sum += nums[i]; if(sum > k) break;
            if(i < n-1)
                cost = min(cost, (k-sum) * (k-sum) + wrapWord(i+1, nums, k, dp));
            else
                cost = 0;
        }
        return dp[idx] = cost;
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        vector<int> dp(n, -1);
        return wrapWord(0, nums, k, dp);
    }
};

