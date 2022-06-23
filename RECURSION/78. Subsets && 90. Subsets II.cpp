🎖️ 78. Subsets && 90. Subsets II.cpp

https://leetcode.com/problems/subsets/

class Solution {
public:
    
    void helper(vector<vector<int>> &ans, vector<int> &nums, vector<int> &hmm,  int i)
    {
        if(i==nums.size())
        {
            ans.push_back(hmm);
            return;
        }
        if(i>nums.size()) return;
        

            helper(ans,nums,hmm, i+1);
            
            hmm.push_back(nums[i]);
            helper(ans,nums,hmm, i+1);
            hmm.pop_back();
        
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> hmm;
        helper(ans, nums, hmm, 0);
        return ans;
    }
};


https://leetcode.com/problems/subsets-ii/


class Solution {
public:
    
void backtrack(vector<int>& cand, vector<vector<int>>& ans, vector<int>& curr, int index) {
        if(index==cand.size()) {
            ans.push_back(curr);
            return;
        }
        if(index > cand.size()) return;
    
        
            curr.push_back(cand[index]);
            backtrack(cand, ans, curr, index + 1);
            curr.pop_back();
while(index + 1 < cand.size() && cand[index + 1] == cand[index]) ++index;
            backtrack(cand, ans, curr, index + 1);
        
    }
    
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, curr, 0);
        return ans;
    }
};
