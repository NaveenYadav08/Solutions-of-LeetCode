https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/


class Solution {
public:
    map<int,map<int,vector<int>>> m;
    void util(TreeNode* root,int vdist, int hdist)
    {
        if(root==NULL) return;
        
        m[vdist][hdist].push_back(root->val);
        util(root->left,vdist-1,hdist+1);
        util(root->right,vdist+1,hdist+1);
            
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(!root)
            return ans;
        
        
        int vdist = 0;
        int hdist = 0;
        
        util(root,vdist,hdist);
        
        for(auto it = m.begin(); it != m.end(); it++){
             vector<int> tmp;
            for(auto iq = it->second.begin(); iq != it->second.end(); iq++){
                sort(iq->second.begin(),iq->second.end());
                for(int i=0;i<iq->second.size();i++)
                {
                    tmp.push_back(iq->second[i]);
                }
                
                
            }
            ans.push_back(tmp);
            
        }
        
        return ans;
        
    }
    
};
