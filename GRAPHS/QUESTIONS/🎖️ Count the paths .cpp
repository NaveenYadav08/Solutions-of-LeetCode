https://practice.geeksforgeeks.org/problems/count-the-paths4332/1


class Solution {
public:
	int count_dfs(vector<vector<int>>graph, int u, int d, vector<bool>&vis){
		if(u == d)
			return 1;
		vis[u] = true;
		int ans = 0;
		for(auto v: graph[u]){
			if(!vis[v])
				ans += count_dfs(graph, v, d, vis);
		}
		vis[u] = false;
		return ans;
	}
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
		vector<vector<int>>graph(n);
		for(auto i: edges)
			graph[i[0]].push_back(i[1]);
		vector<bool>vis(n, false);
		return count_dfs(graph, s, d, vis);
	}
};
