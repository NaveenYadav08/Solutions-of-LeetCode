// INORDER MORRIS TRAVERSAL //

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        TreeNode* curr = root;
        
        while(curr)
        {
            if(!curr->left){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* Look_for_predecessor = curr->left;
                while(Look_for_predecessor->right && Look_for_predecessor->right!=curr){
                    Look_for_predecessor = Look_for_predecessor ->right;
                }
                if(Look_for_predecessor->right==NULL) // fail due to this ( NOT VISITED )
                {
                    Look_for_predecessor->right = curr;
                    curr=curr->left;

                }
                else //  fail due to Look_for_predecessor->right!=curr ( VISITED )
                {
                    Look_for_predecessor->right=NULL; // Restore 
                    ans.push_back(curr->val); // PRINT //
                    curr=curr->right;
                }

            }
        }
        return ans;
    }
