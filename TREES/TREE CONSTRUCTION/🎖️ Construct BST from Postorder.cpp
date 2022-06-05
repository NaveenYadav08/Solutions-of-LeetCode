https://practice.geeksforgeeks.org/problems/construct-bst-from-post-order/1/#

 int pI = 0;
 int sz = 0;
 Node* helper(int pre[], int key, int m, int M)
    {
        if(pI<0) return NULL;
        Node* root=NULL;
        if(key>m and key<M)
        {
            root=new Node(key);
            pI--;
            
            if(pI>=0)
            {
                root->right = helper(pre,pre[pI],key,M);
            }
            if(pI>=0)
            {
                
                root->left = helper(pre,pre[pI],m,key);
            }
            
            
        }
        
        
        return root;
    }
 
 
Node *constructTree (int post[], int size)
{
//code here
        pI = size-1;
        sz = size;
        return helper(post,post[pI],INT_MIN,INT_MAX);
}
