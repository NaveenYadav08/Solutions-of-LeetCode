https://leetcode.com/problems/complete-binary-tree-inserter/


class CBTInserter {
public:
    TreeNode* root;
    CBTInserter(TreeNode* root) {
        this->root = root;
    }
    
    int insertToBT(TreeNode* root, int val){
        queue<TreeNode*>st;
        st.push(root);
        while(st.empty()==false){
            int size = st.size();
            while(size>0){
                TreeNode* temp = st.front();
                st.pop();size--;
                if(temp->left)st.push(temp->left);
                else
                {
                    temp->left=new TreeNode(val);
                    return temp->val;
                }
                if(temp->right)st.push(temp->right);
                else
                {
                    temp->right=new TreeNode(val);
                    return temp->val;
                }
            }
        }
        return -1;
            
    }
    
    int insert(int v) {
        if(root==NULL){
            root=new TreeNode(v);
            return -1;
        }
        else
        {
            TreeNode* curr = root;
            return insertToBT(curr,v);
        }
    }
    
    TreeNode* get_root() {
        return root;
    }
};
