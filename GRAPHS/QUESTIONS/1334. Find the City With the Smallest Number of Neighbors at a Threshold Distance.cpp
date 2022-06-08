https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // using (Floyd-Warshall) - Dynamic Programming
        // dynamic programming
        
        int dist[n][n];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = (i==j) ? 0 : 10000000;
        

        
        for(auto &v : edges){
            dist[v[0]][v[1]] = v[2];
            dist[v[1]][v[0]] = v[2];
        }
    
        for(int k = 0;k < n;k++)
            for(int i = 0;i < n;i++)
                for(int j = 0;j < n;j++)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        
        int res = -1;
        int min_count = INT_MAX;
        
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++)
                if(dist[i][j] <= distanceThreshold)
                    count++;
            if(count <= min_count){
                min_count = count;
                res = i;
            }
        }
        
        return res;
        
    }
};
