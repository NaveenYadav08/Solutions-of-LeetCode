https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

// WORK FOR NON NEGATIVE 
// CAN FIND ALL PATHS ALSO 


    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i:edges){
            int weight = i[2];
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        vector<int> distance(n+1,INT_MAX);
        vector<int> parent(n+1,-1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; // MIN HEAP //
        
        distance[1] = 0;
        parent[1] = 0;
        q.push({0,1});
        
        
        while(!q.empty()){
            int cur = q.top().second;
            int d = q.top().first;
            q.pop();
            
            for(auto k: adj[cur]){
                int neighbour = k.first;
                int weight = k.second;
                
                if(d + weight < distance[neighbour]){
                    distance[neighbour] = d + weight;
                    parent[neighbour] = cur;
                    q.push({distance[neighbour],neighbour});
                }
            }
        }
        
        if(distance[n] == INT_MAX) return {-1};
        
        vector<int> ans;
        int temp = n;
        while(temp != 0){
            ans.push_back(temp);
            temp = parent[temp];
        }
        ans.push_back(distance[n]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
