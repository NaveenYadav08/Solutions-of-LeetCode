LEFT and RIGHT VIEW 

BFS - 
vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=1;i<=n;i++)
            {
               TreeNode* ptr= q.front();
                q.pop();
                  if(i==n) // this will make it Right View
                  if(i==1) // This will make it Left View
                  ans.push_back(ptr->val);
                if(ptr->left!=NULL)q.push(ptr->left);
                if(ptr->right!=NULL)q.push(ptr->right);
            }
        }
        return ans;
    }

DFS - 
    vector<int>ans;
    unordered_map<int,int> mx;
    void helper(TreeNode* root,int h){
        if(root == NULL) return;
        
        cout<<root->val<<" "<<h<<" | ";
         
        if(!mx.count(h))
        {mx[h]=1;ans.push_back(root->val);}
        
        // left than right give me LEFT VIEW
        helper(root->left,h+1);
        helper(root->right,h+1);
       // right than left give me RIGHT VIEW
      helper(root->right,h+1);  
      helper(root->left,h+1);  
    }


TOP and BOTTOM VIEW 
BFS 
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        
        // base case
        if(root == NULL){
            return ans;
        }
    
        Node *temp = NULL;
        //creating empty queue for level order traversal.
        queue<pair<Node *, int>> q;
        //creating a map to store nodes at a particular horizontal distance.
        map<int, int> mp;
    
        q.push({root, 0});
        while(!q.empty())
        {
    
            temp = q.front().first;
            int d = q.front().second;
            q.pop();
            
            //storing temp->data in map.
            if(mp.find(d) == mp.end()){
                mp[d] = temp->data;
            }
                //  IN CASE OF BOTTOM THIS CONDITION WILL NOT COME 
                //  ONLY THIS 
                 // mp[d] = temp->data;
            
            //if left child of temp exists, pushing it in
            //the queue with the horizontal distance.
            if(temp->left){
                q.push({temp->left, d-1});
            }
            //if right child of temp exists, pushing it in
            //the queue with the horizontal distance.
            if(temp->right){
                q.push({temp->right, d+1});
            }
        }
        //traversing the map and storing the nodes in list 
        //at every horizontal distance.
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        //returning the output list.
        return ans;
    }
};



DFS 
void fillMap(Node* root, int d, int l,
             map<int, pair<int, int> >& m)
{
    if (root == NULL)
        return;
 
    if (m.count(d) == 0) {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > l) {
        m[d] = make_pair(root->data, l);
    }
        // IN CASE OF BOTTOM VIEW else if condition change 
        //  else if (m[d].second <= l) {
       
 
    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}

void topView(struct Node* root)
{
 
    // map to store the pair of node value and its level
    // with respect to the vertical distance from root.
    map<int, pair<int, int> > m;
 
    // fillmap(root,vectical_distance_from_root,level_of_node,map)
    fillMap(root, 0, 0, m);
 
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->second.first << " ";
    }
}
