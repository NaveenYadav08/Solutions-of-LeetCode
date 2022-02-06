With space ,  BFS  for both 1 and 2
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄

LEETCODE 
LEETCODE -
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/



█▄▄ █▀▀ █▀   █▀▀ █▀█ █▀▄ █▀▀
█▄█ █▀░ ▄█   █▄▄ █▄█ █▄▀ ██▄


class Solution {
public:
    Node* connect(Node* root) {
          if(root==NULL){
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n-1;i++){
                Node* temp = q.front();
                q.pop();
                temp->next = q.front();
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
            }
            Node* temp = q.front();
                q.pop();
                temp->next = NULL;
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
        }
        return root;
    }

};




██████╗░███████╗░██████╗  ░█████╗░░█████╗░██████╗░███████╗  ░░░░░░  ░░███╗░░
██╔══██╗██╔════╝██╔════╝  ██╔══██╗██╔══██╗██╔══██╗██╔════╝  ░░░░░░  ░████║░░
██║░░██║█████╗░░╚█████╗░  ██║░░╚═╝██║░░██║██║░░██║█████╗░░  █████╗  ██╔██║░░
██║░░██║██╔══╝░░░╚═══██╗  ██║░░██╗██║░░██║██║░░██║██╔══╝░░  ╚════╝  ╚═╝██║░░
██████╔╝██║░░░░░██████╔╝  ╚█████╔╝╚█████╔╝██████╔╝███████╗  ░░░░░░  ███████╗
╚═════╝░╚═╝░░░░░╚═════╝░  ░╚════╝░░╚════╝░╚═════╝░╚══════╝  ░░░░░░  ╚══════╝


class Solution {
public:
// Dfs Approach 1 
    Node* connect(Node* root) {
        if(!root) return root;
        
//      Connecting both childs to a root
        if(root->left) root->left->next = root->right;
        
//      connecting right child of current node and left child of root->next
//      Added root->left condition to counter leaf nodes
        if(root->left && root->next) root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
        return root;
    }
};



██████╗░███████╗░██████╗  ░█████╗░░█████╗░██████╗░███████╗  ░░░░░░  ██████╗░
██╔══██╗██╔════╝██╔════╝  ██╔══██╗██╔══██╗██╔══██╗██╔════╝  ░░░░░░  ╚════██╗
██║░░██║█████╗░░╚█████╗░  ██║░░╚═╝██║░░██║██║░░██║█████╗░░  █████╗  ░░███╔═╝
██║░░██║██╔══╝░░░╚═══██╗  ██║░░██╗██║░░██║██║░░██║██╔══╝░░  ╚════╝  ██╔══╝░░
██████╔╝██║░░░░░██████╔╝  ╚█████╔╝╚█████╔╝██████╔╝███████╗  ░░░░░░  ███████╗
╚═════╝░╚═╝░░░░░╚═════╝░  ░╚════╝░░╚════╝░╚═════╝░╚══════╝  ░░░░░░  ╚══════╝


class Solution {
public:
Node* connect(Node* root) {
        if(!root) return root;
        
//      Connecting both childs of root
        if(root->left) root->left->next = root->right;
        
//      Finding first element to the side right of root->right
//      if root->right = NULL, then we connect root->left to first node we find on right side 
        Node* temp = root->next;
        while(temp){
            if(temp->left){
                temp = temp->left;
                break;
            }
            if(temp->right){
                temp = temp->right;
                break;
            }
            
            temp = temp->next;
        }
        
//      Connecting children of current root to left or right of root->next
        if(root->right) root->right->next = temp;
        else if(root->left) root->left->next = temp;
        
//      Recursion for right first and then left
        connect(root->right);
        connect(root->left);
        return root;
    }
};




