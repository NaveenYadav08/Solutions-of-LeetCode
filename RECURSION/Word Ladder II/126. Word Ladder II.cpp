126. Word Ladder II

https://leetcode.com/problems/word-ladder-ii/


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        // Results
        vector<vector<string>> paths; // FINAL ANS
        vector<string> pth; // INDIVIDUAL PATH 

        // if endWord is not in wordList, return empty results directly;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return paths;

        // if beginWord is not in wordList, add it;
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            wordList.push_back(beginWord);
        } 

        // initialize a graph from wordList;
        unordered_map<string, vector<string>> graph;
        for (auto word : wordList) {
            graph.insert(make_pair(word, vector<string>(0)));
        }

// build adjacency list; there is an edge betwee two nodes if the two words differ by just one letter;
        int n = wordList.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string u = wordList[i];
                string v = wordList[j];
                if(isNeighborbyHammingDistance(u, v)) {
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                  //  cout<<u<<" "<<v<<endl;
                }
            }
        }

        // use simple BFS on unweighted graph to find dist[v] == distance from v to start node;
        unordered_map<string, int> dist;
        dist.insert(make_pair(beginWord, 0));
        unordered_set<string> visited;
        bfs(beginWord, graph, dist, visited);

// backtrack from endWord, use `dist` information as conditions to avoid traversing all paths;
        pth.push_back(endWord); //dfs
        dfs(endWord, beginWord, graph, dist, paths, pth);

        // reverse paths;
        int num_paths = paths.size();
        for (int i = 0; i < num_paths; ++i) {
            reverse(paths[i].begin(), paths[i].end());
        }

        return paths;
    }

    bool isNeighborbyHammingDistance(string& u, string& v) {
        int dist = 0;
        int n = u.size();
        for (int i = 0; i < n; ++i) {
            if (u[i] != v[i])
                dist++;
        }
        return dist == 1 ? true : false;
    }

void bfs(string beginWord, unordered_map<string, vector<string>>& graph, unordered_map<string, int>& dist, unordered_set<string>& visited) {
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            for (auto v : graph[u]) {
                if (visited.find(v) == visited.end()) {
                    visited.insert(v);
                    q.push(v);
                    dist.insert(make_pair(v, dist[u] + 1));
                }
            }
        }
    }

void dfs(string u, string beginWord, unordered_map<string, vector<string>>& graph, unordered_map<string, int>& dist,vector<vector<string>>& paths, vector<string>& pth) {
        for (auto v : graph[u]) {
            // LIVE condition
            if (dist[v] == dist[u] - 1) { 
                pth.push_back(v);
                // Terminal condition
                if (v == beginWord) {
                    paths.push_back(pth);
                }
                else
                    dfs(v, beginWord, graph, dist, paths, pth);
                // backtrack from solution;
                pth.pop_back();
            }
        }
    }
};
