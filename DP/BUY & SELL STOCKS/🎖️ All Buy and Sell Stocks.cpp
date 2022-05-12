
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


⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐

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


⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐

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



█▄▄ █░█ █▄█   ▄▀█ █▄░█ █▀▄   █▀ █▀▀ █░░ █░░   ▄▄   █ █░█
█▄█ █▄█ ░█░   █▀█ █░▀█ █▄▀   ▄█ ██▄ █▄▄ █▄▄   ░░   █ ▀▄▀


( Atmost k  transaction )
        
        // LINK - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
        
        
▄▀█ █░░ █▀▀ █▀█ █▀█ █ ▀█▀ █░█ █▀▄▀█
█▀█ █▄▄ █▄█ █▄█ █▀▄ █ ░█░ █▀█ █░▀░█

TC - Cubic   O ( k * N * N ) , SC -  O ( N * K )
        
 DP Approach 
 
In this post, we are only allowed to make at max k transactions. The problem can be solved by using dynamic programming. 
1 Let profit[t][i] represent maximum profit using at most t transactions up to day i (including day i). 
2 Then the relation is:
profit[t][i] = max(profit[t][i-1], max(price[i] – price[j] + profit[t-1][j])) 
                                           for all j in range [0, i-1] 
3 profit[t][i] will be maximum of – 

profit[t][i-1] which represents not doing any transaction on the ith day.
                                                   
Maximum profit gained by selling on ith day. In order to sell shares on ith day, we need to purchase it on any one of [0, i – 1] days. 
                                                   
If we buy shares on jth day and sell it on ith day, max profit will be price[i] – price[j] + profit[t-1][j] where j varies from 0 to i-1. 
Here profit[t-1][j] is best we could have done with one less transaction till jth day.
                                                   
                                                   
   𝓒𝓞𝓓𝓔 - 
                                                   
  int maxProfit(int price[], int n, int k)
{
    // table to store results of subproblems
    // profit[t][i] stores maximum profit using
    // atmost t transactions up to day i (including
    // day i)
    int profit[k + 1][n + 1];
 
    // For day 0, you can't earn money
    // irrespective of how many times you trade
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;
 
    // profit is 0 if we don't do any transaction
    // (i.e. k =0)
    for (int j = 0; j <= n; j++)
        profit[0][j] = 0;
 
    // fill the table in bottom-up fashion
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n; j++) {
            int max_so_far = INT_MIN;
 
            for (int m = 0; m < j; m++)
                max_so_far = max(max_so_far,
                                 price[j] - price[m] + profit[i - 1][m]);
 
            profit[i][j] = max(profit[i][j - 1], max_so_far);
        }
    }
 
    return profit[k][n - 1];
}



█▀█ █▀█ ▀█▀ █ █▀▄▀█ █ ▀█ █▀▀ █▀▄   ▄▀█ █░░ █▀▀ █▀█ █▀█ █ ▀█▀ █░█ █▀▄▀█
█▄█ █▀▀ ░█░ █ █░▀░█ █ █▄ ██▄ █▄▀   █▀█ █▄▄ █▄█ █▄█ █▀▄ █ ░█░ █▀█ █░▀░█

TC = SC = O ( K * N )


If we observe 
profit[t][i] = max(profit [t][i-1], max(price[i] – price[j] + profit[t-1][j])) 
                            for all j in range [0, i-1]
                            
                                    
If we carefully notice, 
max(price[i] – price[j] + profit[t-1][j]) 
for all j in range [0, i-1]

can be rewritten as, 

= price[i] + max(profit[t-1][j] – price[j]) 
for all j in range [0, i-1] .                                  
                                   



= price[i] + max(prevDiff, profit[t-1][i-1] – price[i-1]) 
where prevDiff is max(profit[t-1][j] – price[j]) 
for all j in range [0, i-2]


   𝓒𝓞𝓓𝓔 - 
        
        
int maxProfit(int price[], int n, int k)
{
    // table to store results of subproblems
    // profit[t][i] stores maximum profit using atmost
    // t transactions up to day i (including day i)
    int profit[k + 1][n + 1];
 
    // For day 0, you can't earn money
    // irrespective of how many times you trade
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;
 
    // profit is 0 if we don't do any transaction
    // (i.e. k =0)
    for (int j = 0; j <= n; j++)
        profit[0][j] = 0;
 
    // fill the table in bottom-up fashion
    for (int i = 1; i <= k; i++) {
        int prevDiff = INT_MIN;
        for (int j = 1; j < n; j++) {
            prevDiff = max(prevDiff,
                           profit[i - 1][j - 1] - price[j - 1]);
            profit[i][j] = max(profit[i][j - 1],
                               price[j] + prevDiff);
        }
    }
 
    return profit[k][n - 1];
}



⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐




█▄▄ █░█ █▄█   ▄▀█ █▄░█ █▀▄   █▀ █▀▀ █░░ █░░   █▀ ▀█▀ █▀█ █▀▀ █▄▀   ▄▄   █░█
█▄█ █▄█ ░█░   █▀█ █░▀█ █▄▀   ▄█ ██▄ █▄▄ █▄▄   ▄█ ░█░ █▄█ █▄▄ █░█   ░░   ▀▄▀

Best Time to Buy and Sell Stock with Transaction Fee ( as many as Transactions ) 
  
// LINK - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
        
        THEORY - See Photos 
        // states and DP used 
        //  TC = O  ( N ) = SC
        
 𝓒𝓞𝓓𝓔 - 
        
class Solution {
public:
    int n, a;
    
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size(), a = fee;
        vector<vector<int>> memo(n+1, vector<int>(2));
        dp(memo, prices, 0, 0);
        return memo[0][0];
    }
    
    
    int dp(vector<vector<int>>& memo, vector<int>& prices, int index, int holding){
        if(index == n) return 0; 
        if(memo[index][holding])
            return memo[index][holding];
        if(holding)
        {   int op1=prices[index] - a + dp(memo, prices, index + 1, 0);
            int op2=dp(memo, prices, index + 1, 1);
            
            memo[index][holding] = max(op1, op2);
        }
        else
            memo[index][holding] = max(-prices[index] + dp(memo, prices, index + 1, 1), dp(memo, prices, index + 1, 0));
        return memo[index][holding];
    }
};



█▀ █▀█ ▄▀█ █▀▀ █▀▀   █▀█ █▀█ ▀█▀ █ █▀▄▀█ █ ▀█ █▀▀
▄█ █▀▀ █▀█ █▄▄ ██▄   █▄█ █▀▀ ░█░ █ █░▀░█ █ █▄ ██▄

       THEORY - See Photos 
      
      𝓒𝓞𝓓𝓔 - 
        

class Solution {
public:
    int n, a;
    
    
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size(), a = fee;
        
       return fun(prices);
        
    }
    
    
    int fun(vector<int>& prices){
        int ab, anb, cb, cnb;
            ab=anb=0;
           for(int index=n-1;index>=0;index--)
               
           { // this is the part of buy = 1
            int op1= prices[index] - a + ab;
            int op2= anb;
            
            cnb = max(op1, op2);
        
        // this is buy -  0
           cb = max(-prices[index] + anb, ab );
        
        
        ab=cb;
        anb=cnb; }
        
        return ab;
        
    }
};


⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐
        
        
        

█▄▄ █░█ █▄█   ▄▀█ █▄░█ █▀▄   █▀ █▀▀ █░░ █░░   █▀ ▀█▀ █▀█ █▀▀ █▄▀   ▄▄   █░█ █
█▄█ █▄█ ░█░   █▀█ █░▀█ █▄▀   ▄█ ██▄ █▄▄ █▄▄   ▄█ ░█░ █▄█ █▄▄ █░█   ░░   ▀▄▀ █



█▀▀ █▀█ █▀█ █░░ █▀▄ █▀█ █░█░█ █▄░█
█▄▄ █▄█ █▄█ █▄▄ █▄▀ █▄█ ▀▄▀▄▀ █░▀█


( as many as Transactions ) 
        
        
        // theory - for both DP 
        // video - https://www.youtube.com/watch?v=IGIe46xw3YY
        
DP - 𝓒𝓞𝓓𝓔 -  
TC = SC = N

class Solution {
public:
    int cooldown=1;
    int f(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp)
    {
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit = INT_MIN;
        if(buy) // if i can buy
        {
             profit = max(-prices[ind] + f(ind+1,0,prices,dp) ,  f(ind+1,1,prices,dp));
        }
        else
        {
            profit = max(prices[ind] + f(ind+1+cooldown,1,prices,dp) ,  f(ind+1,0,prices,dp));
        }  
        
        return dp[ind][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0, 1, prices, dp);
    }
};
        


🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥


        I USED THE STATE METHOD SEE NOTEBOOK FOR THIS 
        
TC = O ( N ) 
        SC = O ( 1 ) 
        
        
        
 𝓒𝓞𝓓𝓔 -     
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)
            return 0;
        // vector<int> noStock(n,0),inHand(n,0),Sold(n,0);
        // BUUT I ONLY NEED PREV STATE SO 2 is enough
        
        vector<int> noStock(2,0),inHand(2,0),Sold(2,0);
        
        noStock[0] = 0;
        inHand[0] = -prices[0];    //bcoz we have bought a stock and never sold it
        Sold[0] = 0;
        
        for(int i=1;i<n;++i)
        {
            noStock[i%2] = max(noStock[(i-1)%2],Sold[(i-1)%2]);
            inHand[i%2] = max(inHand[(i-1)%2],noStock[(i-1)%2]-prices[i]);
            Sold[i%2] = inHand[(i-1)%2]+prices[i];
        }
        int result = max(noStock[(n-1)%2],Sold[(n-1)%2]);
        return result;
    }
};        
        
⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        















































