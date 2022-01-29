// GFG - 
https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1/#
https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

//leetcode
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/



░█████╗░░█████╗░██████╗░███████╗
██╔══██╗██╔══██╗██╔══██╗██╔════╝
██║░░╚═╝██║░░██║██║░░██║█████╗░░
██║░░██╗██║░░██║██║░░██║██╔══╝░░
╚█████╔╝╚█████╔╝██████╔╝███████╗
░╚════╝░░╚════╝░╚═════╝░╚══════╝




vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    vector<int> temp;
    if(root==NULL) return ans;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int RtoL=true;
    while(!q.empty())
    {
        Node* P=q.front();
        q.pop();
        if(P!=NULL)
        {
            temp.push_back(P->data);
            if(P->left)
            q.push(P->left);
            if(P->right)
            q.push(P->right);
        }
        else 
        {   
            if(RtoL)
            {
                for(int i=temp.size()-1;i>=0;i--)
                {
                    ans.push_back(temp[i]);
                    
                }
                
            }
            else
            {
                for(auto x:temp)
                {
                    ans.push_back(x);
                    
                }
            }
            
            RtoL=!RtoL;
            temp.clear();
            //🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥//
            if(!q.empty())
            q.push(NULL);
            
        }

    }
    return ans;
}
