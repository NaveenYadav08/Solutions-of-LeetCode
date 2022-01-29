GFG 
https://practice.geeksforgeeks.org/problems/level-order-traversal/1

Leetcode 
https://leetcode.com/problems/binary-tree-level-order-traversal/


It is done using queue ( FIFO )
  
In queue insert NULL after every level end


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄

CODE - ( leetcode )
  
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(root==NULL)
            return res;
        
        queue<TreeNode*> q;
        
         q.push(root);
         q.push(NULL); // here first level ends
        
         vector<int> temp;
      
        while(!q.empty())
        {
            TreeNode* T=q.front();
            q.pop();
            
            if(T==NULL) // means begin of another level and start of one level 
            {
                res.push_back(temp);
                temp.clear();
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                    temp.push_back(T->val);
                    if(T->left)
                        q.push(T->left);
                    if(T->right)
                        q.push(T->right);
            }
        }
        return res;   
    }
};
