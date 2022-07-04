https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

// EGG DROP 

// k floor N eggs

/*
The basic idea is, we have to find the minimum number of attempts to find the 
Threshold Floor, that means, above that floor the egg will break and below that 
floor the egg will not break

So, we have two choices
1. Egg will break
2. Egg will not break

-> For the first case if the egg will break from a particular floor then we have to go below
that floor
-> For the second case if the egg will not break from a particular floor then we have to go
above to find the threshold floor

Base Conditions:
1. It is given that egg the will not be 0 so no check for this in code
2. If the egg will be 1 i.e. k = 1, So we need at minimum n moves to determine what the value
    of floor is i.e n attempts.
3. If the n is 0 then no floor 0 attempt.
4. If the n is 1 then only 1 attempt.
*/

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int solve(int n,int k)
    {
        if(n==1)
            return k;
            
        if(k==0)
            return 0;
            
        if(dp[n][k]!=-1)
            return dp[n][k];
        
        int ans=INT_MAX;    // i am throwing from topmost to bottom order
        for(int i=1;i<=k;++i)
           {
               int broken=solve(n-1,i-1);
               int notbroken=solve(n,k-i);
               int maxval=max(broken,notbroken);
               ans=min(ans,maxval+1);
           }
        
        return dp[n][k]=ans;
    }
    int eggDrop(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};







/////////////////////////////////////////////////////


OPtiimized binary searh Dp 

int dp[102][10002];

class Solution {
public:
    int BSsolve(int e,int f){
        if(f==1 || f==0)
            return f;
        if(e==1)
            return f;

        if(dp[e][f]!=-1)
            return dp[e][f];

        int minn=INT_MAX;
        int l=1, r=f;
        
        while(l<=r){
            int k=l+(r-l)/2; // k mid
            int Lval=BSsolve(e-1,k-1); // broken at mid
            int Rval=BSsolve(e,f-k); // not broken at mid

            if(Lval<=Rval)
                l=k+1;
            else
                r=k-1;

            int temp=1+max(Lval,Rval);
            minn=min(minn,temp);
        }

        return dp[e][f]=minn;
    }
    
    int superEggDrop(int e, int f) {
        memset(dp,-1,sizeof(dp));
	    return BSsolve(e,f);
    }
};
