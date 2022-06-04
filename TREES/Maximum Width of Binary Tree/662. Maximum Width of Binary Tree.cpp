https://leetcode.com/problems/maximum-width-of-binary-tree/





class Solution {
public:
    
    unordered_map<int,pair<unsigned long long, unsigned long long>> m;
    void util(TreeNode* root, unsigned long long i, int h)
    {
        if(root==NULL)
            return;
      
        if(m.find(h)!=m.end())
        {   if(i<m[h].first)
            m[h].first=i;
         if(i>m[h].first)
         m[h].second=i;
         }
        else
        {
            m[h]={i,i};
        }
        
        util(root->left,2*i+1,h+1);
        util(root->right,2*i+2,h+1);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        
      if(root==NULL)
          return 0;
        
       unsigned long long  i = 1;
        int h = 0;
        
        util(root,i,h);
        
        unsigned long long ans = 0;
        for(auto it:m)
        {   //cout<<it.second.first<<"  "<<it.second.second<<endl;
            ans=max(ans,it.second.second-it.second.first+1);
        }
        
        return (int)ans;
        
    }
    
};
