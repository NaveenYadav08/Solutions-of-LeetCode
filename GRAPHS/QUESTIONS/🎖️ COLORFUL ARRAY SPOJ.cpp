https://www.spoj.com/problems/CLFLARR/








#include <bits/stdc++.h>
using namespace std;

struct dsu
{
   vector<int> par;
   void init(int n)
   {
       par.resize(n);
       iota(par.begin(),par.end(),0); //iota is same to memset 
   }

   // parent of x // find fn here init all are parent of themself
   int get(int x)
   {
       return x==par[x]?x:(par[x]=get(par[x]));
   }

   void unite(int x, int y)
   {
       x=get(x);
       y=get(y);
       if(x!=y)
       {
           par[x]=max(par[x],par[y]);
           par[y]=max(par[x],par[y]);
       }
   }
};

int main() {
    int n,q;
    cin>>n>>q;
    int l[q], r[q], c[q];

    for(int i=0; i<q; i++)
    {
      
      cin>>l[i]>>r[i]>>c[i];

    }

    dsu G;
    G.init(n+2);
    int res[n+2]={};
    for(int i=q-1; i>=0; i--)
    {
        // index -> rightmost non color index
        int index =G.get(l[i]);
        while(index<=r[i])
        {
            res[index]=c[i];
            G.unite(index,index+1);
            //rightmost
            index=G.get(index);
        }
    }
    // Dekh inshort me apni query rev me fill kr rha hu 
    // or curr me fill krke curr ke next ke sah unite kr rha hu taki merko 
    // rightmost non clr index mil jae 

    for(int i=1; i<=n; i++)
    {
        cout<<res[i]<<endl;
    }

}
