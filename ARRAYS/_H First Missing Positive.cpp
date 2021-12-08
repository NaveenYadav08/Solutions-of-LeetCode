// LEETCODE - https://leetcode.com/problems/first-missing-positive/

// CODE -

// O ( n ) , O ( n ) 

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> m;
        int minn=INT_MAX;
        int maxx=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=0)
                continue;
            else
            {
                minn=min(minn,nums[i]);
                maxx=max(maxx,nums[i]);
                m[nums[i]]++;
                
            }
        }
        
                int ans=minn;
        if(minn!=1)
            return 1;

        else
        {
            while(m.find(ans+1)!=m.end())
            {
                ans=ans+1;
            }
            return ans+1;
        }
        
        return -1;
        
        
        
        
    }
};
