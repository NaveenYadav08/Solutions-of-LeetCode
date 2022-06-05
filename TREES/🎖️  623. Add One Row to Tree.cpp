https://leetcode.com/problems/add-one-row-to-tree/

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        vector<TreeNode*> a;
        while(!q.empty())
        {   lvl++;
            //cout<<lvl<<endl;
            int n = q.size();
            for(int i=0;i<n;i++)
            {   TreeNode* tmp = q.front();
                q.pop();
                if(lvl==depth-1)
                a.push_back(tmp);
             if(tmp->left)
                 q.push(tmp->left);
             if(tmp->right)
                 q.push(tmp->right);
             
            }
            if(lvl==depth-1) break;
            
        }
        
        for( auto x:a )
        {
            TreeNode* T= new TreeNode (val);
            TreeNode* TT=new TreeNode (val);
            TreeNode* L = x->left;
            TreeNode* R = x->right;
            x->left=T;
            T->left = L;
            x->right=TT;
            TT->right=R;
            
        }
   
        
        
        return root;

    }
};
