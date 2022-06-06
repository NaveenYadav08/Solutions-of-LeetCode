#include <bits/stdc++.h>
using namespace std;

#define INF 100000

vector<vector<int> > floyd_warshall(  vector<vector<int> > graph)
{
  vector<vector<int> > dist(graph);
  auto V= graph.size();
  //Phases , in kt phase we included vertices ( 1,2,---k) as intermediate vertex
  for(int k=0; k<V;k++)
  {
      //iterate over 2D matrix
      for( int i=0; i<V; i++ )
      {
          for(int j=0; j<V; j++)
          {
              //if vertex k is included and can we minimise the dist ?
              if(dist[i][j] > dist[i][k] + dist[k][j])
              dist[i][j] = dist[i][k] + dist[k][j];

          }
      }

  }
 return dist;

}

int main() {
  
  // THIS INF IS IMPORTANT TO SHOW NO PATH IS THERE AND IT BE USE IN OUR ALGO 
    vector<vector<int> > graph={
        {0,INF,-2,INF},
        {4,0,3,INF},
        {INF,INF,0,2},
        {INF,-1,INF,0}
    };
    auto result = floyd_warshall(graph);
    for( int i=0; i<result.size(); i++)
    {
        for( int j=0; j<result.size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
