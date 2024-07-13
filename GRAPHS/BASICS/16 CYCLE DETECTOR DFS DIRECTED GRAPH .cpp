// THE Code for undirected graph not work in case of 
A->B
|  | 
V  V
C->D
// where we can reach a node by 2 ways
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    list<int> *l;
    int V;
    public:
    Graph(int V)
    {
        this->V=V;
        l=new list<int>[V];
    }

void addEdge(int x, int y, bool directed = true)
{
    l[x].push_back(y); 
    if(!directed)
    {
        l[y].push_back(x);
    }
}

bool cycle_helper( int node, bool *visited, bool *arrayy)
{
    visited[node]=true;
    arrayy[node]=true;
    for(auto nbr:l[node])
    {
        //two cases
        if(!visited[nbr])
        { // go and recursively visit neighbour
         bool cycle_mila = cycle_helper(nbr,visited,arrayy);
         if(cycle_mila)
         { return true;

         }
           

        }
        // nbr visit and part of current path backedge , means that the node is visited and part of curr path 
        // for those who are vis but not part of curr path are not cycle 
        else if(arrayy[nbr]==true)
        {
           return true;
        }
    }
    // leave a node 
    arrayy[node]=false;
   return false;
}

bool contains_cycle()
{  // CHeck for cycle in Directed Graph
     bool *visited =new bool[V];
     bool *arrayy = new bool[V];
     for( int i=0; i<V; i++ )
     {
         visited[i]=false;
         arrayy[i]=false;

     }
    
    for(int i=0;i<V;i++)
     {
        if(!visited[i])
        if(cycle_helper(i,visited,arrayy) return true;
     }
     return false;

}

};

int main() {
    Graph g(7);
    g.addEdge(0,1);
     g.addEdge(1,2);
      g.addEdge(2,3);
       g.addEdge(3,4);
        g.addEdge(4,5);
         g.addEdge(1,5);
          g.addEdge(5,6);
           g.addEdge(4,2); // Backedge


        if(g.contains_cycle())
        {
           cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;

}
