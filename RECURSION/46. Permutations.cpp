https://leetcode.com/problems/permutations/



// WITHOUT REFERENCE
class Solution {
public:
    
    void helper(vector<int> S, vector<vector<int>>& ans, int i, int n)
	{
	    if(i==n)
	    {
	        ans.push_back(S);
	        //cout<<S<<"  print"<<endl;
	        return;
	    }
	    if(i>n)
	    return;
	    
	    for(int k=i;k<n;k++)
	    {
	        swap(S[i],S[k]);
	        //cout<<S<<"   ...."<<endl;
	        helper(S,ans,i+1,n);
	    }
	}
    
    vector<vector<int>> permute(vector<int>& S) {
        sort(S.begin(),S.end());
        vector<vector<int>> ans;
        helper(S,ans,0,S.size());
        return ans;
        
    }
};

// WITH REFERENCE 
class Solution {
public:
    
void helper(vector<int> &nums, vector<vector<int>>& ans, int i)
{
    if(i==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    
    if(i>nums.size()) return;
    
    for(int j=i; j<nums.size(); j++)
    {
        swap(nums[i], nums[j]);
        helper(nums,ans, i+1);
        swap(nums[i],nums[j]);
    }
}
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        helper(nums, ans, 0);
        return ans;
        
    }
};
