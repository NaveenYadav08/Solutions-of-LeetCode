https://leetcode.com/problems/longest-univalue-path/

▄▀█ █░░ █▀▀ █▀█
█▀█ █▄▄ █▄█ █▄█


The basic approach is we do a post order traversal and on the way back we'll se if out current node is same as its parent node or not.
if "YES" -> then we will return the max of. the univalued path length from the left and the right of the current node

if "NO" -> we'll just return 0; (since the streak will not be continues after this node since it is not same as its parent)

and mean while we'll be updating out answer variable as the max length seen so far.
For that we'll take the sum of the left and right length we have seen.




█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄


class Solution {
public:
//answer variable
int ans = 0;

int longestUnivaluePath(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    solve(root, NULL);
    return ans;
}

    
int solve(TreeNode* root,  TreeNode* parent){

    if(root == NULL){
        return 0;
    }
    
	//calculate the lengths on left and right side of the current node
    int left = 0; 
    int right = 0;
    
        left = solve(root->left, root);
        right = solve(root->right,  root);
    
	//update the ansewer as the sum of the length found on the left side and the right side
    ans = max(ans, left + right);
    
	//if parent exists (node is not root)
	//if the current value matches with the parent value then we return the maxLength betn left and right + 1(current element).
    if(parent){
        if(parent->val == root->val){
            return max(left, right) + 1;
        }
        else{
		//else return 0
            return 0;
        }
    }
    return 0;        
}
};
