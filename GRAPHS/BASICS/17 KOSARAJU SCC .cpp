#include <bits/stdc++.h>
using namespace std;

void dfs( vector<int> graph[], int  i,  bool *visited, vector<int> &stack)
{
  visited[i]=true;

  for( auto nbr:graph[i])
  {
      if(!visited[nbr])
      {
          dfs(graph,nbr, visited, stack);
      }
  }
  //function call is complete
  stack.push_back(i);

}


void dfs2( vector<int> graph[], int i ,bool *visited)
{
  visited[i]=true;
  cout<<i<<" ";

  for( auto nbr:graph[i])
  {
      if(!visited[nbr])
      {
          dfs2(graph,nbr, visited);
      }
  }


}

void solve(vector<int> graph[], vector<int> rev_graph[],int N)
{
 bool visited[N];
 memset(visited,0,N);
 vector<int> stack;

 // step 1 need to store vertices acc to the dfs finish time
 for( int i=0; i<N; i++)
 {
     if( !visited[i])
     {
         dfs(graph,i,visited,stack);
     }
 }
 //ordering =stack
 //step 2 rev graph
 //step 3 dfs acc to ordering in stack

 memset(visited,0,N);
 char component_name='A';
 for( int x=stack.size()-1;x>=0;x--)
 {
     int node=stack[x];
     if(!visited[node])
     {   cout<<"COMPONENT "<<component_name<<"--> ";
         // the component starting from this node
         dfs2(rev_graph,node,visited);
         cout<<endl;
         component_name++;
     }


 }


}

int main() {

    int N;
    cin>>N;

    vector<int> graph[N];
    vector<int> rev_graph[N];

    int m;
    cin>>m;
    while(m--)
    { int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    rev_graph[y].push_back(x);

    }
    solve(graph,rev_graph,N);



}

