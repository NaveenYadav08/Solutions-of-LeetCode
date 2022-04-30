#include <bits/stdc++.h>
using namespace std;


// https://www.geeksforgeeks.org/shortest-cycle-in-an-undirected-unweighted-graph/

// Approach: For every vertex, we check if it is possible to get the shortest cycle involving this vertex. For every vertex first, push current vertex into the queue and then it’s neighbours and if the vertex which is already visited comes again then the cycle is present. 
// Apply the above process for every vertex and get the length of the shortest cycle.



#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N =100005 , M=22;

vector<int> gr[N];


void bfs(int src, int n, int& ans)
{   // hr ek node se bfs krunga 
    vector<int> dis(n+1,INT_MAX); 
    queue<int> Q;
    Q.push(src);
    dis[src]=0;
    while( !Q.empty() )
    {
        int cur = Q.front();
        Q.pop();
        for( auto neigh:gr[cur])
        {
            if(dis[neigh]==INT_MAX)
            {
                // neighbour not visited
                dis[neigh]=dis[cur]+1;
                Q.push(neigh);

            }
            // vis
            else if(dis[neigh]>=dis[cur])
            {        
                     //backedge is encountered
                    ans =min(ans,dis[neigh]+dis[cur]+1);
            }
        }
    }

}

void solve()
{
    int i,j,n,m,ans;
    cin>>n>>m;
    for( i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    ans = n+1;
 
    for( i=1;i<=n; i++)
    {
        bfs(i,n,ans);
    }
    if( ans==n+1)
    cout<<"NO cycle"<<endl;
    else
    {
        cout<<"shortest cycle is of length "<<ans<<endl;
    }
}

void init()
{

}


int main() {
    solve();
}
