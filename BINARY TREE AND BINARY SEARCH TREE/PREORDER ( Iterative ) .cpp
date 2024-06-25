
░█████╗░██╗░░░░░░██████╗░░█████╗░██████╗░██╗████████╗██╗░░██╗███╗░░░███╗
██╔══██╗██║░░░░░██╔════╝░██╔══██╗██╔══██╗██║╚══██╔══╝██║░░██║████╗░████║
███████║██║░░░░░██║░░██╗░██║░░██║██████╔╝██║░░░██║░░░███████║██╔████╔██║
██╔══██║██║░░░░░██║░░╚██╗██║░░██║██╔══██╗██║░░░██║░░░██╔══██║██║╚██╔╝██║
██║░░██║███████╗╚██████╔╝╚█████╔╝██║░░██║██║░░░██║░░░██║░░██║██║░╚═╝░██║
╚═╝░░╚═╝╚══════╝░╚═════╝░░╚════╝░╚═╝░░╚═╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░░░░╚═╝

1) Create an empty stack nodeStack and push root node to stack. 
2) Do the following while nodeStack is not empty. 
….a) Pop an item from the stack and print it. 
….b) Push right child of a popped item to stack 
….c) Push left child of a popped item to stack
The right child is pushed before the left child to make sure that the left subtree is processed first bcz of LIFO nature of stack.
  


░█████╗░░█████╗░██████╗░███████╗
██╔══██╗██╔══██╗██╔══██╗██╔════╝
██║░░╚═╝██║░░██║██║░░██║█████╗░░
██║░░██╗██║░░██║██║░░██║██╔══╝░░
╚█████╔╝╚█████╔╝██████╔╝███████╗
░╚════╝░░╚════╝░╚═════╝░╚══════╝

    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
            
        }
        return ans;
    }
