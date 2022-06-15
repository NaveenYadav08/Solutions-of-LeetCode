// https://leetcode.com/problems/task-scheduler/
// 

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> un_map;
        for(auto ch : tasks) ++un_map[ch]; // freq
        
        
        priority_queue<int> pq; // max heap
        
        for(auto it : un_map)
            pq.push(it.second); // freq
        
        int res = 0;
        deque<pair<int, int>> dq;  //dequeue  cnt, res+n // kb t use nhi hoga
        
        
        
        while(!pq.empty() || dq.size() > 0){
            ++res;
            if(!pq.empty()){
                int cnt = pq.top() - 1;
                pq.pop();
                if(cnt > 0) dq.push_back(make_pair(cnt, res + n));
            }
            
            if(dq.size() > 0 && dq.front().second == res){
                pq.push(dq.front().first);
                dq.pop_front();
            }
        }
        return res;    
    }
};
