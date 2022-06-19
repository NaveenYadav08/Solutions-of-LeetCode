
https://leetcode.com/problems/trapping-rain-water-ii/

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        typedef pair<int, int> cell;
        priority_queue <cell, vector<cell>, greater<cell>> pq; // min priority queue
        int n, m;
        n = heightMap.size();
        m = heightMap[0].size();
        int vis[n][m]; // to keep the status of vistited cells
        memset(vis, 0, sizeof(vis));
		// adding boundary cells to the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    pq.push({heightMap[i][j], i * m + j});
                    vis[i][j] = 1;
                }
            }
        }
        int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int vol = 0; // stores the water volume sum
        int x, y;
        
        while(!pq.empty()) {
            cell front = pq.top();
            pq.pop();
            for(int i = 0; i < 4; i++) {
                x = front.second / m;
                y = front.second % m;
                x += dir[i][0];
                y += dir[i][1];
                if(x < n && x >= 0 && y < m && y >= 0 && vis[x][y] == 0) {
                    vis[x][y] = 1;
                    vol += max(0, front.first-heightMap[x][y]);
                    pq.push({max(front.first, heightMap[x][y]), x * m + y});
                }
            }
        }
        return vol;
    }
};
