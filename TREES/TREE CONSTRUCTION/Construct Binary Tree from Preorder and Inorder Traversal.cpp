https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


class Solution {
public:
    int idx = 0;
    unordered_map<int,int> m;
        
        TreeNode* rec(vector<int> inorder, vector<int> preorder,int l,int r)
    {
        if(l>r)
            return NULL;
        
        TreeNode* tmp = new TreeNode(preorder[idx++]);
        if(l==r)
            return tmp;
        
        int M = m[tmp->val];
        
        tmp->left = rec(inorder,preorder,l,M-1);
        tmp->right = rec(inorder,preorder,M+1,r);
        return tmp;
        
    }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        
        idx=0;
        m.clear();
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        int n =inorder.size();
        return rec(inorder,preorder,0,n-1);
    }

};

