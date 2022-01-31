https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


I have two cases if the nodes are present in tree for sure  and 2nd is if they are not 
  
  
  
█▀▀ ▄▀█ █▀ █▀▀   ▄█   ▄▄   █▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▀█ ▄█ ██▄   ░█   ░░   █▄▄ █▄█ █▄▀ ██▄

if both present


 class Solution {
 public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(!root) return NULL;
         if(root == p || root == q) return root;
         TreeNode* left = lowestCommonAncestor(root->left , p , q);
         TreeNode* right = lowestCommonAncestor(root->right, p, q);
         if(left && right) return root;
         if(!left && !right) return NULL;
         return left ? left : right;
     }
 };




█▀▀ ▄▀█ █▀ █▀▀   ▀█   ▄▄   █▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▀█ ▄█ ██▄   █▄   ░░   █▄▄ █▄█ █▄▀ ██▄

if any or both not there 


█▀█ ▄▀█ ▀█▀ █░█   █▀█ █▀█ █▀█ ▀█▀   ▀█▀ █▀█   █▄░█ █▀█ █▀▄ █▀▀
█▀▀ █▀█ ░█░ █▀█   █▀▄ █▄█ █▄█ ░█░   ░█░ █▄█   █░▀█ █▄█ █▄▀ ██▄


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

