?? LINK  https://leetcode.com/problems/jump-game-v/

// CODE 

/// https://www.youtube.com/watch?v=sCbuxSvoJqI

class Solution {
public:
    int dp[1003];
    int helper(vector<int>& arr, int d, int i)
    {   
        if(dp[i]!=-1) return dp[i];
        int ans=1, n=arr.size();
        // right
        for(int j=i+1;j<=min(i+d,n-1)and arr[i]>arr[j]; j++)
            ans=max(ans,1+helper(arr,d,j));
        // left
        for(int j=i-1;j>=max(i-d,0) and arr[i]>arr[j]; j--)
            ans=max(ans,1+helper(arr,d,j));
        return dp[i]=ans;
    }
    
    
    int maxJumps(vector<int>& arr, int d) {
       
         memset(dp,-1,sizeof(dp));
         int ans=1;
        for(int i=0; i<arr.size(); i++)
            ans=max(ans,helper(arr,d,i));
        return ans;
    }
};
