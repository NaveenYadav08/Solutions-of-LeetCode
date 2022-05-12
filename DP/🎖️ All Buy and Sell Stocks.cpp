
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



