// LINK https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

Node* merge(Node *a, Node *b)
{
    if(a==NULL) return b;
    if(b==NULL) return a;
    
    Node *r;
    if(a->data < b->data)
    {
        r=a;
        r->bottom=merge(a->bottom,b);
    }
    else
    {
        r=b;
        r->bottom=merge(a,b->bottom);
    }
    
    return r;
}
    
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL or root->next==NULL) return root;
   
   return merge(root, flatten(root->next));
}
