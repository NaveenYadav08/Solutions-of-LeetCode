https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1#
https://leetcode.com/problems/kth-largest-element-in-a-stream/


class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        
        vector<int> ans(n);
        
        priority_queue<int,vector<int>,greater<int>> pq;  //largest  mae min heap
        
        for(int i=0; i<n; i++)
        {
            if(pq.size() < k)
                pq.push(arr[i]);
            else
            {
                if(arr[i] > pq.top())
    			{
    				pq.pop();
    				pq.push(arr[i]);
    			}
            }
            if(pq.size() < k)
                ans[i] = -1;
            else
                ans[i] = pq.top();
        }
        
        return ans;
    }
};
