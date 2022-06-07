https://codeforces.com/contest/25/problem/D


https://www.youtube.com/watch?v=5nfm5__jjN8


Codeforces graph theory problem solving series:

What will you learn from this video editorial?: 

1. How to use DSU data structure to solve graph problems involving multiple connected components of a graph.

2. Why prevention is better than cure in DSU data structure

Problem Link: https://codeforces.com/contest/25/pro...

Solution Link: https://codeforces.com/contest/25/sub...

Solution Sketch: 
 1) Add an edge between nodes from different connected components so that all connected components get merged into a single connected component 
 – this can be done easily using DSU.

2) Remove redundant edges – edges connecting nodes already in the same connecting component.

3) Instead of removing the redundant edges manually just check if the 2 endpoints of the edges are already in the same connected component 
(if they are then don’t add the edge otherwise add the edge).

 
 
 #include <bits/stdc++.h>
using namespace std;



struct DSU
{
    int n;
    vector<int> p;
    DSU(int _n)
    {
        n = _n;
        p.assign(n + 1,0);
        // parent
        for (int i = 1;i<=n;i++) p[i] = i;
    }

    int Find(int i)
    {
        if (p[i] == i)return i;
        return p[i] = Find(p[i]);
    }

    void Merge(int u,int v)
    {
        u = Find(u), v = Find(v);
        p[v] = u;
    }
};

int main()
{
    
    int n;
    cin>>n;
    // list 1 store extra edge
    // list 2 store edge bw node from diff set
    vector<vector<int>> list1,list2; //list2 stores the edges between pairs of nodes in different cc's
    DSU val(n);

    for (int i = 0;i<n - 1;i++){
        int u,v;
        cin>>u>>v;
        if (val.Find(u) == val.Find(v)) // if same set add in redundant list
            list1.push_back({u,v});
        else val.Merge(u,v);
    }   
    

    // for each u v pair
    for (int u = 1; u<=n; u++){
        for (int v = u + 1; v<=n; v++){
            if (val.Find(u) == val.Find(v)) continue;
            //we know that u<-->v is an edge which should be added
            //because u and v are part of different cc's
            list2.push_back({u,v});
            val.Merge(u,v);//so that we are not introducing extra redundant edges
        }
    }

    cout<<list2.size()<<'\n';
    for (int i = 0;i<(int)list2.size();i++)
        cout<<list1[i][0]<<" "<<list1[i][1]<<" "<<list2[i][0]<<" "<<list2[i][1]<<'\n';
    return 0;
}
