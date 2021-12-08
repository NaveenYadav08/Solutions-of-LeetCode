// LEETCODE - https://leetcode.com/problems/minimum-size-subarray-sum/

// CODE 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size=nums.size(), start=0, end=0, sum=0, min=size+1;
        
        while(end<size)
        {
            while(sum<target && end<size)
                sum += nums[end++];
            
            while(sum>=target && start<end)
            {
                if(min>end-start)
                    min = end-start;
                
                sum -= nums[start++];
            }
        }
        if(min == size+1)
            return 0;
        return min;
    }
};
