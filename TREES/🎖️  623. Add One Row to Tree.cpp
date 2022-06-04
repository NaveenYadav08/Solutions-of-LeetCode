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
        q.push(root);q.push(NULL);
        int lvl=1;
        vector<TreeNode*> v1;

        while(q.size()>0){
            TreeNode* src=q.front();q.pop();
            if(src!=NULL){
                v1.push_back(src);
                if(src->left){
                    q.push(src->left);
                }if(src->right){
                    q.push(src->right);
                }
                
            }else{
                if(lvl==depth-1){
                    break;
                }
                if(q.size()!=0){
                    q.push(NULL);
                    v1.clear();
                }
                
                lvl++;
            }
        }
        for(int i=0;i<v1.size();i++){
       
            TreeNode* l=v1[i]->left;
            TreeNode* r=v1[i]->right;
            
            
                TreeNode* node=new TreeNode(val);
                v1[i]->left=node;
                node->left=l;
            
                TreeNode* Node=new TreeNode(val);
                v1[i]->right=Node;
                Node->right=r;
            
        }
        return root;
    }
};
