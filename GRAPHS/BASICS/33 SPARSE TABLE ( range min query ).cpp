#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N=100005, M=22;


//min value
struct sparse_table
{
   vector<vector<int>> mat;
   int n,m; // size and log
   vector<int> p2; // it will store log base 2

   void init(int _n, int _m)
   {
       n=_n;
       m= _m;
       mat.resize(n);
       p2.resize(n+1);
       for(int i=0; i<n; i++)
       mat[i].resize(m);
       
       for(int i=1; i<=n; i++)
       {
          p2[i]=p2[i/2]+1; // log ( n ) = log (n/2) + 1;
       }
   }

   void build(int a[])
   {
       for(int i=0; i<n; i++)
       {
           mat[i][0]=a[i]; // base case len 1 ki query ka ans will be itself
       }

       for(int j=1; j<m; j++)
       {
           for( int i=0; i+(1<<j) <= n ; i++)
           {
              mat[i][j]=min(mat[i][j-1],mat[i+(1<<(j-1))][j-1] );
              //range sum
              // mat[i][j-1] + mat[i+(1<<j)][j-1]
           }
       }
   }
  
  // step of filling is diff from step of query
   int query(int l, int r)
   {
       int pw=p2[r-l]; // so i will find log of power less than r
       return min(mat[l][pw], mat[r-(1<<pw)+1][pw]);
       // some from left hand side some from right hand side 
   }

};



void solve()
{
    int i,j,k,n,m,ans=0,cnt=0,sum=0;


}


int main() {
    solve();

}
