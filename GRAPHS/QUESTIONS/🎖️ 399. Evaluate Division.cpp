// https://www.youtube.com/watch?v=P9cPgMp6Wc8
// https://leetcode.com/problems/evaluate-division/


class Solution {
public:
    
map<string,vector<pair<string,double>>> m;
    
void dfs(string s,string d,set<string> v, double &ans, double tmp)
{
    if(v.find(s)!=v.end()) return;
    else
    {
        v.insert(s);
        if(s==d)
        {
            ans=tmp;
            return;
        }
        else
        {   // nbr of  s
            for(auto a:m[s])
            {
                // int temp1=tmp;
                // tmp=tmp*a.second;
                dfs(a.first,d,v,ans,tmp*a.second);
                //tmp=temp1;
            }
        }
            
            
    }
}
    
    
vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
      
    m.clear();
    
    // we see these string a,b,c as nodes
    // and relation a/b as edge a-->b
    // and edge wgt = ans of a/b
    // now i have to find path a to c
    // if there is path exist ans is multiply of all edge wgt on path
    for(int i=0;i<e.size(); i++)
    { // map[a]={b,a/b};
        m[e[i][0]].push_back({e[i][1],v[i]});
        m[e[i][1]].push_back({e[i][0],1/v[i]}); // for reciporcal
    }
    
    vector<double> res;
    for(int i=0;i<q.size();i++)
    {
        string s=q[i][0];
        string d=q[i][1];
        
        set<string> visited;
        
        double ans=-1.0;
        // DFS to find path
        if(m.find(s)!=m.end())
        dfs(s,d,visited,ans,1.0);
        res.push_back(ans);
    }
    return res;
    
    
    }
};
