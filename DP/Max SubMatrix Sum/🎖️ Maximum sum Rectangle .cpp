https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#


Maximum sum Rectangle 

class Solution {
  public:
  int kadane(vector<int> nums) {
        int maxfar=0;
        bool pos=false;
        int maxtill=0;
        for(int i=0;i<nums.size();i++)
        {   if(nums[i]>=0) pos=true;
            maxtill+=nums[i];
            if(maxtill<0)
                maxtill=0;
            maxfar=max(maxfar,maxtill);
        }
        if(pos==false)
        {
            int ans=INT_MIN;
            for(int i=0;i<nums.size(); i++)
                ans=max(ans,nums[i]);
            return ans;
        }
        return maxfar;
    }
  
  
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        
        int ans = INT_MIN;
        for(int i=0;i<R;i++)
        {
            vector<int> a(C,0);
            for(int j=i;j<R;j++)
            {
                for(int col =0;col<C;col++)
                {
                    a[col]+=M[j][col];
                }
                
                ans = max(ans,kadane(a));
            }
        }
        
        return ans;
    }
};
