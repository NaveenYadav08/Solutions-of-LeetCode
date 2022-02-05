https://leetcode.com/problems/maximum-binary-tree/


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄

class Solution {
    public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        return buildTree(nums,0,nums.size()-1);
    }
    TreeNode* buildTree(vector<int> nums,int low,int high){
        if(low>high)
            return NULL;
        int mid=low,max=INT_MIN;

        for(int i=low;i<=high;i++){
            if(nums[i]>max){
                max=nums[i];
                mid=i;
            }
        }
        TreeNode* root=new TreeNode(max);
        root->left=buildTree(nums,low,mid-1); // Here mid-1 becomes the left subtree of the root
        root->right=buildTree(nums,mid+1,high); // And mid+1 becomes the right subtree of the root.
        return root;
    }
};
