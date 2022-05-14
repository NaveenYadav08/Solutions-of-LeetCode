//LINK - https://leetcode.com/problems/minimum-cost-for-tickets/

// CODE 

class Solution {
public:
int n;
    vector<int> dp;
    
    int go(int i, vector<int> &days, vector<int> &costs) 
    {
        
        if(i == n) {
			// all trips are done
            return 0;
        }
        
        // memoized result
        if(dp[i] != -1) {
            return dp[i];
        }
        
		// arbirarily high value
       int ans = INT_MAX;
        
        // buy daily pass, go to next day
        ans = min(ans, costs[0] + go(i+1, days, costs));
        
        // weekly pass, [days[i], days[i] + 7] ,
		// and skip days that we already paid for
        int j = i;
        while(j < n && days[j] < days[i] + 7) {
            j += 1;
        }
        
        // go to jth day, our weekly pass date has expired 
        ans = min(ans, costs[1] + go(j, days, costs));
        
        // buy monthly pass, [days[i], days[i] + 30]
		// and skip days that we already paid for
        
        j = i;
        while(j < n && days[j] < days[i] + 30) {
            j += 1;
        }
        
        // go to jth day, our monthly pass expired 
        ans = min(ans, costs[2] + go(j, days, costs));
        
        return dp[i]=ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        n = days.size();
        dp.assign(n, -1);
        return go(0, days, costs);  // i, vector, cost
    }
};
