#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N=100005, M=22;


vector<int> gr[N];
int Par[N],dep[N];

void dfs(int cur, int par)
{
     Par[cur]=par;
     for(auto x:gr[cur])
     {
         if(x!=par)
         {   dep[x]=dep[cur]+1;
             dfs(x,cur);
         }
     }
     return ;
}

//O(n)
int lca_brute( int u, int v)
{ 
    if(u==v) return u;

    // same depth let x be at more depth not then swap
   if(dep[u]<dep[v]) swap(u,v);
   // always dep of x>dep y
   while(dep[u]>dep[v])
   {
       u=Par[u]; 

   }
   //same level
   while(u!=v)
   {
       u=Par[u];
             v=Par[v];
   }


return u;


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
    dfs(1,0);
    cout<<lca_brute(7,9)<<endl;

    // for(i =1; i<=n; i++)
    // {
    //     cout<<i<<" "<<dep[i]<<" "<<Par[i]<<endl;
    // }

}


int main() {
    solve();

}
