GFG 
https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

Same as level order just slight variation 
reverse the vector of vector ans at the end , or insert right then left and rev ans at end.
  
  
  
  
█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄
  
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    if(!root) 
    return ans;
    
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node * temp=q.front();
        q.pop();
        if(temp!=NULL)
        {    
          // right then left
            ans.push_back(temp->data);
            if(temp->right)
            q.push(temp->right);
            if(temp->left)
            q.push(temp->left);
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}
