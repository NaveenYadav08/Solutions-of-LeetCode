// LEETCODE - https://leetcode.com/problems/minimum-increment-to-make-array-unique/


// CODE 

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int pre=nums[0];
        int curr;
        int count=0;
        for(int i=1;i<nums.size();i++)
        {
            curr=nums[i];
            pre=nums[i-1];
            if(pre>=curr)
            {
                count+=pre-curr+1;
                    nums[i]=pre+1;

            }
            
        }
        return count;
        
    }
};
