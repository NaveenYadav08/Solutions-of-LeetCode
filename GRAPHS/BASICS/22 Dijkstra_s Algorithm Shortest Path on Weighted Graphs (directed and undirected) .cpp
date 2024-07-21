TC = E Log ( V )


///////////////////// using set //////////////////////////////////

 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>>st;
        vector<int>dist(V, INT_MAX);
        dist[S]=0;
        st.insert(make_pair(0,S));
        
        while(!st.empty()){
            auto top= *(st.begin());
            int distNode=top.first;
            int topNode= top.second;
            
            st.erase(top);
            
            //traversing top neighbours
            
            for(auto neighbour: adj[topNode]){
                if(distNode+neighbour[1] < dist[neighbour[0]]){
                    auto record=  st.find(make_pair(dist[neighbour[0]], neighbour[0]));
                    
                    if(record!=st.end()){
                        st.erase(record);
                    }
                    
                    //distance update
                    dist[neighbour[0]]=distNode+neighbour[1];
                    
                    //record push into set
                    st.insert(make_pair(dist[neighbour[0]],neighbour[0]));
                }
            }
        }
        return dist;
    }




//////////////////////////////// ⭐⭐⭐ general ⭐⭐⭐  /////////////////////
#include<bits/stdc++.h>
using namespace std;

template<typename T> 
class Graph{
unordered_map<T,list<pair<T,int>> >m;

public:
void addEdge(T u, T v, int dist, bool bidir=true)
{
    m[u].push_back(make_pair(v,dist));
    if(bidir)
    {
        m[v].push_back(make_pair(u,dist));
    }
}

void printAdj()
{
    for(auto j:m)
    {
        cout<<j.first<<"->";
        // Iterate over list of cities
        for(auto l:j.second)
        {
            cout<<"("<<l.first<<","<<l.second<<")";
        }
        cout<<endl;
    }
}

void dijsktraSSSP(T src)
{
  unordered_map<T,int>dist;
  // set all dist to infinty
  for(auto j:m)
  {
      dist[j.first]=INT_MAX;

  }

  // mmake a set to find out node with min distance
  set<pair<int,T>> s;
  dist[src]=0;
  s.insert(make_pair(0,src));

  while(!s.empty())
  {
      // least dist
      auto p = *(s.begin());
      T node = p.second;
      int nodeDist=p.first;
      s.erase(s.begin());

      // iterate to all pdosi of top 
      for(auto childpair:m[node])
      {  if((nodeDist+childpair.second)<dist[childpair.first])
      {// in the set update is not pssble we have to remove and reinsert 
          T dest = childpair.first; 
          auto f = s.find(make_pair(dist[dest],dest));
          if(f!=s.end())
          {
              s.erase(f);
          }
          // insert new pair
          dist[dest]=nodeDist+childpair.second;
          s.insert(make_pair(dist[dest],dest));
      }
  }
  }

  for(auto d:dist)
  {
      cout<<d.first<<" is located at distance of "<<d.second<<endl;
  }
  // We can make a parent map to print the path also
}

};

int main()
{
    // Graph<int> g;
    // g.addEdge(1,2,1);
    // g.addEdge(1,3,4);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,2);
    // g.addEdge(1,4,7);
    // g.printAdj();
    // g.dijsktraSSSP(1);

    Graph<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);
    //india.printAdj();
    india.dijsktraSSSP("Amritsar");

}



⭐⭐⭐⭐⭐⭐ WAY 02 using priority queue ⭐⭐⭐⭐⭐⭐
                using set is better that pq because set can erase the value if we find better 
                but not in pq

class Solution
{
    public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       vector<int> dis(V,1e9);
       dis[S]=0;
       pq.push({0,S});
       while(!pq.empty()){
           int diss=pq.top().first;
           int node=pq.top().second;
           pq.pop();
           for(auto it:adj[node]){
               int edgeweight=it[1];
               int adjnode=it[0];
               if(diss+edgeweight<dis[adjnode]){
                   dis[adjnode]=diss+edgeweight;
                   pq.push({dis[adjnode],adjnode});
               }
           }
       }
       return dis;
    }
};
