// LEETCODE - https://leetcode.com/problems/contiguous-array/

// changing 0 to -1


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0,ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]==1?1:-1;
            if(sum==0)
            {
                ans=max(ans,i+1);
            }
            if(m.find(sum)==m.end())
            {
                m[sum]=i;
            }
            else
            {
                ans=max(ans,i-m[sum]);
            }
        }
        return ans;
    }
};
