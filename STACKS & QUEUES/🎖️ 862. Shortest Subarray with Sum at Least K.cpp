https://youtu.be/K0NgGYEAkA4
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

class Solution {
public:
   
    int shortestSubarray(vector<int>& nums, int k) {
        long long n = nums.size();
        vector<long long> prefix(n,0);
        long long mini = INT_MAX;
        long long sum = 0;
        deque<pair<long,long>> dq; //MONOTONIC DEQUEUE
        
        for(long long j = 0; j < n;j++){
            sum+=nums[j];
            
            if(sum>=k){
                mini=min(mini,j+1);
            }
            
            // DOING COMPRESSION OF WINDOW
            while(!dq.empty() and sum - dq.front().first >= k){
                mini = min(mini,j-dq.front().second);
                dq.pop_front();
            }
            while(!dq.empty() and sum <= dq.back().first){
                // TO KEEP IT MONOTONIC
                dq.pop_back();
            }
            dq.push_back({sum,j});
        }
        return mini==INT_MAX?-1:mini;
    }
};
