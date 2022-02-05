https://leetcode.com/problems/complete-binary-tree-inserter/
leeocode


do bst and insert at the first null place


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



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


/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
