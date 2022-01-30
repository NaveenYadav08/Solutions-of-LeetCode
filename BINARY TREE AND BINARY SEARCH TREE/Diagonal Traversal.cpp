// GFG 
https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1/


█▄▄ █▀▀ █▀
█▄█ █▀░ ▄█


vector<int> diagonal(Node *root)
{
    queue<Node*> Q;
    Node *p;
    Q.push(root);
    vector<int> diagonalNode;
    while (!Q.empty())
    {
        p=Q.front();
        Q.pop();
        while (p)
        {
            if(p->left)
                Q.push(p->left);
            //cout<<p->data<<" ";
            diagonalNode.push_back(p->data);
            p=p->right;
        }
    }
    return diagonalNode;
    
}






█▀▄ █▀▀ █▀
█▄▀ █▀░ ▄█

void diagonalPrintUtil(Node* root, int d,
                map<int, vector<int>> &diagonalPrint)
{
    // Base case
    if (!root)
        return;
 
    // Store all nodes of same
    // line together as a vector
    diagonalPrint[d].push_back(root->data);
 
    // Increase the vertical
    // distance if left child
    diagonalPrintUtil(root->left,
                      d + 1, diagonalPrint);
 
    // Vertical distance remains
    // same for right child
    diagonalPrintUtil(root->right,
                         d, diagonalPrint);
}
 
// Print diagonal traversal
// of given binary tree
void diagonalPrint(Node* root)
{
     
    // create a map of vectors
    // to store Diagonal elements
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
 
    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }
}
