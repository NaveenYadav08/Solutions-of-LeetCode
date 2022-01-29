Structure of  Nary Tree
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


█ █▄░█ █▀█ █▀█ █▀▄ █▀▀ █▀█
█ █░▀█ █▄█ █▀▄ █▄▀ ██▄ █▀▄
void inorder(Node *node)
{
    if (node == NULL)
        return;
 
    // Total children count
    int total = node->length;
     
    // All the children except the last
    for (int i = 0; i < total - 1; i++)
        inorder(node->children[i]);
 
    // Print the current node's data
    cout<< node->data << " ";
 
    // Last child
    inorder(node->children[total - 1]);
}



█▀█ █▀█ █▀▀ █▀█ █▀█ █▀▄ █▀▀ █▀█
█▀▀ █▀▄ ██▄ █▄█ █▀▄ █▄▀ ██▄ █▀▄
class Solution {
public:
    vector<int> ans;
    void helper(Node* root)
    {
        if(root==NULL) return;
        ans.push_back(root->val);
        for(int i=0;i<root->children.size();i++)
        {
            helper(root->children[i]);
        }
    }
    
    vector<int> preorder(Node* root) {
        ans.clear();
        if(root==NULL) return ans;
        helper(root);
        return ans; 
    }
};


█▀█ █▀█ █▀ ▀█▀ █▀█ █▀█ █▀▄ █▀▀ █▀█
█▀▀ █▄█ ▄█ ░█░ █▄█ █▀▄ █▄▀ ██▄ █▀▄
class Solution {
public:
    vector<int> ans;    
    void helper(Node* root)
    {
        if(root==NULL) return;
        
        for(int i=0;i<root->children.size();i++)
        {
            helper(root->children[i]);
        }
        ans.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        ans.clear();
        if(root==NULL) return ans;
        helper(root);
        return ans; 
    }
};

  
  
  
