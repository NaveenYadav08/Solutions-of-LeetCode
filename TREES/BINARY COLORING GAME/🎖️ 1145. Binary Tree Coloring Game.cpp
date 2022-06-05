https://leetcode.com/problems/binary-tree-coloring-game/

class Solution {
public:
    
    static void countNodes(TreeNode* root,int& ans){
        if(root==NULL){
            return;
        } ans=ans+1;
        countNodes(root->left,ans);
        countNodes(root->right,ans);
       
    }
    
    static void findX(TreeNode* root,int x,int& ans1,int& ans2){
        if(root==NULL){
            return;
        }
        if(root->val==x){
            countNodes(root->left,ans1);
            countNodes(root->right,ans2);
            return;
        }
        findX(root->left,x,ans1,ans2);
        findX(root->right,x,ans1,ans2);
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int ans1,ans2,ans3;
        ans1=ans2=ans3=0;
        findX(root,x,ans1,ans2);
        ans3=n-ans1-ans2-1;
        return (max(ans1,max(ans2,ans3)) > n/2);
    }
};
