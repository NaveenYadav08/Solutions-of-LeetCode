https://www.spoj.com/problems/HOLI/


#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>> *l;

    public:
    Graph(int v)
    {
        V=v;
        l=new list<pair<int,int>> [V];
    }

    void addEdge(int u, int v, int cost)
    {
        l[u].push_back(make_pair(v,cost));
        l[v].push_back(make_pair(u,cost));

    }

    int dfs_helper(int node, bool *visited, int *count, int &ans)
    {
        // int to return node count
        // mark node as visited

        visited[node]=true;
        count[node]=1;

        for(auto nbr_pair:l[node])
        {
            int nbr=nbr_pair.first;
            int wt=nbr_pair.second;
            if(!visited[nbr])
            {
                count[node] += dfs_helper(nbr, visited, count, ans);
                int nx= count[nbr];
                int ny= V-nx;
                ans += 2*min(nx,ny)*wt;
            }
        }
        // just before leaving parent 
        return count[node];


    }

    int dfs( )
    {
        bool *visited =new bool[V];
        int *count = new int[V];

        for( int i=0; i<V;i++)
        {
            visited[i]=false;
            count[i]=0;

        }

        int ans=0;
        dfs_helper(0,visited,count,  ans);
        return ans;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0,1,3);
    g.addEdge(1,2,2);
    g.addEdge(2,3,2);
    cout<< g.dfs()<<endl;
    
}
