#include <bits/stdc++.h>
using namespace std;
// binary lifting

#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N=100005, M=22;


vector<int> gr[N];
int Par[N][M],dep[N];
int tin[N], tout[N],timer;

void dfs(int cur, int par)
{  tin[cur] = ++timer;

     
     for(auto x:gr[cur])
     {
         if(x!=par)
         {   dep[x]=dep[cur]+1;
             dfs(x,cur);
         }
     }
     tout[cur] = timer;
     return ;
}

void cal_sparse_table(int cur, int par)
{
   Par[cur][0]=par;
   for(int j=1;j<M; j++)
   Par[cur][j]=Par[Par[cur][j-1]][j-1]; // recursion relation 

   for(auto x:gr[cur])
   {
       if(x!=par)
       {
           cal_sparse_table(x,cur); // DFS Fashion
       }
   }
} 

// o( log N ) == O ( M )
int LCA_depth(int u,int v)
{     if(u==v) return u;
    if(dep[u]<dep[v]) swap(u,v);
    // dep[u]>dep[v]
    int diff = dep[u]-dep[v];
    for(int i=M-1; i>=0; i--)
    {
        if((diff>>i) & 1)
        {
            u=Par[u][i]; // u ko jump kraya mae 2 ki power ith parent pr

        }
    }
    // after it u,v same level ya depth

    // if v was ancestor of u tb donno same ho jaenge 
    if(u==v)
    return u;

    
    for(int i=M-1; i>=0; i--)
    {  // here  I am jumping till i got same nodes , jump in log steps larger to smaller
        if(Par[u][i]!= Par[v][i])
        {
            u=Par[u][i];
            v=Par[v][i];

        }
    }
    // diff nodes
    return Par[u][0]; 
    // as now u and v are diff but just below that LCA 


}


bool is_ancestor(int u, int v)
{ // is u ancestor of v or notcccccc
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

void solve()
{
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n;
    for(i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    //root 1
    timer =0;
    tin[0]=0; tout[0]=n+1; //universal parent

    dfs(1,0);
    cal_sparse_table(1,0);
    cout<<LCA_depth(9,15);

}


int main() {
    solve();

}
