#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005, M = 22;
vector<int> gr[N];
int tin[N], tout[N],timer;

void euler_tour_1(int cur, int par)
{  cout<<cur<<" ";
    for(auto x:gr[cur])
    {
        if(x!= par)
        {
            euler_tour_1(x,cur);
            cout<<cur<<" ";
        }
    }
    return;
}

void euler_tour_2(int cur, int par)
{  cout<<cur<<" ";
    // tin[cur]=timer++;
    for(auto x:gr[cur])
    {
        if(x!= par)
        {
            euler_tour_2(x,cur);
            
        }
    }
   // tout[cur]=timer++;
    cout<<cur<<" ";
    return;
}


void euler_tour_3(int cur, int par)
{  cout<<cur<<" ";
   tin[cur]= ++timer;

    for(auto x:gr[cur])
    {
        if(x!= par)
        {
            euler_tour_3(x,cur);
            
        }
    }
     tout[cur]=timer;
    return;
}


//wheter x ancestor o not
bool is_ancestor(int x, int y)
{
    return tin[x]<=tin[y] and tout[x]>=tout[y];
}



void solve()
{
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    timer = 1;
     //euler_tour_1(1,0);
     //euler_tour_2(1,0);
     //timer=0;
     euler_tour_3(1,0);
}






int main() {
    solve();
    
}
