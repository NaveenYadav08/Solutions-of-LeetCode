// whi min mae max ya max mae min aese question inme to hr baar bs hi lgega 
// leetcode https://leetcode.com/problems/koko-eating-bananas/


class Solution {
public:
    
    bool isfeasible(vector<int>piles, int h, int k)
    {
        int ans = 0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]<=k)
                ans++;
            else
            {
                if(piles[i]%k==0)
                    ans+= piles[i]/k;
                else
                {
                    ans+= piles[i]/k;
                    ans++;
                }
            }
        }
        
        if(ans<=h)
            return true;
        
            return false;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int m = 1;
        int M = *max_element(piles.begin(),piles.end());
        
    
        
        int ans = M;
        
        while(m<=M)
        {
            int mid=(m+M)/2;
            
            if(isfeasible(piles,h,mid))
            {M=mid-1; ans = min(ans,mid);}
            else
                m=mid+1;
        }
        
        return ans;
        
    }
};
