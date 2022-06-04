https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/


class Solution {
public:
//     TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
//     }
    
    int preIndex=0;
unordered_map<int,int> m;

TreeNode* constructTreeUtil (vector<int>& pre, vector<int>& post, int& preIndex,
								int l, int h, int size)
{
	// Base case
	if (preIndex >= size || l > h)
		return NULL;

	// The first TreeNode in preorder traversal is root. So take the TreeNode at
	// preIndex from preorder and make it root, and increment preIndex
	TreeNode* root = new TreeNode ( pre[preIndex] );
	++preIndex;

	// If the current subarray has only one element, no need to recur
	if (l == h)
		return root;

	// Search the next element of pre[] in post[]
	int i=m[pre[preIndex]];

	// Use the index of element found in postorder to divide
		// postorder array in two parts. Left subtree and right subtree
	if (i <= h)
	{
		root->left = constructTreeUtil (pre, post, preIndex,
												l, i, size);
		root->right = constructTreeUtil (pre, post, preIndex,
												i + 1, h-1, size);
	}

	return root;
}

// The main function to construct Full Binary Tree from given preorder and
// postorder traversals. This function mainly uses constructTreeUtil()
TreeNode *constructFromPrePost (vector<int>& pre, vector<int>& post)
{
	preIndex = 0;
    int size=pre.size();
    m.clear();
    for(int i=0;i<size;i++)
    {
        m[post[i]]=i;
    }
	return constructTreeUtil (pre, post, preIndex, 0, size - 1, size);
}
};

