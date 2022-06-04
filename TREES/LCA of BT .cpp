https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

BOTH MUST BE PRESENT IN TREE 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL) return NULL;
        
        if(root==p or root==q) return root;
        
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(l&&r) return root;
        if(l) return l;
        return r;
        
        

        
    }
};


IF some node can be absent 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:


bool hasPath(TreeNode *root, vector<TreeNode*>& arr, TreeNode* x)
{
	// if root is NULL
	// there is no path
	if (!root)
		return false;
	
	// push the TreeNode's value in 'arr'
	arr.push_back(root);
	
	// if it is the required TreeNode
	// return true
	if (root == x)
		return true;
	
	// else check whether the required TreeNode lies
	// in the left subtree or right subtree of
	// the current TreeNode
	if (hasPath(root->left, arr, x) ||
		hasPath(root->right, arr, x))
		return true;
	
	// required TreeNode does not lie either in the
	// left or right subtree of the current TreeNode
	// Thus, remove current TreeNode's value from
	// 'arr'and then return false
	arr.pop_back();
	return false;		
}
     
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
         vector<TreeNode*> v2;
         
         if(hasPath(root,v1,p) and hasPath(root,v2,q))
         {
             int i=0;
             while(i<min(v1.size(),v2.size()) and v1[i]==v2[i])
             {
                 i++;
             }
             return v1[i-1];
             
         }
         else
         {
             cout<<"NOT PRESENT";
             return NULL;
         }
     }
 };
