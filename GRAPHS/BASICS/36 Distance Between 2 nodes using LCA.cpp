// if you move x to y 
// find length of path from x to y , weighted TREE

// APpproach is I go from x to LCA( x,y ) and then LCA( x,y ) to y
// DistaNCE OF X TO lca =  ( distance root to x ) - ( distance root to lca )
// ( distance root to x ) can be done by LCA
// final formaula =  ( distance root to x ) + ( distance root to y ) - 2 * ( distance root to lca )

#include <bits/stdc++.h>
using namespace std;
// binary lifting
// dist from x to y

#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N=100005, M=22;


vector<pair<int,int>> gr[N];
int Par[N][M],dep[N];
int tin[N], tout[N],timer,dis[N];

void dfs(int cur, int par)
{  tin[cur] = ++timer;

     
     for(auto x:gr[cur])
     {
         if(x.F!=par)
         {   dep[x.F]=dep[cur]+1;
             dis[x.F]=dis[cur]+x.S;
             dfs(x.F,cur);
         }
     }
     tout[cur] = timer;
     return ;
}

void cal_sparse_table(int cur, int par)
{
   Par[cur][0]=par;
   for(int j=1;j<M; j++)
   Par[cur][j]=Par[Par[cur][j-1]][j-1];

   for(auto x:gr[cur])
   {
       if(x.F!=par)
       {
           cal_sparse_table(x.F,cur);
       }
   }
} 

// o( log N) == O ( M )
int LCA_depth(int u,int v)
{     if(u==v) return u;
    if(dep[u]<dep[v]) swap(u,v);
    // dep[u]>dep[v]
    int diff = dep[u]-dep[v];
    for(int i=M-1; i>=0; i--)
    {
        if((diff>>i) & 1)
        {
            u=Par[u][i];

        }
    }
    // after it u,v same level ya depth
    // if v was ancestor of u
    if(u==v)
    return u;

        for(int i=M-1; i>=0; i--)
    {
        if(Par[u][i]!= Par[v][i])
        {
            u=Par[u][i];
            v=Par[v][i];

        }
    }
    // diff nodes
    return Par[u][0]; 


}


bool is_ancestor(int u, int v)
{ // is u ancestor of v or not
return   tin[u]<=tin[v] and tout[u] >= tout[v];

}

int LCA_time(int u, int v)
{
    if( is_ancestor(u,v))
    return u;
        if( is_ancestor(v,u))
    return v;


    for(int i=M-1; i>=0; i--)
    { //Par[u][i] is not ancestor of v then move to it
    if(!is_ancestor(Par[u][i],v))
        u=Par[u][i];
        
    }
    return Par[u][0];
}


int distance(int x, int y)
{ 
    //O(M)
    int lca=LCA_depth(x,y);
    return dis[x]+dis[y] -2*dis[lca];

}

void solve()
{
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n;
    for(i=1; i<n; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        gr[x].pb({y,w});
        gr[y].pb({x,w});
    }
    //root 1
    timer =0;
    tin[0]=0; tout[0]=n+1; //universal parent

    dfs(1,0);
    cal_sparse_table(1,0);
    cout<<distance(4,6)<<endl;
    

}


int main() {
    solve();

}
