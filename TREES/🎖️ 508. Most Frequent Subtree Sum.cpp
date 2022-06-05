https://leetcode.com/problems/most-frequent-subtree-sum/


class Solution {
public:
    
    int findMostFrequentSum(TreeNode* root, int &maxValue, unordered_map<int, int> &mp){
        if(!root) return 0;
        
        int l = findMostFrequentSum(root->left, maxValue, mp);
        int r = findMostFrequentSum(root->right, maxValue, mp);
        int totalSum = l + r + root->val;
        mp[totalSum]++;
        maxValue = max(maxValue, mp[totalSum]);
        return totalSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxValue = INT_MIN;
        unordered_map<int, int> mp;
        findMostFrequentSum(root, maxValue, mp);
        
        vector<int> res;
        for(auto a: mp){
            if(a.second == maxValue) res.push_back(a.first);
        }
        return res;
    }
};
