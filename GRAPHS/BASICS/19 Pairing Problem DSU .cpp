// question 
// https://discuss.codingblocks.com/t/pairing-problem-graph/24651
// journy to moon using DSU 
// conected component using DSU rank will show that

#include <bits/stdc++.h>
using namespace std;

int pairing()
{
    // init DSU logic
    int *parent = new int[V];
    int *rank = new int[V];

    for( int i=0; i<V; i++ )
    {
        parent[i]=-1;
        rank[i]=1;
    }

    //CODE LOGIC
    int ans=0;
    for( auto edge: l)
    {
        int i=edge.first;
        int j=edge.second;

        int s1=findSet(i, parent);
        int s2= findSet(j,parent);

        union_set(s1,s2,parent,rank);



    }
    // go to all the nodes
    int ans=0;
    for( int i=0; i<V; i++)
    {   // here the curr node can pair up with all that are not part of its set
     // thats why total - rank of parent of node 
        ans+=V-rank(findSet(i,parent));
    }
    delete [ ] parent;
    delete [ ] rank;
    return ans/2;

}

int main() {
    int n,m;
    cin>>n>>,=m;
    Graph g(n);

    while(m--)
    {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
}

