https://leetcode.com/problems/redundant-connection/










class Solution {

int parent[1001];
int size[1001];

    
public:
    

    
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    
    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        for (int i = 1; i <= n; ++i) {
                    parent[i] = i;
                    size[i] = 1;
        }
        
        vector<int> ans;
        
        for(vector<int> edge: edges) {
            
            int a = find(edge[0]);
            int b = find(edge[1]);
            
            if (a == b) {
                ans.push_back(edge[0]);
                ans.push_back(edge[1]);
            }
            
            Union(edge[0], edge[1]);
        }
        return ans;
    }
};
