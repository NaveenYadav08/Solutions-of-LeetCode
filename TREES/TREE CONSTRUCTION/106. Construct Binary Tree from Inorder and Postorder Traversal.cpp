
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
public:
    int idx=0;
    unordered_map<int,int> m;
    
    TreeNode* rec(vector<int>& inorder, vector<int>& postorder, int l, int r)
    {if(l>r) return NULL;
     
     TreeNode* tmp = new TreeNode(postorder[idx--]);
     if(l==r)
         return tmp;
     int M = m[tmp->val];
      tmp->right= rec(inorder,postorder,M+1,r);
     tmp->left = rec(inorder,postorder,l,M-1);
    
     return tmp;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx = inorder.size()-1;
        m.clear();
        for(int i=0; i<inorder.size(); i++)
        {
            m[inorder[i]]=i;
        }
        int n = inorder.size();
        return rec(inorder,postorder,0,n-1);
    }
};
