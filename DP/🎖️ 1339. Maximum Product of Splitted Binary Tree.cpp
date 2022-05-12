// LINK https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

// CODE 

// find sum Tree 

// maximize left subtree sum prosuct , right subtree sum product 


#define mod 1000000007
class Solution {
public:
    unordered_map<TreeNode*,int> mp;
    int findSum(TreeNode* root){
        if(root==NULL) return 0;
        int leftsum=findSum(root->left);
        int rightsum=findSum(root->right);
        mp[root]=root->val+leftsum+rightsum;
        return (root->val+leftsum+rightsum)%mod;
    }
    
    void myfun(TreeNode* root, TreeNode* curr, long long int &res){
        
        if(curr==NULL)return ;
        int t=mp[root]; // total sum is stored at root 
        myfun(root,curr->left,res);
        myfun(root,curr->right,res);
        long long  int l=mp[curr->left];  
        long long int r=mp[curr->right]; 
        res=max(res,max(l*(t-l),r*(t-r))); 
        
    }
    
    int maxProduct(TreeNode* root) {
        if(root==NULL)return 0;
        findSum(root); // to find sum of all subtreee of tree
        long long int res=INT_MIN;
        
        myfun(root,root,res);
        
        return res%mod;
    }
};
