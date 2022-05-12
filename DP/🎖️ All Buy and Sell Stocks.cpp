
█▄▄ █░█ █▄█   ▄▀█ █▄░█ █▀▄   █▀ █▀▀ █░░ █░░   █▀ ▀█▀ █▀█ █▀▀ █▄▀   ▄▄   █
█▄█ █▄█ ░█░   █▀█ █░▀█ █▄▀   ▄█ ██▄ █▄▄ █▄▄   ▄█ ░█░ █▄█ █▄▄ █░█   ░░   █

( single transaction )
// LINK - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// 🅣🅗🅔🅞🅡🅨

// For selling the stock on ith day I will buy it at 
// min price ( 0 to i-1 th day )

𝓒𝓞𝓓𝓔

int maxProfit(vector<int>& prices) 
{
        int n = prices.size();
        int maxprofit = 0;
        int minvalue = prices[0];
        for(int i=0;i<n;i++){
            minvalue = min(prices[i],minvalue);
            maxprofit= max(maxprofit,prices[i] - minvalue);
        }
        return maxprofit;
}



█▄▄ █░█ █▄█   ▄▀█ █▄░█ █▀▄   █▀ █▀▀ █░░ █░░   █▀ ▀█▀ █▀█ █▀▀ █▄▀   ▄▄   █ █
█▄█ █▄█ ░█░   █▀█ █░▀█ █▄▀   ▄█ ██▄ █▄▄ █▄▄   ▄█ ░█░ █▄█ █▄▄ █░█   ░░   █ █

( Many transaction )
        
// LINK - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// 🅣🅗🅔🅞🅡🅨 - see the photo uploaded

DP solution of BUY AND SELL STOCK - 2 
        
𝓒𝓞𝓓𝓔 - 
class Solution {
    
    int dp[30003][2];
    
    int helper(vector<int>& prices, int index, int buy)
    {
        if(index==prices.size())
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];
        int profit = INT_MIN;
        if(buy)
        {
            profit = max(-prices[index]+helper(prices,index+1,0) , helper(prices,index+1,1));
        }
        else
        {
            profit = max(prices[index]+helper(prices,index+1,1) , helper(prices,index+1,0));
        }
        
        return dp[index][buy]=profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
      memset(dp,-1,sizeof(dp));
        return helper(prices,0,1);
    }
};

🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥
// VALLEY PEAK 
𝓒𝓞𝓓𝓔 - 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int diff = 0;
        for(int i=1;i<n;++i)
        {
            if(prices[i] > prices[i-1])
                diff += prices[i]-prices[i-1];
        }
        
        return diff;
    }
};




