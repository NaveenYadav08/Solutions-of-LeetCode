// LEETCODE - https://leetcode.com/problems/max-consecutive-ones-iii/

// CODE -

class Solution {
         // TC : O(n)
        // SC : O(1)
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int start = 0;
        int end = 0;
        int maxLen = 0;
        int flippedOnes = 0;
        while(end<nums.size()){
            if(nums[end] ==1){
                end++;
            } else {
                // nums[end] == 0
                if(flippedOnes<k) {
                    flippedOnes++;
                    end++;
                } else {
                    // reduce some flips
                    while(flippedOnes>=k) {
                        if(nums[start] == 0) {
                            flippedOnes--;

                        }
                         start++;
                    }
                }
            }

            maxLen = max(maxLen, end-start);
        }
        return maxLen;
        
    }
};

