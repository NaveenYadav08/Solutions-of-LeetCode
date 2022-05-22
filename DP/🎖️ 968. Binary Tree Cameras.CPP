// https://leetcode.com/problems/binary-tree-cameras/

// 968. Binary Tree Cameras

class Solution {
public:
    int res_;
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == NONE) res_++;
        return res_;
    }

private:
    // NONE means neither cover nor camera , else are explained
    int  NONE = 0, CAMERA = 1, COVERED = 2;
    int dfs(TreeNode* root){
        if(!root) return COVERED; // null is child node of leaf node so covered
        int l = dfs(root->left), r = dfs(root->right);
        if(l == NONE || r == NONE){ // IF LEFT YA RIGHT none TO CURR PR CAMERA LAGAU
            res_++;
            return CAMERA;
        }
        return (l == CAMERA || r == CAMERA) ? COVERED: NONE;  //  IF LEFT YA RIGHT CAMERA TO ROOT COVER HUA ELSE NONE
    }
};

// https://www.youtube.com/watch?v=2Gh5WPjAgJk
