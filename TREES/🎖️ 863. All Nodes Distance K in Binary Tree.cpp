https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/


class Solution {
public:
    
    vector<TreeNode*> Nodepath; //stored here root to target tk kae nodes
    bool Nodetoroot(TreeNode* root,TreeNode* target){
        if(root==NULL) return false;
        
        if(root==target){
            Nodepath.push_back(root);
            return true;
        }
        
        bool leftans=Nodetoroot(root->left,target);
        if(leftans==true){
            Nodepath.push_back(root);
            return true;
        }
        bool rightans=Nodetoroot(root->right,target);
        if(rightans==true){
            Nodepath.push_back(root);
            return true;
        }
        return false;
    }
    
    vector<int> ans;
    void distanceFar(TreeNode* root, TreeNode* target, int k){
        if(root==NULL || root==target || k<0) return;
        
        if(k==0) {ans.push_back(root->val); return;}
        distanceFar( root->left,target, k-1);
        distanceFar( root->right,target, k-1);
        
    }
    
    
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    Nodetoroot(root,target);
    for(auto x:Nodepath)
    {
        //cout<<x->val<<endl;
    }
    
        for(int i=0;i<Nodepath.size() && i<=k;i++){
            cout<<Nodepath[i]->val<<"  "<<k-i<<endl;
            distanceFar(Nodepath[i],i==0 ? NULL: Nodepath[i-1],k-i);
        }
        return ans;
    }
};
