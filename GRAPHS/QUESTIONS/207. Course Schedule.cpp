https://leetcode.com/problems/course-schedule/








class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector <int> adj[numCourses];
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        int count = 0;
        queue <int> q;
        vector <int> indegree(numCourses, 0);
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            indegree[prerequisites[i][0]]++;
        }
        
        for(int i = 0; i < indegree.size(); i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            count++;
            
            for(auto v: adj[temp])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                {
                    q.push(v);
                }
            }
            
        }
        
        if(count == numCourses)
            return true;
        return false;
        
    }
};
