#include <bits/stdc++.h>
using namespace std;

// ADJANCENCY LIST REPRESENTAION BASIC

// class Graph
class Graph{
    int V;
    list<int> *l; // array of list

    public:
    Graph(int V)
    {
        this->V=V;
        l = new list<int>[V];
    }

    void addedge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);

    }

    void printGraph()
    {
        for(int i=0;i<V; i++)
        {
            cout<<"Vertex "<<i<<" -> ";
            for(int nbr:l[i])
            {
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }

};


int main() {
    // cout<<"Hello World!";
    Graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(1,2);
    g.printGraph();
    return 0;
}
