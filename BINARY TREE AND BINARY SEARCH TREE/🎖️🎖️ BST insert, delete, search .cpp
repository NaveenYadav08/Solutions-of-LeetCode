https://leetcode.com/problems/insert-into-a-binary-search-tree/
https://leetcode.com/problems/delete-nodes-and-return-forest/


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄


// C++ program to demonstrate
// delete operation in binary
// search tree
#include <bits/stdc++.h>
using namespace std;

struct node {
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do
// inorder traversal of BST
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->key;
		inorder(root->right);
	}
}

/* A utility function to
insert a new node with given key in
* BST */


█ █▄░█ █▀ █▀▀ █▀█ ▀█▀
█ █░▀█ ▄█ ██▄ █▀▄ ░█░


struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}


█▀ █▀▀ ▄▀█ █▀█ █▀▀ █░█
▄█ ██▄ █▀█ █▀▄ █▄▄ █▀█


// C function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->key == key)
	return root;
	
	// Key is greater than root's key
	if (root->key < key)
	return search(root->right, key);

	// Key is smaller than root's key
	return search(root->left, key);
}



█▀▄ █▀▀ █░░ █▀▀ ▀█▀ █▀▀
█▄▀ ██▄ █▄▄ ██▄ ░█░ ██▄

/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */

struct node* deleteNode(struct node* root, int key)
{
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted is
	// smaller than the root's
	// key, then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is
	// greater than the root's
	// key, then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else {
		// node has no child
		if (root->left==NULL and root->right==NULL)
			return NULL;
	
		// node with only one child or no child
		else if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}



▄▀█ █▀▀ ▀█▀ █░█ ▄▀█ █░░
█▀█ █▄▄ ░█░ █▄█ █▀█ █▄▄


█▀▄ █▀▀ █░░ █▀▀ ▀█▀ █▀▀
█▄▀ ██▄ █▄▄ ██▄ ░█░ ██▄


    // Helper function to delete a node
    TreeNode* helper(TreeNode* root) {
        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;  // Free the memory for the node
            return NULL;  // Simply return NULL to delete the node
        }
        
        // Case 2: Node has only one child
        else if (root->left == NULL) {
            TreeNode* temp = root->right;  // Save the right child
            delete root;  // Free the current node
            return temp;  // Return the right child to bypass the current node
        } 
        else if (root->right == NULL) {
            TreeNode* temp = root->left;  // Save the left child
            delete root;  // Free the current node
            return temp;  // Return the left child to bypass the current node
        }
        
        // Case 3: Node has two children
        else {
            // We can handle this case by:
            // Recurse to find the node to delete, then connect its parent directly to its left or right child
            // We can safely link the left or right child, which will be done during recursion
            TreeNode* leftRightMost = root->left; // inorder predecessor
            while (leftRightMost->right != NULL) {
                leftRightMost = leftRightMost->right;
            }
            // ⭐ make root -> left new root & to handel root right
            // make the inorder predecessor right to point to root right 

            // Connect right child to the rightmost node of the left subtree
            leftRightMost->right = root->right;

            TreeNode* temp = root->left;  // Save the left child, the new subtree to return
            delete root;  // Free the current node
            return temp;  // Return the left child (this effectively "removes" the node)
        }
    }

    // Recursive function to delete a node with the given key
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;  // If the tree is empty, nothing to delete

        // If the key is smaller than the root's value, go left
        if (root->val > key) {
            root->left = deleteNode(root->left, key);  // Recurse on the left subtree
        } 
        // If the key is larger, go right
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);  // Recurse on the right subtree
        }
        // If the key is the same as the root's value, delete this node
        else {
            return helper(root);  // Use the helper function to delete the node
        }

        return root;  // Return the (possibly modified) root
    }




// Driver Code
int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	struct node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	cout << "Inorder traversal of the given tree \n";
	inorder(root);

	cout << "\nDelete 20\n";
	root = deleteNode(root, 20);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 30\n";
	root = deleteNode(root, 30);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 50\n";
	root = deleteNode(root, 50);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	return 0;
}

// This code is contributed by shivanisinghss2110
