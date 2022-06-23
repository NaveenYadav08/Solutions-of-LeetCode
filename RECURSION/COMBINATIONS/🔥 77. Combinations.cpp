https://leetcode.com/problems/combinations/

class Solution {
public:
vector<vector<int>> ans;
    
void helper(vector<int> &nums, int i, vector<int> &tmp, int k)
{
    if(tmp.size()==k )
    {
        ans.push_back(tmp); return;
    }
    
    if(tmp.size()>k or i>=nums.size()) return;
    
    helper(nums, i+1, tmp, k);
    
    tmp.push_back(nums[i]);
    helper(nums, i+1, tmp, k);
    tmp.pop_back();
    
}    
vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=0; i<n; i++)
        {
            nums.push_back(i+1);
        }
        vector<int> tmp;
        helper(nums,0,tmp,k);
        return ans;
    }
};
