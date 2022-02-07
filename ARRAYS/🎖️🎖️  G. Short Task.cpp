
https://codeforces.com/contest/1512/problem/G

        #include<bits/stdc++.h>
        using namespace std;
        #define ll long long
        #define N 10000007
        ll sum[N], ans[N];
         
        void pre()
        {
            for(ll i=1;i<N;i++){
                for(ll j=i;j<N;j+=i){
                    sum[j] += i;
                }
            }
            memset(ans,-1,sizeof(ans));
            for(ll i=1;i<N;i++){
                if(sum[i]<=N && ans[sum[i]]==-1) ans[sum[i]] = i;
            }
        }
         
        int main()
        {
            ll t=1,T=0,i,j,n,m,k,x,y,z;
            pre();
            cin>>t;
            while(t--){
                cin>>n;
                cout<<ans[n]<<endl;
            }
            return 0;
        }
