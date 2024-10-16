INSERT   https://leetcode.com/problems/insert-into-a-binary-search-tree/
SEARCH   https://leetcode.com/problems/search-in-a-binary-search-tree/
DELETE   https://leetcode.com/problems/delete-node-in-a-bst/

// IN BST no hard rule if element == x either insert left or right



INSERT   - O( Height )
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(val>root->val)
            root->right=insertIntoBST(root->right,val);
        else
            root->left=insertIntoBST(root->left,val);
        return root;
    }
};

SEARCH  - O( Height )
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        while(curr)
        {
            if(curr->val==val)
                return curr;
            else if(curr->val > val)
                curr=curr->left;
            else
                curr=curr->right;
        }
        return curr;
    }
};


DELETE  - O( Height )
class Solution {
public:
    int findminfromright(TreeNode* root){
        while(root->left!=nullptr)
            root=root->left;
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==nullptr) return root;
        else if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
		// LEAF NODE
            if(root->left==NULL and root->right==NULL){
                delete root;
		return NULL;
	    }	// ONLY ONE CHILD EXIST A
            if(root->right==nullptr){
                TreeNode* temp =  root->left;
		delete root;
		return temp;
            }  // ONLY ONE CHILD EXIST B
	    else if(root->left==nullptr){
                TreeNode* temp =  root->right;
		delete root;
		return temp;
            } // BOTH CHILD EXIST
	    else{
		// replace the root value by find the minimum val from right side 
		// or change accordingly for max from left side.

	        // After replacing the root value we will delete the 
		// inorder successor or predecessor recusrively.
                root->val=findminfromright(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
   
};
};



// DELETE THE NODE SAME SAME JUST for INORDER PREDECESSOR
class Solution {
public:
    int findmaxfromleft(TreeNode* root){
        while(root->right!=nullptr)
            root=root->right;
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==nullptr) return root;
        else if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
		// LEAF NODE
            if(root->left==NULL and root->right==NULL){
                delete root;
		return NULL;
	    }	// ONLY ONE CHILD EXIST A
            if(root->right==nullptr){
                TreeNode* temp =  root->left;
		delete root;
		return temp;
            }  // ONLY ONE CHILD EXIST B
	    else if(root->left==nullptr){
                TreeNode* temp =  root->right;
		delete root;
		return temp;
            } // BOTH CHILD EXIST
	    else{
		// replace the root value by find the minimum val from right side 
                root->val=findmaxfromleft(root->left);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};

