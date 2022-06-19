https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/

https://www.youtube.com/watch?v=-o4cZskb9Tc&t=621s

class Solution {
        public:
        int reachableNodes(vector<vector<int>> edges, int maxMoves, int n) {
            
            
        vector<vector<int>> graph(n,vector<int>(n,-1));
        for (vector<int> edge: edges) {
            // source -> end = Distance / Intermediatory nodes
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
            
             
        int ans  = 0;
        vector<bool> visited(n);
        // Comparator on the basis of max moves possible
        priority_queue<vector<int>> pq;
        pq.push({maxMoves,0});

        while (!pq.empty()) {
            vector<int> nearestEl = pq.top(); pq.pop();
            int nearestNodeId = nearestEl[1];
            int maxMovesRemaining = nearestEl[0];
            if (visited[nearestNodeId]) {
                continue;
            }
            visited[nearestNodeId] = true;
            // beacuse you are visiting the curr node
            ans++;
            for (int nei = 0; nei < n; nei++) {
                if (graph[nearestNodeId][nei] != -1) {

                     if (!visited[nei] &&   graph[nearestNodeId][nei] + 1 <= maxMovesRemaining) {

                        pq.push({maxMovesRemaining - graph[nearestNodeId][nei] - 1,nei});
                    }

                    int movesCost = min(maxMovesRemaining, graph[nearestNodeId][nei]);

                    graph[nei][nearestNodeId] -= movesCost;
                    graph[nearestNodeId][nei] -= movesCost;
                    ans += movesCost;
                }
            }
        }
        return ans;
    }
};
