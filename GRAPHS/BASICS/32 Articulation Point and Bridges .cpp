#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N=100005, M=22;

vector<int> gr[N]; //graph
int disc[N], low[N],tme;
set<int> art_p;
vector<pair<int,int>> bridge;

void dfs(int cur, int par)
{
  disc[cur]=low[cur]=tme++;
  // low  is dp
  int no_child=0;
  for( auto child: gr[cur])
  {
      //not visited
      if(disc[child]==0)
      {dfs(child,cur);
      no_child++;
      low[cur]=min(low[cur],low[child]);
      // articulation point
      if(par!=0 and low[child]>=disc[cur])
      { 
          art_p.insert(cur);
      }
      //bridge
       if(low[child]>disc[cur])
       {
           bridge.pb(make_pair(cur,child));

       }
      }
      else if(child!=par)
      { //backedge
      //cycle found
      // disc is depth   
      low[cur]=min(low[cur],disc[child]);

      

      }
  } 
  //seprate caase of root
  if(par==0 and no_child >=2)
  {
     art_p.insert(cur);
  }
  return;

}

void solve()
{
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n>>m;
    for( int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    tme=1;
    dfs(1,0);
    for(auto x:art_p)
    cout<<x<<" ";
}


int main() {
    solve();

}
