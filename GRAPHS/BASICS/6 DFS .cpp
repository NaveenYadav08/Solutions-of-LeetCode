#include <bits/stdc++.h>
using namespace std;

//DFS = O ( V + E )  SC = O ( V )

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


    void dfs_helper(T src, map<T,bool> &visited)
    {
      // recursive funtion dfs that will traaverse graph

      cout<<src<<" ";
      visited[src]=true;
      // go to all nbr that are not visited recursively 
      for(T nbr : l[src])
      {
          if(!visited[nbr])
          {
              dfs_helper(nbr,visited);
          }
      }
    }


    void dfs(T src)
    {
        // queue and vis array
        map<T,bool> visited;
        // mark all not vis
        // queue<T> q;
       
       
        
        // all other node have distance infinite
        for(auto x:l)
        {
            T node = x.first;
            visited[node]=false;
        }
        
        dfs_helper(src,visited);
         
    }



};


int main() {
    // cout<<"Hello World!";
    Graph<int> g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(4,5);
    g.addedge(3,0);
    g.dfs(0);
    return 0;
}
