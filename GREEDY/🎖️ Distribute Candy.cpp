https://www.interviewbit.com/problems/distribute-candy/
https://leetcode.com/problems/candy/

https://www.youtube.com/watch?v=Ya-LfQ0OBkU&t=789s

// MUST SEE THIS FOR THE SOLUTION 2 
https://www.geeksforgeeks.org/chocolate-distribution-problem-set-2/


class Solution {
public:
    int candy(vector<int>& ratings) {
      int len = ratings.size();
      vector<int>L2R(len, 1);
      vector<int>R2L(len, 1);
      
      for(int i=1; i<len; i++)
        if(ratings[i] > ratings[i-1])
          L2R[i] = L2R[i-1]+1;
      
      for(int i=len-2; i>=0; i--)
        if(ratings[i] > ratings[i+1])
          R2L[i] = R2L[i+1]+1;
        
      int ans = 0;
      for(int i=0; i<len; i++)
        ans += max(L2R[i], R2L[i]);
      return ans;
    }
};


// CONSTANT SPACE //
//  As the values in an increasing/decreasing sequence differ by 1, the number of chocolates distributed to students in a specific subarray 
//  of k elements will be sum of k natural numbers. And the count will be k for a flat sequence as all the values are 1. 
//  The required value will be the total sum of the results of subarrays.


class Solution {
  public:
    
    int sum(int n) {
            return (n * (n + 1)) / 2;
    }
    
    int candy(vector<int>& ratings) {
        if(ratings.size() <= 1) return ratings.size();
        int candies = 1;
        int up = 0, down = 0; 
        int prevSlope = 0;
        
        for(int i = 1; i < ratings.size(); i++) {
            //If increasing then 1; if decreasing then -1; if equal then 0.
int currSlope = (ratings[i] > ratings[i-1]) ? 1  : (ratings[i] < ratings[i-1] ? -1 : 0);
            //                                       _
            //If mountain is changing. \_ || \/ ||  /
            if((prevSlope < 0 && currSlope >= 0) || (prevSlope > 0 && currSlope == 0)) {  
                candies = candies + sum(up) + sum(down) + max(up, down);
                //cout<<i<<" DD "<<up<<" "<<down<<endl;
                up = 0; 
                down = 0;
              
            }
            
            //Add in up/down if slope is increasing or decreasing respectively. 
            //If it is a plain, add a candy as it is the base case.
            if(currSlope > 0) {
                up++;
            }
            else if(currSlope < 0) {
                down++;
            }
            else {
                candies++;
            }
            
            prevSlope = currSlope;
        } 
        
        candies = candies + sum(up) + sum(down) + max(up, down);
        return candies;
    }
    

};
