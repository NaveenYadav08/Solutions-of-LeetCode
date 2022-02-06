leetcode - https://leetcode.com/problems/maximum-width-of-binary-tree/


I will reindex the nodes and just find max of diffrnce between most left and most right 


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        q.push({NULL, -1});
        unsigned long long l = 0, r, ans = 0;
        while(!q.empty())
        {            
            auto tnode = q.front().first;
            auto tlevel = q.front().second;
            q.pop();
            
            if(tnode)
            {
                r = tlevel;
                if(tnode->left)
                    q.push({tnode->left, 2 * r + 1});
                if(tnode->right)
                    q.push({tnode->right, 2 * r + 2});
            }
            else
            {
                ans = max(ans, r - l + 1);
                if(!q.empty())
                    l = q.front().second, q.push({NULL, -1});
            }
        }
        
        return ans;
    }
}
