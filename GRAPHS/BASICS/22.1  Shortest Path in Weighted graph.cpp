https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> ans;
        vector<int> parent(n + 1);
        set<pair<int, pair<int, int>>> st;
        st.insert({0, {1, 1}});
        vector<int> vis(n + 1);
        vector<vector<vector<int>>> adj(n + 1);
        for (auto i : edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        int temp = -1;
        while (!st.empty()) {
            int d = st.begin()->first;
            int p = st.begin()->second.first;
            int par = st.begin()->second.second;
            st.erase(st.begin());
            if (vis[p] == 1)
                continue;
            parent[p] = par;
            if (p == n) {
                temp = d;
                break;
            }
            vis[p] = 1;
            for (auto j : adj[p]) {
                st.insert({j[1] + d, {j[0], p}});
            }
        }

        if (temp == -1)
            return {-1};
        int p = n;
        while (p != 1) {
            ans.push_back(p);
            p = parent[p];
        }
        ans.push_back(1);
        ans.push_back(temp);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
