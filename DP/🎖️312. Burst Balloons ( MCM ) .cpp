// LINK https://leetcode.com/problems/burst-balloons/

// CODE 

class Solution {
public:
    
    
int MCM(vector<int>& nums,int left,int right,vector<vector<int>>& mem)
//Matrix Chain Multiplication Problem
{
    if(left>=right)//Invalid Condition
        return 0;
    
    if(mem[left][right]!=-1)
        return mem[left][right];
    
    int max_cost=INT_MIN;
    
    for(int k=left;k<right;k++)  //Start iterating from left(1) to right(n-1)
    {
       int total_cost=MCM(nums,left,k,mem)+MCM(nums,k+1,right,mem)+nums[left-1]*nums[k]*nums[right]; 
        //after traversing any element from left to right, 
	   //Assume that the traversed element is no more in nums array and find product of current element and its adjacent element
        
       max_cost=max(max_cost,total_cost);
       
        mem[left][right]=max_cost;
    }
   return mem[left][right];
}
    
    
int maxCoins(vector<int>& nums) 
{
    nums.insert(nums.begin(),1); 
    //for inserting value in front of vector array by    vec_name.insert(pos,val);
    nums.push_back(1);
    //Inserting 1 at the end of nums vector array
    
    //insert 1 at start and end 
    
    int n=nums.size();
    vector<vector<int>> mem(n,vector<int>(n,-1));
    // mem[n][n]={-1};
    
    
    return MCM(nums,1,n-1,mem);
}
    
};
