https://leetcode.com/problems/next-greater-element-ii/


//way 1 is append this same array at back 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        
        stack<int> st;
        
        vector<int> res(n, -1);
        
        for(int i = 2 * n - 1; i >= 0; i--)
        {
            int idx = i % n;
            
            while(st.empty() == false && nums[st.top()] <= nums[idx])
            {
                st.pop();
            }
            
            if(st.empty() == false)
            {
                res[idx] = nums[st.top()];
            }
            
            st.push(idx);
        }
        
        return res;
    }
};
