// link - https://leetcode.com/problems/maximum-subarray/


CODE - 
  
class Solution {
  public:
    int crossSum(vector<int>& nums, int left, int right, int m) {
        if (left == right) return nums[left];

        int leftSubsum = INT_MIN;
        int currSum = 0;
        for(int i = m; i >= left ; i--) {
          currSum += nums[i];
          leftSubsum = max(leftSubsum, currSum);
        }

        int rightSubsum = INT_MIN;
        currSum = 0;
        for(int i = m + 1; i <= right ; i++) {
          currSum += nums[i];
          rightSubsum = max(rightSubsum, currSum);
        }

        return leftSubsum + rightSubsum;
    }

    
    int helper(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];

        int m = (left + right) / 2;

        int leftSum = helper(nums, left, m);
        int rightSum = helper(nums, m + 1, right);
        int crossS = crossSum(nums, left, right, m);

        return max(max(leftSum, rightSum), crossS);
    }
    
    
    int maxSubArray(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
    
};
