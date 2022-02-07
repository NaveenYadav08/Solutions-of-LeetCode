https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

i wlll make left half as left subtree and right half as right subtree


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int m = (left + right) / 2;
        TreeNode* t = new TreeNode(nums[m]);
        t->left = build(nums, left, m - 1);
        t->right = build(nums, m + 1, right);
        return t;
    }
};
