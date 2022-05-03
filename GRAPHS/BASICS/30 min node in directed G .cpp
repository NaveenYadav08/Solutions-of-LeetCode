#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> gr[N];
int dp[N];

void dfs(int cur, int par)
{  dp[cur]=cur;
    for(auto x:gr[cur])
    {
        if(x!= par)
        {
            dfs(x,cur);
            // i cant fill than dfs  as x fill on calling dfs first
            dp[cur]=min(dp[cur],dp[x]); // curr ,child
        }
    }
    return;
}

int main()
{
  int n;
  cin>>n;
  for(int i=1; i<n; i++)
  {
      int x,y;
      cin>>x>>y;
      gr[x].push_back(y);
      // not for bidir
      //gr[y].push_back(x);

  }
  // root is 1 
  dfs(1,0);
  // dfs from root 1 or root 1 ka papa 0

  for(int i=1; i<=n; i++)
  {

      cout<<i<<" "<<dp[i]<<endl;
  }

}
