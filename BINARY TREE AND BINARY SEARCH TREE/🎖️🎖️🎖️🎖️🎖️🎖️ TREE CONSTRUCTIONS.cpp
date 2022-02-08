
█ █▄░█ █▀█ █▀█ █▀▄ █▀▀ █▀█   ▄▀█ █▄░█ █▀▄   █▀█ █▀█ █▀▀ █▀█ █▀█ █▀▄ █▀▀ █▀█   ▀█▀ █▀█   █▄▄ ▀█▀
█ █░▀█ █▄█ █▀▄ █▄▀ ██▄ █▀▄   █▀█ █░▀█ █▄▀   █▀▀ █▀▄ ██▄ █▄█ █▀▄ █▄▀ ██▄ █▀▄   ░█░ █▄█   █▄█ ░█░
Algorithm: buildTree() 
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick the next element in the next recursive call. 
2) Create a new tree node tNode with the data as the picked element. 
3) Find the picked element’s index in Inorder. Let the index be inIndex. 
4) Call buildTree for elements before inIndex and make the built tree as a left subtree of tNode. 
5) Call buildTree for elements after inIndex and make the built tree as a right subtree of tNode. 
6) return tNode.
  
  CODE 
class Solution{
  public:
    int findIndex(int arr[], int start, int target)
    {
        int i=0;
        while( arr[start+i] != target ) i++;
        return i;
    }
    
    Node* buildUtil(int inorder[], int preorder[], int inStart, int preStart, int n)
    {
        if(n==0) return NULL;
        
        Node* ret = new Node( preorder[preStart] );
        
        int i = findIndex( inorder, inStart, preorder[preStart] );
        
        ret->left = buildUtil( inorder, preorder, inStart, preStart+1, i );
        ret->right = buildUtil( inorder, preorder, inStart+i+1, preStart+i+1, n-i-1 );
        
        return ret;
    }
    
    Node *buildTree(int inorder[], int preorder[], int n)
    {
        return buildUtil(inorder, preorder, 0, 0, n);
    }
};




█ █▄░█ █▀█ █▀█ █▀▄ █▀▀ █▀█   ▄▀█ █▄░█ █▀▄   █▀█ █▀█ █▀ ▀█▀ █▀█ █▀█ █▀▄ █▀▀ █▀█   ▀█▀ █▀█   █▄▄ ▀█▀
█ █░▀█ █▄█ █▀▄ █▄▀ ██▄ █▀▄   █▀█ █░▀█ █▄▀   █▀▀ █▄█ ▄█ ░█░ █▄█ █▀▄ █▄▀ ██▄ █▀▄   ░█░ █▄█   █▄█ ░█░
