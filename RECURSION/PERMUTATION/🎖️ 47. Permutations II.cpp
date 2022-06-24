https://leetcode.com/problems/permutations-ii/

class Solution {
public:

    
    bool CHECK(vector<int> nums, int start, int curr)
    {
        for(int i=start; i<curr; i++)
        {
            if(nums[i]==nums[curr]) return false;
        }
        return true;
    }
    
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
        if(!CHECK(nums,i,j)) continue;
        else{
        swap(nums[i], nums[j]);
        helper(nums,ans, i+1);
        swap(nums[i], nums[j]);
        }
    }
}
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        helper(nums, ans, 0);
        return ans;
        
    }
    
};



// class Solution {
// public:
//     vector<vector<int>>ans;//to store final ans
//     void solve(vector<int> nums,int idx)
//     {
//         if(idx==nums.size())//if idx equals arr size add current permutation to ans
//         {
//             ans.push_back(nums);
//         }
//         for(int i=idx;i<nums.size();i++)
//         {
//             if(i!=idx && nums[i]==nums[idx])//to cheak if the elements are duplucate 
//                 continue;
//             swap(nums[i],nums[idx]);//swap the current element with the index
//             solve(nums,idx+1);//solve for next index
            
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(),nums.end());//sort the given array
//         solve(nums,0);
//         return ans;
        
//     }
// };
