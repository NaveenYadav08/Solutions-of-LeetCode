// LINK https://leetcode.com/problems/target-sum/

// CODE 

// BOTTOM UP 
// IT IS 0 , 1 Knapsack 
// lets saay divide into 2 sets 

// +Ve = S1 
// -Ve = S2

// S1 - S2 = target
// S1 + S2 = totalSum

// s1 = ( target + Tsum ) / 2;
// so it bcm ways of target sum = S1



class Solution {
    
    int dp[21][1001];
    
public:
    
    int findTargetSumWays(vector<int>&a, int s) {
        
      int t= accumulate(a.begin(),a.end(),0);
        
        if(t<s || (t+s)%2 !=0)
            return 0;
        
         
        int z=(s+t)/2;
        
        for(int i=0;i<=a.size();i++)
        {
            for(int j=0;j<=z;j++ )
            {
                if(i==0 && j !=0)
                    dp[i][j]=0;
                
                else if(i==0 && j==0)
                    dp[i][j]=1;
                
                else if(a[i-1]<=j)  // if curr ele is less than sum 
                    dp[i][j]= dp[i-1][j-a[i-1]] + dp[i-1][j]; // include and exclude 
                
                 else 
                     dp[i][j]=dp[i-1][j]; // not include curr ele
                    
}
}
        return dp[a.size()][z];
    }
};
