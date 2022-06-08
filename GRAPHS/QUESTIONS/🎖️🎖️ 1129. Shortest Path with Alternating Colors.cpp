// https://leetcode.com/problems/shortest-path-with-alternating-colors/
// undirected mae BFS 

// using 2 separate visited arrays and Graphs for red and blue, And proceeding in alternative way.



class Solution {
public:
   
   #define vi vector<int>
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
       
        vector<vector <int>> graphred(n);
        vector<vector <int>> graphblue(n);
       
        for(auto x:red_edges){
            graphred[x[0]].push_back(x[1]); 
        }
        for(auto x:blue_edges){
            graphblue[x[0]].push_back(x[1]); 
        }
       
        vector <int> distance(n,-1); 
       
        queue <vi> bfs ;
        vector <int> visitedred(n,0);
        vector <int> visitedblue(n,0);
       
        //1 is red, -1 is blue 
        bfs.push({0,0,1});  // src, dist, red OR blue
        bfs.push({0,0,-1});
        distance[0] = 0 ;
       
        visitedred[0] = 1;
        visitedblue[0] = 1;
       
        while(!bfs.empty()){
            vi temp = bfs.front(); 
            bfs.pop();  
            if(temp[2] == 1) {
                for(auto x:graphblue[temp[0]]){
                    if(!visitedblue[x]){
                        visitedblue[x] = 1; 
                        if(distance[x] == -1) distance[x] = 1+temp[1]; // AS BFS so first contact is our shortest ans
                        bfs.push({x,1+ temp[1], -1});    
                    }
                    
                }
            }
            if(temp[2] == -1) {
                for(auto x:graphred[temp[0]]){
                    if(!visitedred[x]){
                        visitedred[x] = 1;
                        if(distance[x] == -1) distance[x] = 1+temp[1]; 
                        bfs.push({x,1+ temp[1], 1});
                    }
                }
            }
        }
        return distance; 
    }
};
