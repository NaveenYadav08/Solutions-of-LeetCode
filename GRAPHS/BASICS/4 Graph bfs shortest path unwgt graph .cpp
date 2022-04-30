/// BFS to fnd single source shortest path to all other nodes in unwgt graph

#include <bits/stdc++.h>
using namespace std;

//BFS shortest path ( single source shortest path to all nodes in unwgt graph )

// class Graph
// GENERIC GRAPH
template<typename T>

class Graph{
    //int V;
map<T,list<T>> l;

    public:

    void addedge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);

    }

    void bfs(T src)
    {
        // queue and vis array
        map<T,int> dist;
        queue<T> q;
       
       
        
        // all other node have distance infinite
        for(auto x:l)
        {
            T node = x.first;
            dist[node]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;


        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            
       
            //cout<< node<<"  ";
            for(int nbr:l[node])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr]=dist[node]+1;
                }
            }
            

        }

        // print dist
        for(auto node_pair: l)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout<< "NODE  "<<node<< " Dist from src  "<<d <<endl;
        }
         
    }



};


int main() {
    // cout<<"Hello World!";
    Graph<int> g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,0);
    g.addedge(3,4);
    g.addedge(4,5);
    g.bfs(0);
    return 0;
}
