https://leetcode.com/problems/path-sum-ii/

class Solution {
public:
    vector<vector<int>> ans; 
    
    void helper(TreeNode* root, vector<int>& nums, int sum)
    {
        if(root==NULL) return;
        sum-=root->val;
        nums.push_back(root->val);
        if(sum==0 and !root->left and !root->right ) 
        { ans.push_back(nums); nums.pop_back(); return; }
        helper(root->left,nums,sum);
        helper(root->right,nums,sum);
        sum+=root->val;
        nums.pop_back();
        
       
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
          ans.clear();
          vector<int> tmp;
          helper(root, tmp, targetSum);
          return ans;
          
        
    }
};
