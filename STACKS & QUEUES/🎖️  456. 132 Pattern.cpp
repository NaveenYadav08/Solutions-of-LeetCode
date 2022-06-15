https://leetcode.com/problems/132-pattern/




class Solution {
    public:
    bool find132pattern(vector<int>& nums) 
    {
        int n = nums.size();
        if (n < 3) 
            return false;
        
        int minn[n]; // min prefix array 
        minn[0] = nums[0];
        for (int i = 1; i < n; i++)
            minn[i] = min(nums[i], minn[i - 1]);
        
        stack<int> s; // stack from last element
        for (int j = n - 1; j >= 0; j--) 
        {
            while (!s.empty() && s.top() < nums[j]) 
            {
                if (s.top() > minn[j])
                    return true;
                s.pop();
            }
            s.push(nums[j]);
        }
        return false;
    }
};
