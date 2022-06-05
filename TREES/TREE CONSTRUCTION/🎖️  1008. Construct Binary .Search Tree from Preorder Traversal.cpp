https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/


class Solution {
public:
    int pI = 0;                                                                                                                                                                                                       
  
    TreeNode* helper(vector<int>& pre,int key, int m, int M)
    {
        if(pI>=pre.size()) return NULL;
        TreeNode* root=NULL;
        if(key>m and key<M)
        {
            root=new TreeNode(key);
            pI++;
            
            if(pI<pre.size())
            {
                root->left = helper(pre,pre[pI],m,key);
            }
            if(pI<pre.size())
            {
                root->right = helper(pre,pre[pI],key,M);
            }
            
            
        }
        
        
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        pI = 0;
        return helper(preorder,preorder[0],INT_MIN,INT_MAX);
        
    }
    
    
};
