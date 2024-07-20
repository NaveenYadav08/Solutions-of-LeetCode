BFS indegree Kahns algorithm
Kahn’s Algorithm for Topological Sorting is a method used to order the vertices of a directed graph in a linear order such that for every 
directed edge from vertex A to vertex B, A comes before B in the order. The algorithm works by repeatedly finding vertices with no incoming 
edges, removing them from the graph, and updating the incoming edges of the remaining vertices. This process continues until all vertices have been ordered.

#include <bits/stdc++.h>
using namespace std;

class Graph{
  list<int> *l;
  int V;

  public:

  
      Graph(int V)
      {
          this->V = V;
          l=new list<int>[V];
      }

      void addEdge( int x, int y)
      {
          // directed graph
          l[x].push_back(y);
      }

      void topological_sort()
      {
          //indegree
          int *indegree = new int[V];
          // 0 indegree
          for( int i=0; i<V;i++)
          indegree[i]=0;

          //update indegree by traversing
          for(int i=0; i<V; i++)
          {
              
              for( auto y:l[i])
              {
                  indegree[y]++;
              }
          }

          //bfs
          queue<int> q;
          //1. Step find nodes with 0 indegree
          for( int i=0;i<V; i++)
          {
              if(indegree[i]==0)
              q.push(i);

          }
          // start to remove elements from queue
          while(!q.empty())
          {
              int node =q.front();
              cout<<node<<" ";
              q.pop();
              // iterate over nbrs of that node and reduce their indegree by 1
              for( auto nbr:l[node] )
              {
                  indegree[nbr]--;
                  if(indegree[nbr]==0)
                  {
                      q.push(nbr);
                  }
              }

          }

      }



  

};

int main() {
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(4,5);

    g.topological_sort();

    
    
}
