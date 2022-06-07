https://www.codechef.com/problems/DISHOWN


#include <bits/stdc++.h>
using namespace std;


class par{
    public: 
    vector<int> chef;
    par(int n)
    {
        chef.resize(4*n+4);
        for(int i=0; i<4*n+4; i++)
        {
            chef[i]=i;
        }
        // chef is my parent array
    }

    int find(int x) // find dunction
    {
        if(x==chef[x]) return x;
        return chef[x]=find(chef[x]);
    }
};

///////////////////////////////// MAIN THING ///////////////////////
void solve()
{
    int n;
    cin>>n;
    // par class ka object bnaya
    par changes(n);

    vector<int> a(n);

    for(int i=0; i<n; i++)
    cin>>a[i]; //score
    // q queries
    int q;
    cin>>q;

    while(q--)
    {
        int t;
        cin>>t;
        if(t==0)
        {
            int u, v;
            cin>>u>>v;
            --u,--v; // 0 base index

            int pu=changes.find(u); // parent or chef of respective dishes 
            // AS I am combing on bases of score so jo parent hoga dish ka uspe uski sab dish mae se max hi score hoga
            int pv=changes.find(v);

            if(pu == pv)  // dono dish ke parent same
            {
                cout<<"Invalid query!"<<'\n';
            }
            
            else if(a[pu]==a[pv])
                continue; // equal score

            else if(a[pu]>a[pv])
            {
                changes.chef[pv] = pu;
            }
            else
            {
                changes.chef[pu] = pv;
            }
        }
        else
        {
            int x;
            cin>>x;
            cout<<changes.find(x-1)+1<<endl;
        }
    }
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
