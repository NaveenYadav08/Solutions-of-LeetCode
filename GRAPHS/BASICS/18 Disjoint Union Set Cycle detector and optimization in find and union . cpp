#include <bits/stdc++.h>
using namespace std;

class Graph{
 int V;
 list<pair<int,int>> l;
 public:
 Graph(int V)
 {
     this->V=V;
 }

 void addegde( int u, int v )
 {
     l.push_back(make_pair(u,v));
 }

 //FIND
  int findSet(int i, int parent[])
  { 
       //base case
      if(parent[i]==-1)
      return i;
      return findSet(parent[i], parent);
  }

   //FIND BY PATH COMPRESSION
  int findSet_PC(int i, int parent[])
  { 
       //base case
      if(parent[i]==-1)
      return i;
      return parent[i] = findSet_PC(parent[i], parent);
  }

 //UNION
 void union_set(int x, int y, int parent[])
 {
     int s1=findSet(x,parent);
     int s2=findSet(y,parent);

     if(s1!=s2)
     {
         parent[s1]=s2;
     }
      
 }

//UNION BY RANK
 void union_set_UBR(int x, int y, int parent[], int rank[])
 {
     int s1=findSet(x,parent);
     int s2=findSet(y,parent);

     if(s1!=s2)
     {   
          if(rank[s1]<rank[s2])
         {parent[s1]=s2;
         rank[s2]+=  rank[s1];
         }
        else
         {parent[s2]=s1;
         rank[s1]+=rank[s2];
         
         }

     }
      
 }



bool contains_cycle_UBR()
{
    //DSU logic for cycle or not
    int *parent =new int [V+1];
    int *rank = new int[V+1];

    for( int i=0; i<V; i++)
    {
        parent[i]=-1;
        rank[i]=1;
    }

    //iterative over edge list
    for( auto edge :l )
    {
        int i=edge.first;
        int j=edge.second;

        int s1 =findSet(i,parent);
        int s2=findSet(j,parent);
           if(s1!=s2)
    {
        union_set_UBR(s1,s2,parent,rank);
    }
    else
   { cout<<"Same Parents "<<s1<<" and "<<s2<<endl;
          return true;
   }

    }

 

delete[] parent;

return false;

}

bool contains_cycle()
{
    //DSU logic for cycle or not
    int *parent =new int [V+1];
    for( int i=0; i<V; i++)
    {
        parent[i]=-1;
    }

    //iterative over edge list
    for( auto edge :l )
    {
        int i=edge.first;
        int j=edge.second;

        int s1 =findSet(i,parent);
        int s2=findSet(j,parent);
           if(s1!=s2)
    {
        union_set(s1,s2,parent);
    }
    else
   { cout<<"Same Parents "<<s1<<" and "<<s2<<endl;
          return true;
   }

    }

 

delete[] parent;

return false;

}


};

int main() {
Graph g(4);
g.addegde(0,1);
g.addegde(1,2);
g.addegde(2,3);
//g.addegde(3,0);

cout<<g.contains_cycle();

    
}
 
