// LINK https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

Node* dummy = New Node(0);
Node* tmp=NULL;

Node *list(Node* l1, Node* l2)
{   if(l1==NULL and l2==NULL) return NULL;
    if(l1==NULL) return list(l1->next,l2);
    else if(l2==NULL) return list(l1,l2->next);
    
    if(l1->val<l2->val)
    {
        Node* taco = New Node(l1->val);
        tmp->bottom=taco;
        tmp=taco;
        return list(l1->bottom,l2);
    }
    else
    {
        Node* taco = New Node(l2->val);
        tmp->bottom=taco;
        tmp=taco;
        return list(l1,l2->bottom);
    }
    
    
    
}
    
Node *flatten(Node *root)
{
   // Your code here
   Node* dummy = New Node(0);
   tmp = dummy;
   list(root, root->next);
   return dummy->bottom;
   
}
