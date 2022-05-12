// LINK https://leetcode.com/problems/ugly-number-ii/

// CODE 

class Solution {
public:
int nthUglyNumber(int n) {
vector<int> dp(n);
dp[0]=1;
    
    // indexes 
    
int p2=0;
int p3=0;
int p5=0;

    for(int i=1;i<n;i++)
    {
        int multipletwo=dp[p2]*2;
        int multiplethree=dp[p3]*3;
        int multiplefive=dp[p5]*5;
        
        dp[i]=min(multipletwo,min(multiplethree,multiplefive));
        if(dp[i]==multipletwo)p2++;
        if(dp[i]==multiplethree)p3++;
        if(dp[i]==multiplefive)p5++;
    }
    return dp[n-1];
}
};
