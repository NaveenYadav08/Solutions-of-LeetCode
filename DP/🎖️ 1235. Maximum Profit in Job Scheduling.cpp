// LINK https://leetcode.com/problems/maximum-profit-in-job-scheduling/


Approach :
Step 1 : We save startTime , endTime and profit in a single 2D vector jobs and sort it according to endTime
Step 2 : Make a vector dp
Step 3 : dp[0] = jobs[0][2] i.e. first profit after sorting according to endTime

Now for index >= 1 we have choice either to include the current profit or not.
If we don't include the current profit : dp[i] = dp[i-1]
but if we include the current profit then : dp[i] = current profit + profit at the last non-overlapping index
Note : To find profit at the last non-overlapping index we move backwards from current index i till we find some element with its endTime <= current elements startTime

CODE :

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        int n = profit.size();
        
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        
        vector<int> dp;
        dp.push_back(jobs[0][2]);
        
        for(int i=1;i<n;i++){
            int including = jobs[i][2];
            int lastoverlapping = -1;
            
            for(int j=i-1;j>=0;j--){
                if(jobs[j][0]<=jobs[i][1]){
                    lastoverlapping = j;
                    break;
                }
            }
            if(lastoverlapping != -1)
                including += dp[lastoverlapping];
            
            dp.push_back( max(dp[i-1],including) );
        }
        
        return dp[n-1];
    }
};

