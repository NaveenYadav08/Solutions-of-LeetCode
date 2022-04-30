#include <bits/stdc++.h>
using namespace std;

// ADJANCENCY LIST REPRESENTAION BASIC WEIGHTED

// class Graph
class Graph{
    //int V;
   unordered_map<string,list<pair<string,int>>> l;

    public:
    // Graph(int V)
    // {
    //     this->V=V;
    //     l = new list<int>[V];
    // }

    void addedge(string x, string y, bool bidir, int wgt)
    {
        l[x].push_back({y,wgt});
        if(bidir)
        l[y].push_back({x,wgt});

    }

    void printGraph()
    {
        for(auto city:l)
        {
            cout<<"City "<<city.first<<" -> ";
            for(auto nbr:city.second)
            {
                cout<<"( "<<nbr.first<<","<<nbr.second<<" ) ";
            }
            cout<<endl;
        }
    }

};


int main() {
    // cout<<"Hello World!";
    Graph g;
    g.addedge("A","B",true,20);
    g.addedge("B","D",true,40);
    g.addedge("A","C",true,10);
    g.addedge("C","D",true,40);
    g.addedge("A","D",false,50);
    g.printGraph();
    return 0;
}
