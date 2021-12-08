// LEETCODE - https://leetcode.com/problems/array-nesting/submissions/

// CODE -

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
        int ans = INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                continue;
            else
            {
                int start = i;
                int lenn=0;
                while(start>=0 and start<nums.size() and nums[start]!=INT_MIN)
                {
                    int nextval = nums[start];
                    nums[start]=INT_MIN;
                    lenn++;
                    start=nextval;
                    
                }
                
                ans = max(ans,lenn);
                
                
            }
        }
        
        return ans;
        
    }
};
