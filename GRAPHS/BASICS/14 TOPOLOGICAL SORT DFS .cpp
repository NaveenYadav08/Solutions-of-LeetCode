TOPOLOGICAL SORTING is there in DAG ( directed acacliyc graph ) 
and it means the linear ordering of vertices such that if there is edge between U and V then U appear before V in that ordereing.

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> l;
    public:
    void addEdge(string x,string y)
    {
        l[x].push_back(y);
        // l[y].push_back(x);
    }

    void dfs_helper(T src,map<T,bool> &visited,  list<T> &ordering)
    {
     // it teaverse the graph
     //cout<<src<<" "<<endl;
     visited[src]=true;
     for(auto x:l[src])
     {
         if(!visited[x])
         {
             dfs_helper(x,visited,ordering); 
         }
     }
     ordering.push_front(src);
     return;
    }

    void dfs()
    {
     
     map<T,bool> visited;
     list<T> ordering;

     for(auto x:l)
     {
         T node=x.first;
         visited[node]=false;
     }

     for(auto p:l)
     {  T node=p.first;
            if(!visited[node])
            {
         dfs_helper(node,visited,ordering);
            }
     }


     //finally  print list
     for(auto node:ordering)
     cout<<node<<endl;

     
    }
};

int main() {
    Graph<string> g;
    g.addEdge("python","DataPreprocessing");
     g.addEdge("python","pyTorch");
      g.addEdge("python","ML");
        g.addEdge("DataPreprocessing","ML");
         g.addEdge("pyTorch","DL");
          g.addEdge("ML","DL");
           g.addEdge("DL","faceRecogn");
            g.addEdge("Dataset","faceRecogn");
         
    
    g.dfs();
}
