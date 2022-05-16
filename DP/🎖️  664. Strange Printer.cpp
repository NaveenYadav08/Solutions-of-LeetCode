// LINK  https://leetcode.com/problems/strange-printer/

// CODE 

class Solution {
public:
    int strangePrinter(string s) {
    int n=s.length();
        if(n==0)return 0;
		
		//dp[i][j] stores the minimum prints for substring starting from index i and ending at j
        int dp[n][n]; 
		
		//initialising to a maximum value
        for(int i=0;i<n;i++){for(int j=0;j<n;j++) dp[i][j]=INT_MAX;}
		
		//**BASE CASE:**
		//For substring of length one, 1 print is must
		//And for length of two, if characters are same it can be printed in 1 go otherwise 2.
    for (int i = 0; i < n; i++) 
        dp[i][i] = 1;
        
    for (int i = 0; i < n-1; i++) 
        {if(s[i]==s[i+1]) dp[i][i+1]=1; else dp[i][i+1]=2;}  
        
        
		//Applying dp for substrings for length 3 to n
        
        for(int k=3;k<=n;k++){
		
            for(int l=0;l<n-k+1;l++){
                // l is start index of substring
                int r=l+k-1; // ending index as per length
				
				//consider every element as a partition 
                 for(int j=l+1;j<=r;j++){
                       int tmp = dp[l][j-1] + dp[j][r];// here i to j-1 is printed first followed by j to r substring
					   
					   //IMPORTANT CATCH: if i and j th character are same , we can reduce 1 print by printing them together
                    if (s[l] == s[j])
                        tmp--;
                    
                    dp[l][r] = min(dp[l][r], tmp);
                }
            }     
            }
        // return 
        return dp[0][n-1];
    }
};
