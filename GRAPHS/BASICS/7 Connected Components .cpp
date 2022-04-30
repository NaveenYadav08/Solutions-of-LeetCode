#include <bits/stdc++.h>
using namespace std;

//DFS

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


    void dfs()
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
        

        // iterate over all nodes to check vis or not
        for(auto p:l)
        {
            T node = p.first;
            int cnt=0;
            if(!visited[node])
           {  cout<<"component  "<<cnt<<"  -- >  ";
               dfs_helper(node,visited);
               cnt++;
               cout<<endl;
           
           }
           
        }
        
    }



};


int main() {
    // cout<<"Hello World!";
    Graph<int> g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(0,3);
    g.addedge(0,4);


    g.addedge(5,6);
    g.addedge(6,7);

    g.addedge(8,8);
   
    g.dfs();
    return 0;
}
