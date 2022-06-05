https://leetcode.com/problems/serialize-and-deserialize-bst/


class Codec {
public:
    
    TreeNode* fun(TreeNode* root,int val)
    {
        if(!root) return new TreeNode(val);
        if(val>root->val)
            root->right=fun(root->right,val);
        else
            root->left=fun(root->left,val);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            root=fun(root,preorder[i]);
        }
        return root;
        
    }
    
    
    
    void pre(TreeNode* root, string& sus)
    {
        if(root==NULL) return;
        sus+=to_string(root->val)+",";
        pre(root->left,sus);
        pre(root->right,sus);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string sus="";
        pre(root, sus);
        return sus;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        vector<int> PRE;
       
        
        string soka="";
        for(int i=0;i<data.size();i++)
        {   if(data[i]==',')
           {
              int hmm=stoi(soka);
              PRE.push_back(hmm);
              soka="";
            
           }
          else
            soka+=data[i];
            
        }
        
        return bstFromPreorder(PRE);
        
        
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
