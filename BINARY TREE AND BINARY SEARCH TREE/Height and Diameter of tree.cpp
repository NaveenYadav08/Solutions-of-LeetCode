
█░█ █▀▀ █ █▀▀ █░█ ▀█▀
█▀█ ██▄ █ █▄█ █▀█ ░█░
    int height(struct Node* node)
    {
        //if node is null, we return 0.
        if (node==NULL)
            return 0;

        //else we call the recursive function, height for left and right 
        //subtree and choose their maximum. we also add 1 to the result
        //which indicates height of root of the tree.
        else
            return 1 + max(height(node->left), height(node->right));
    } 


█▀▄ █ ▄▀█ █▀▄▀█ █▀▀ ▀█▀ █▀▀ █▀█
█▄▀ █ █▀█ █░▀░█ ██▄ ░█░ ██▄ █▀▄

int diameter(Node* root)
    {
    // Your code here
     if(root==NULL)
     return 0;
     
     int ld=diameter(root->left);
     int rd=diameter(root->right);
     
     int lh=height(root->left);
     int rh=height(root->right);
     
     return max(max(ld,rd), 1+lh+rh);
    }
