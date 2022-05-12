
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




█▄▄ █░█ █▄█   ▄▀█ █▄░█ █▀▄   █▀ █▀▀ █░░ █░░   █▀ ▀█▀ █▀█ █▀▀ █▄▀   ▄▄   █ █ █
█▄█ █▄█ ░█░   █▀█ █░▀█ █▄▀   ▄█ ██▄ █▄▄ █▄▄   ▄█ ░█░ █▄█ █▄▄ █░█   ░░   █ █ █


( Atmost 2 transaction )
        
// LINK - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// 🅣🅗🅔🅞🅡🅨 - see the photo uploaded

DP solution of BUY AND SELL STOCK - 3
        
        // Same  as part 2 buy dp[index][buy][k]
        // buy - 2 { 0, 1 }
        // k - 3 { 0, 1, 2 }

🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥

ANOTHER APPROACH - TC ( N ) , SC ( N )
      
Max profit with at most two transactions = 
MAX {max profit with one transaction and subarray price[0..i] + max profit with one transaction and subarray price[i+1..n-1] } 
i varies from 0 to n-1.


▄▀█ █░░ █▀▀ █▀█ █▀█ █ ▀█▀ █░█ █▀▄▀█
█▀█ █▄▄ █▄█ █▄█ █▀▄ █ ░█░ █▀█ █░▀░█

1) Create a table profit[0..n-1] and initialize all values in it 0.
2) Traverse price[] from right to left and update profit[i] such that profit[i] stores maximum profit achievable from one transaction in subarray price[i..n-1]
3) Traverse price[] from left to right and update profit[i] such that profit[i] stores maximum profit such that profit[i] contains maximum achievable profit from two transactions in subarray price[0..i].
4) Return profit[n-1]

After iteration i, the array profit[0..i] contains the maximum profit with 2 transactions, and profit[i+1..n-1] contains profit with two transactions.
        
        
𝓒𝓞𝓓𝓔 - 
int maxProfit(int price[], int n)
{
    int* profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;
 
    /* Get the maximum profit with only one transaction allowed. After this loop, profit[i] contains maximum profit from price[i..n-1] using at most one trans. */
    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        // max_price has maximum of price[i..n-1]
        if (price[i] > max_price)
            max_price = price[i];
 
        // we can get profit[i] by taking maximum of: a) previous maximum, i.e., profit[i+1] b) profit by buying at price[i] and selling at max_price
        profit[i]
            = max(profit[i + 1], max_price - price[i]);
    }
 
    /* Get the maximum profit with two transactions allowed After this loop, profit[n-1] contains the result */
    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        // min_price is minimum price in price[0..i]
        if (price[i] < min_price)
            min_price = price[i];
 
        // Maximum profit is maximum of:
             // a) previous maximum, i.e., profit[i-1]
             // b) (Buy, Sell) at (min_price, price[i]) and add profit of other trans. stored in profit[i]
        profit[i] = max(profit[i - 1],
                        profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];
 
    delete[] profit; // To avoid memory leak
 
    return result;
}



🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥

ANOTHER APPROACH - TC ( N ) , SC ( 1 )
        
        
▄▀█ █░░ █▀▀ █▀█ █▀█ █ ▀█▀ █░█ █▀▄▀█
█▀█ █▄▄ █▄█ █▄█ █▀▄ █ ░█░ █▀█ █░▀░█

taking care of the first buy, first sell, second buy, second sell. Set first buy and second buy as INT_MIN and first and second sell as 0. 
        This is to ensure to get profit from transactions. Iterate through the array and return the second sell as it will store maximum profit.
        
        
   𝓒𝓞𝓓𝓔 - 
        
int maxtwobuysell(int arr[],int size) {
      int first_buy = INT_MIN;
      int first_sell = 0;
      int second_buy = INT_MIN;
      int second_sell = 0;
       
      for(int i=0;i<size;i++) {
         
          first_buy = max(first_buy,-arr[i]);//we set buy to negative, so the calculation of profit will be convenient
          first_sell = max(first_sell,first_buy+arr[i]); // max profit 1
          second_buy = max(second_buy,first_sell-arr[i]); //we can buy the second only after first is sold
          second_sell = max(second_sell,second_buy+arr[i]);
       
    }
     return second_sell;
}
      


⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐
