A bipartite graph is a graph in which the vertices can be divided into two disjoint sets, 
    such that no two vertices within the same set are adjacent. In other words, 
it is a graph in which every edge connects a vertex of one set to a vertex of the other set.


No odd-length cycles: A bipartite graph cannot contain any odd-length cycles, as this would require vertices from the same set to be connected by an edge.


EVEN len cycle may or maynot be bipartite.


#include <bits/stdc++.h>
using namespace std;

bool dfs_helper( vector<int> graph[], int node, int *visited,int parent, int color)
{
    // come to a node visited
    visited[node]=color; //1 or 2 
    for(auto nbr:graph[node])
    {
        if(visited[nbr]==0)
        {
            int subprob =dfs_helper(graph,nbr,visited,node,3-color);
            if(subprob==false)
            return false;
        }
        else if(nbr!=parent and color==visited[nbr])
        {
              return false;
        }
    }
    return true;
}

bool dfs(vector<int> graph[], int N)
{
  // visited array color array
  int visited[N] ={0};
  // 0 - not visited 1-visited clr 1, 2-visited clr2
  int color=1;

   
    for(int i=0;i<N;i++)
    {
        if(visited[i]==0)
        {
            if(dfs_helper(graph,i,visited,-1,color)==false)
              return false;
        }
    }
        
   
    
    
    
    
     for( int i=0;i<N;i++)
     {
         cout<<i<<"- Color " <<visited[i]<<endl;
     }
      return true;

}

int main() {
    int N,M;
    cin>>N>>M;
    vector<int> graph[N];

    while(M--)
{
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
    // BFS or DFS by coloring nodes at each step (if current is clr 1 nbr must be clr2)



}
if(dfs(graph,N))
{
    cout<<"bipartite"<<endl;
}
else
cout<<"NO"<<endl;
}

