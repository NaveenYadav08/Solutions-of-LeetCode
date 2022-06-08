
https://leetcode.com/problems/reconstruct-itinerary/





// PLanned route bnana hae bas  route return kro isko jismae wo saare path ho jo idr given hae
// in lexical order means COVER All Tickets
// ANS is possible for every ans so 
// no edge case like multi component 
// I can travel an edge only once 
class Solution {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>>hm;
    
    void dfs(string v, vector<string>& res) {
        
        while (hm[v].size() != 0) {
            string p = hm[v].top();
            hm[v].pop();
            dfs(p, res);
        }
        
        res.push_back(v);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for (int i = 0; i < tickets.size(); i++) {
            hm[tickets[i][0]].push(tickets[i][1]);
        }
        
        vector<string>res;
        dfs("JFK", res);
        reverse(res.begin(), res.end());
        
        return res;
    }
};
