https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

2 WAYS 

█▄▄ █▀▀ █▀
█▄█ █▀░ ▄█

void printVerticalOrder(Node* root)
{
    // Base case
    if (!root)
        return;
 
    // Create a map and store vertical order in
    // map using function getVerticalOrder()
    map<int, vector<int> > m;
    int hd = 0;
 
    // Create queue to do level order traversal.
    // Every item of queue contains node and
    // horizontal distance.
    queue<pair<Node*, int> > que;
    que.push(make_pair(root, hd));
 
    while (!que.empty()) {
        // pop from queue front
        pair<Node*, int> temp = que.front();
        que.pop();
        hd = temp.second;
        Node* node = temp.first;
 
        // insert this node's data in vector of hash
        m[hd].push_back(node->key);
 
        if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }
 
    // Traverse the map and print nodes at
    // every horizontal distance (hd)
    for (auto it:m) {
        for (int i = 0; i < it.second.size(); ++i)
            cout << it.second[i] << " ";
        cout << endl;
    }
}



█▀▄ █▀▀ █▀
█▄▀ █▀░ ▄█

void preOrderTraversal(Node* root, long long int hd, long long int vd, map<long long int, vector<int> >& m)
{
    if (!root)
        return;
    // key = horizontal
    // distance (30 bits) + vertical
    // distance (30 bits) map
    // will store key in sorted
    // order. Thus nodes having same
    // horizontal distance
    // will sort according to
    // vertical distance.
    long long val = hd << 30 | vd;
 
    // insert in map
    m[val].push_back(root->data);
 
    preOrderTraversal(root->left, hd - 1, vd + 1, m);
    preOrderTraversal(root->right, hd + 1, vd + 1, m);
}
 
void verticalOrder(Node* root)
{
    // map to store all nodes in vertical order.
    // keys will be horizontal + vertical distance.
    map<long long int, vector<int> > mp;
 
    preOrderTraversal(root, 0, 1, mp);
 
    // print map
    int prekey = INT_MAX;
    map<long long int, vector<int> >::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (prekey != INT_MAX
            && (it->first >> 30) != prekey) {
            cout << endl;
        }
        prekey = it->first >> 30;
        for (int j = 0; j < it->second.size(); j++)
            cout << it->second[j] << " ";
    }
}
