https://leetcode.com/problems/sliding-window-maximum/


The solution is quite easy if you understand monotonic queue. Monotonic queue maintains our queue in increasing or decreasing order.
Deque data structure gives us the best way to implement them.
As we want the max value, we need to maintain our queue in such a way such that we can get the maximum value in O(1).
Eg. the given order is 5 4 3 6 7. The queue in each step will be:

5
5 4
5 4 3
Now 6 is >3 so pop_back till we get a number greater than 6. In this case whole of the queue gets popped.
6
7
Now as we want our window to be of a particular size k, whenever the difference in current index and the top element's index is >=k , 
remove that element from the front.
Comment for any doubt.
    
    

class Solution {
public:
    
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
int n=nums.size();
deque<int> dq;
vector<int> ans;

    for(int i=0;i<n;i++)
    {
        while(!dq.empty() && dq.front()==i-k)
        {
            dq.pop_front();
        }
        
        while(!dq.empty() && nums[dq.back()]<=nums[i])
        {
            dq.pop_back();
        }
        
        dq.push_back(i);
        if(i>=k-1) ans.push_back(nums[dq.front()]);      
    }
    
    return ans;
}
    
};
