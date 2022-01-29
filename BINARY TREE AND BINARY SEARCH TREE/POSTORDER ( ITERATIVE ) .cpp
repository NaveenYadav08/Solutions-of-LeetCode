
▀█   █░█░█ ▄▀█ █▄█ █▀
█▄   ▀▄▀▄▀ █▀█ ░█░ ▄█


WAY 1

█░█ █▀ █ █▄░█ █▀▀   ▀█   █▀ ▀█▀ ▄▀█ █▀▀ █▄▀ █▀
█▄█ ▄█ █ █░▀█ █▄█   █▄   ▄█ ░█░ █▀█ █▄▄ █░█ ▄█
  
  
  
▄▀█ █░░ █▀▀ █▀█ █▀█ █ ▀█▀ █░█ █▀▄▀█
█▀█ █▄▄ █▄█ █▄█ █▀▄ █ ░█░ █▀█ █░▀░█

1. Push root to first stack.
2. Loop while first stack is not empty
   2.1 Pop a node from first stack and push it to second stack
   2.2 Push left and right children of the popped node to first stack
3. Print contents of second stack

█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄

void postOrderIterative(Node* root)
{
    if (root == NULL)
        return;
 
    // Create two stacks
    stack<Node *> s1, s2;
 
    // push root to first stack
    s1.push(root);
    Node* node;
 
    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);
 
        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
 
    // Print all elements of second stack
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

WAY 2
  
  
 
█░█ █▀ █ █▄░█ █▀▀   ▄█   █▀ ▀█▀ ▄▀█ █▀▀ █▄▀
█▄█ ▄█ █ █░▀█ █▄█   ░█   ▄█ ░█░ █▀█ █▄▄ █░█

█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄


void postorder_traversal(TreeNode *root)
{
    stack<TreeNode*> st;
    TreeNode *curr = root;
    TreeNode *prev = NULL;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left; // go to left
        }
        else
        {
            curr = st.top();
            if (curr->right == NULL || curr->right == prev)  // if there is no right child or right child is already printed 
              // I can print current
            {
                cout << curr->val << " ";
                st.pop();
                prev = curr;
                curr = NULL;
            }
          // else go to right  do your work there 
            else
                curr = curr->right;
        }
    }
}


