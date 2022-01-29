GFG 
https://practice.geeksforgeeks.org/problems/level-order-traversal/1

Leetcode 
https://leetcode.com/problems/binary-tree-level-order-traversal/
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/ 
// this other one is simple just reverse the ans of above one or use a stack to do so 


It is done using queue ( FIFO )
  
In queue insert NULL after every level end


▄▀█ █░░ █▀▀ █▀█ █▀█ █ ▀█▀ █░█ █▀▄▀█ █▀▄▀█
█▀█ █▄▄ █▄█ █▄█ █▀▄ █ ░█░ █▀█ █░▀░█ █░▀░█

1 Push root in queue
2 Until q is empty push left and right children of the front element and pop it


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
            
            if(T==NULL) // means begin of another level and end of one level 
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
