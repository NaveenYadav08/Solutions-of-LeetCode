https://leetcode.com/problems/network-delay-time/










class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> graph[n+1];
        vector<int> distance(n+1, INT_MAX);
        
        //min priority queue
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
        
        for(auto it : times){
            graph[it[0]].push_back(make_pair(it[1], it[2]));
        }
       
        
        distance[k] = 0;
        pq.push(make_pair(0, k));
        
        while(!pq.empty()){
            int current = pq.top().second;
            int dis = pq.top().first;
            
            pq.pop();
            
            for(auto it : graph[current]){
                if(dis + it.second < distance[it.first]){
                    distance[it.first] = dis + it.second;
                    pq.push(make_pair(distance[it.first], it.first));
                }
            }
        }
        
        int output = *max_element(distance.begin() +1 , distance.end());
        return output == INT_MAX ? -1 : output;
        
    }
};
