LEFT and RIGHT VIEW 

BFS - 
vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=1;i<=n;i++)
            {
               TreeNode* ptr= q.front();
                q.pop();
                  if(i==n) // this will make it Right View
                  if(i==1) // This will make it Left View
                  ans.push_back(ptr->val);
                if(ptr->left!=NULL)q.push(ptr->left);
                if(ptr->right!=NULL)q.push(ptr->right);
            }
        }
        return ans;
    }

DFS - 
    vector<int>ans;
    unordered_map<int,int> mx;
    void helper(TreeNode* root,int h){
        if(root == NULL) return;
        
        cout<<root->val<<" "<<h<<" | ";
         
        if(!mx.count(h))
        {mx[h]=1;ans.push_back(root->val);}
        
        // left than right give me LEFT VIEW
        helper(root->left,h+1);
        helper(root->right,h+1);
       // right than left give me RIGHT VIEW
      helper(root->right,h+1);  
      helper(root->left,h+1);  
    }


TOP and BOTTOM VIEW 

