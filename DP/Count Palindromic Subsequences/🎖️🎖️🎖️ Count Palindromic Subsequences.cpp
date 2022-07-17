
Time Complexity: O(N2), Auxiliary Space: O(N2)
  
  
  https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/


THEORY 
CountPS(i,j)
// Every single character of a string is a palindrome 
// subsequence 
if i == j
   return 1 // palindrome of length 1

// If first and last characters are same, then we 
// consider it as palindrome subsequence and check
// for the rest subsequence (i+1, j), (i, j-1)
Else if (str[i] == str[j])
   return   countPS(i+1, j) + countPS(i, j-1) + 1;

else
   // check for rest sub-sequence and  remove common
   // palindromic subsequences as they are counted
   // twice when we do countPS(i+1, j) + countPS(i,j-1)
   return countPS(i+1, j) + countPS(i, j-1) - countPS(i+1, j-1)
  
  
  
  
  
  
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  CODE

class Solution{
    public:
    /*You are required to complete below method */
long long m = 1e9 + 7;
   int dp[1001][1001];
   
   long long int cps(string &s,int i,int j)
   {
       if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j])
       {
         return  dp[i][j] = ( cps(s,i+1,j) + cps(s,i,j-1) - cps(s,i+1, j-1)   + cps(s,i+1, j-1) + 1 )%m;
         // cps(s,i+1,j) + cps(s,i,j-1) - cps(s,i+1, j-1)  yae as normal
         // cps(s,i+1, j-1) + 1 // this is common wale sare make palindrome with i,j and +1 for i ---- j
       }
       else
       {
          return dp[i][j] = (m+ cps(s,i+1,j) + cps(s,i,j-1) - cps(s,i+1,j-1))%m;
       }
      // return dp[i][j]%m;
   }
   
   long long int  countPS(string s)
   {
      //Your code here
     memset(dp,-1,sizeof(dp));
     return cps(s,0,s.size() -1);
   }
     
};
