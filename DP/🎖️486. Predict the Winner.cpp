// LINK https://leetcode.com/problems/predict-the-winner/
// CODE

class Solution {
public:
    
    int helper(vector<int>&nums, int i, int l, bool turn)
    {
        if(i>l)
        {
            
            return 0 ;
        }
        
        if(turn)
        {
            int op1= nums[i]+helper(nums, i+1, l,false);
            int op2= nums[l]+helper(nums, i, l-1,false);
            return max(op1,op2); // maximaize own score
        }
        else
        {
            int op1= helper(nums, i+1, l,true);
            int op2= helper(nums, i, l-1,true);
            return min(op1,op2); // miinimize opponent score
        }
        
        
    }
    
    
bool PredictTheWinner(vector<int>& nums) 
{
        
        int i=0;
        int l=nums.size()-1;
        
        int p1=0;
        int p2=0;
        
        // bool win=false;
        bool turn=true;
        
        int sum=0;
        for(auto x:nums)
            sum+=x;
        
        p2=sum;
        p1=helper(nums,i,l,turn); // find score of p1
        
        // as p1+p2=sum;
        // p2=sum-p1;
        // to win p1 >= p2
        // p2 = sum - p1;
        // p1 > = sum - p1
        // 2*p1 >= sum
        
        if(2*p1 >= sum)
        return true;
        
        return false;
    }
    
};
