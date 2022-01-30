
█▀▀ █▀█ █▀▀ ▄▀█ ▀█▀ █▀▀   █▀▄▀█ █ █▀█ █▀█ █▀█ █▀█   █▀█ █▀▀   ▀█▀ █▀█ █▀▀ █▀▀
█▄▄ █▀▄ ██▄ █▀█ ░█░ ██▄   █░▀░█ █ █▀▄ █▀▄ █▄█ █▀▄   █▄█ █▀░   ░█░ █▀▄ ██▄ ██▄

void mirror(Node* root)
{
    if(!root) return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left,root->right);
}


█▀▀ █░█ █▀▀ █▀▀ █▄▀   ▀█   █▄░█ ▄▄ ▄▀█ █▀█ █▄█   ▀█▀ █▀█ █▀▀ █▀▀   █▀▄▀█ █ █▀█ █▀█ █▀█ █▀█
█▄▄ █▀█ ██▄ █▄▄ █░█   █▄   █░▀█ ░░ █▀█ █▀▄ ░█░   ░█░ █▀▄ ██▄ ██▄   █░▀░█ █ █▀▄ █▀▄ █▄█ █▀▄

https://www.geeksforgeeks.org/check-mirror-n-ary-tree/

    int M = 7, N = 6;
     
    //Tree 1
    int u1[] = { 1, 1, 1, 10, 10, 10 };
    int v1[] = { 10, 7, 3, 4, 5, 6 };
   
    //Tree 2
    int u2[] = { 1, 1, 1, 10, 10, 10 };
    int v2[] = { 3, 7, 10, 6, 5, 4 };

here tree are given like this u is parent of corresponding v

int checkMirrorTree(int M, int N, int u1[ ],
                    int v1[ ] , int u2[], int v2[])
    {
        // Map to store nodes of the tree
        unordered_map<int , stack<int>>mp;
   
        // Traverse first tree nodes
        for (int i = 0 ; i < N ; i++ )
        {
           mp[u1[i]].push(v1[i]);
        }
         
        // Traverse second tree nodes
        for (int i = 0 ; i < N ; i++)
        {
            if(mp[u2[i]].top() != v2[i])
                  return 0;
            mp[u2[i]].pop();
        }
   
        return 1;
    }
