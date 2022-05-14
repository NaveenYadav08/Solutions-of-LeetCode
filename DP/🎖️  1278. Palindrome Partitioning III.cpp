// LINK https://leetcode.com/problems/palindrome-partitioning-iii/


// CODE 


class Solution {
public:

    
//count = no of char need to change
long int count(string s,int l,int r)
{
  long int c=0;
  while(l<r)
 {
   if(s[l]!=s[r]) c++;
   l++;
   r--;
 }
    return c;
}
    
//dp[i][j] stands for the minimal number of characters required to change upon the substring s[i:end], such that s[i:end] can be divided into (j) non-empty disjoint substrings with each substring a palindrome.
    
    int dp[101][101];
    int solve(string s,int k,int i)
    {
            if(i==s.length() and k==0) return 0;
            if(k<0||i>=s.length()) return INT_MAX;
           long int ans=INT_MAX;
            if(dp[i][k]!=-1) return dp[i][k];
            for(int l=i;l<s.length();l++)
            {
                    ans=min(ans,count(s,i,l)+solve(s,k-1,l+1));
            }
            return dp[i][k]=ans;
    }
    
    
int palindromePartition(string s, int k) 
{memset(dp,-1,sizeof(dp)); 
return solve(s,k,0);}
    

};
