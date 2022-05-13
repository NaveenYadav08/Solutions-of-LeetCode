// LINK - https://leetcode.com/problems/k-concatenation-maximum-sum/

// THEORY 

// IT is similar to kadanes algorithm 
// IF k = 1 , normal kadanes algo 

// if k is more than 1 

// cases = if total sum is negative 
// then it is useless to apply kadane over all concatenated arrays , only apply kadane over 2 concatenated ARRAY 

// if total sum is positive 
// array sum * ( K - 2 ) + kadane on two concat array


// CODE - 

typedef long long int lli;

class Solution {
public:

lli kadaneOne(vector<int> &nums)
{
    lli sum=0;
    lli max_val=INT_MIN;
    
    for(int i=0;i<nums.size();i++)
    {
        sum=max<lli>(sum+nums[i],nums[i]);
        
        max_val=max(max_val,sum);
    }
    
    return max_val;
}


lli kadaneTwo(vector<int> &nums)
{
    vector<int> dums=nums;
    for(int i=0;i<nums.size(); i++)
        dums.push_back(nums[i]);
    cout<<dums.size()<<endl;
    
    lli sum=0;
    lli max_val=INT_MIN;
    
    for(int i=0;i<dums.size();i++)
    {
        sum=max<lli>(sum+dums[i],dums[i]);
        
        max_val=max(max_val,sum);
    }
    
    return max_val;
    
}




int kConcatenationMaxSum(vector<int>& nums, int k) 
{
    
    lli sum=0;
    
    for(int i=0;i<nums.size();i++)
        sum+=nums[i];
    
    
    lli ans;
    
    
    
    if(k==1)
        ans=kadaneOne(nums);
    
    else if(sum<0)
         ans=kadaneTwo(nums);
    
    else ans=kadaneTwo(nums)+sum*(k-2);
        
    
    ans=max<lli>(0,ans);
    ans%=(int)(1e9+7);
    
    
    return ans;
}
};
