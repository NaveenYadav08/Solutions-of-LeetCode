https://leetcode.com/problems/cousins-in-binary-tree/


class Solution {
    int find_HeightParent(TreeNode *curr,int &parent,int value,int height)
    {
        if(!curr)
            return 0;
        if(curr->val==value)
            return height;
        
        parent = curr->val;
        int left = find_HeightParent(curr->left,parent,value,height+1);
        if(left)
            return left;
        parent = curr->val;
        int right = find_HeightParent(curr->right,parent,value,height+1);
        if(right) return right;
        
        return 0;
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {

        
        if(root->val==x || root->val==y)
            return false;
            
        int parent=-1;
        int xHeight = find_HeightParent(root,parent,x,0);
        
        int yParent=-1;
        int yHeight = find_HeightParent(root,yParent,y,0);
        
        if(parent!=yParent && xHeight==yHeight)
            return true;        
        
        if(xHeight==0 and root->val!=x)
            cout<<x<<" is not present in Tree"<<endl;
        if(yHeight==0 and root->val!=y)
            cout<<y<<" is not present in Tree"<<endl;
        
        return false;
    }
};
