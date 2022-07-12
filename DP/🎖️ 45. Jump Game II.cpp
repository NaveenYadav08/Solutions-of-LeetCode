// LINK  https://leetcode.com/problems/jump-game-ii/

// CODE 

// grrreddy O ( n )
// https://www.youtube.com/watch?v=a9r98S-pDvk&t=1s&ab_channel=AnuragCodes
class Solution {
public:
    int jump(vector<int>& nums) {
        // linear time 
        int n=nums.size();
        int currReach = 0;
        int currMax = 0;
        int jumps = 0;
        
        for(int i=0;i<nums.size()-1; i++)
        {
            if(i+nums[i]>currMax)
            {
                currMax=i+nums[i]; 
                // it will see all the jump between i and reach to see the max possibilty 
            }
            
            if(i==currReach)
            {// when I reach at currReach i will take the jump and update new reach as maxreach 
                jumps++;
                currReach = currMax;
            }

        }
        if(currReach<n-1)
        return -1;
        
        return jumps;
    }
};


// DP O ( N^2)
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        int dp[n+1];
        memset(dp,INT_MAX,n+1);
        
        dp[n-1]=0;
        for(int i=n-2;i>=0; i--)
        {
            int ans=INT_MAX;
            for( int j=i+1; j<n and j<= nums[i]+i ; j++)
            {  
                if(dp[j]!=INT_MAX)
                ans=min(ans,dp[j]+1);
            }
            
            dp[i]=ans;
                
        }
        
        return dp[0];
        
    }
};
