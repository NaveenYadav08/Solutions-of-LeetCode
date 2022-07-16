https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1


class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    string a=str;
		    string b=str;
		    int n=str.size();
		    int dp[n+1][n+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n;j++)
        {
            if(i==0 or j==0)
            dp[i][j]=0;
        
        else if(a[i-1]==b[j-1] and i!=j)
        {
            dp[i][j]= dp[i-1][j-1] +1;
        }
        else{
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }

        }
    }
    return dp[n][n];
    
		}
		

    


};
