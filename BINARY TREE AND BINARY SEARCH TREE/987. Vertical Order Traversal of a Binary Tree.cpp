//LEETCODE 
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄

class Solution {
public:
map<int, map<int, vector<int>>> mp;
    void verticalTraversalUtil(TreeNode* root,int horizontalLevel, int verticalLevel){
        if(root == NULL)
            return;
        mp[verticalLevel][horizontalLevel].push_back(root->val);
        verticalTraversalUtil(root->left, horizontalLevel + 1,  verticalLevel - 1);
        verticalTraversalUtil(root->right, horizontalLevel + 1, verticalLevel + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;
        int verticalLevel = 0;
        int horizontalLevel = 0;
        verticalTraversalUtil(root,horizontalLevel, verticalLevel);
        for(auto it = mp.begin(); it != mp.end(); it++){
            vector<int> temp;
            for(auto iq = it->second.begin(); iq != it->second.end(); iq++){
                sort(iq->second.begin(), iq->second.end());
                for(int i = 0; i < iq->second.size(); i++)
                    temp.push_back(iq->second[i]);
            }
            answer.push_back(temp);
        }
        return answer;
    }
};
