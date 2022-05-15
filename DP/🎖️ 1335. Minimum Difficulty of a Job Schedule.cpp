//LINK  https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

// CODE 

// https://happygirlzt.com/code/1335.html

class Solution {
public:
    
     int dp[301][11]; 
    
     int memo(vector < int > & j , int d , int pos){ 
         if(d == 0 && pos == j.size())
         { 
         return 0; // if all days and ellemnts are considered
         }
         
         if( d == 0 || pos == j.size()) return 10001; 
         // if days become 0 but some elements are rleft to considered or all elements are considered but some days are left then return a maximum value which can't be achieved
         
         if(dp[pos][d] != -1) return dp[pos][d]; 
         // if we know the subproblem before then just return that one without solving it again
         
         int mx = -10001; 
         int ans =  10001;  
         
         for(int i = pos ; i<j.size() ; i++){ 
             mx = max( mx , j[i]); // considered maximum element of that particular subarray
             ans = min(ans  ,  mx + memo(j , d-1 , i+1)); 
             // our answer is the minimum of all the possible answer by taking different subarrays 
         }
         return dp[pos][d] = ans; // return the final ans 
     }
    
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
          memset(dp , -1 , sizeof(dp));  // memset dp to -1
        return memo(jobDifficulty , d , 0) >= 10001 ? -1 : memo(jobDifficulty , d , 0);
        // pos = 0 to d, [pos][d] = from pos to end and into d parts 
    }
};
