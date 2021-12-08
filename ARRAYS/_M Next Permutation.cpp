// LEETCODE -https://leetcode.com/problems/next-permutation/

// CODE -
class Solution {
public:

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n-2, j = n-1;
    
    while(i>=0 && nums[i]>=nums[i+1]) i--;
    
    if(i<0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        while(nums[j]<=nums[i]) j--;
        swap(nums[i],nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
   
}
};
