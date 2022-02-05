LEETCODE
https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

bfs sae deepest nodes find kre then unka LCA return krdia


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄


class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
         if(root->left==NULL && root->right==NULL)
         return root;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        pair<TreeNode*,TreeNode*>p;
        while(!q.empty())
        {
            if(q.front()==NULL)
            {
                q.pop();
                if(q.empty())
                    break;
                /*storing the first node of current level */
                p.first=q.front();
                q.push(NULL);
            }
            TreeNode*temp=q.front();
            q.pop();
             /*storing the last node of  current level */
            if(q.front()==NULL)
                p.second=temp;
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
        return helper(root,p.first,p.second);
    }
    
    
    /* for finding LCA */
    TreeNode*helper(TreeNode*root,TreeNode*p,TreeNode*q)
    {
        if(!root || root==p || root==q)
            return root;
        TreeNode*left=helper(root->left,p,q);
         TreeNode*right=helper(root->right,p,q);
        if(left && right)
            return root;
        else
            return(left==NULL?right:left);
        
    }
    
};
