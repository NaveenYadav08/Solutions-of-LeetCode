// min hgt i can reach from curr node if i can travel only one backedge

#include <bits/stdc++.h>
using namespace std;

const int N=100;

vector<int> gr[N];
int dp[N],vis[N];
int depth[N];

void dfs(int cur, int par, int dep)
{
    
    vis[cur]=1;
    dp[cur]=dep; 
    depth[cur]= dep;

for( auto x: gr[cur] )
{
    if(vis[x]==0)
    {
        dfs(x,cur,dep+1); 
        dp[cur]= min(dp[cur],dp[x]);
        
    }
    else if(x!=par)
    { 
        // backedge
        dp[cur]=min(dp[cur],depth[x]); 


    }
}
    return;
}

int main() {
    int n,m;
    cin>>n>>m;
    for( int i=1; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);

    }

    dfs(1,0,0); // curr parent depth 

    for( int i=1; i<=n; i++)
    cout<<i<<" "<<dp[i]<<endl;
}
