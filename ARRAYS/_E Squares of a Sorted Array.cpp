// LEETCODE - https://leetcode.com/problems/squares-of-a-sorted-array/

// TRICK IS TO STORE 2 VALUES IN one INTEGER

// CODE -
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int MAX = max(abs(nums[0]), abs(nums[nums.size()-1]));
        MAX=MAX+=5;
        
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=abs(nums[i]);
        }
        
        int k=nums.size()-1;
        int i=0;
        int j=nums.size()-1;
        while(k>=0 and j>=i)
        {
            int numsi = nums[i]%MAX;
                int numsj = nums[j]%MAX;
            if(numsi>=numsj)
            {
                nums[k] = numsi*MAX + (nums[k]%MAX);
                k--;
                i++;
            }
            else
            { 
                nums[k] = numsj*MAX + (nums[k]%MAX);
                k--;
                j--;
            }
        }
        
        for(int I=0;I<nums.size(); I++)
        {
            int y=nums[I]/MAX;
            nums[I] = y*y;
        }
        return nums;
        
    }
};
