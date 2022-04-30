// QUESTIONS 
// Minimum number of dice throw required to reach destiny 36 
// starting from source 

// find shortest path as well

// edges of snake or ladder also the way in we walk in 
// snake and  ladder like 1 to 2 , 2 to 3 
// snake mean jump -ve ladder is +ve jump
// vertex every no 1 to 36 
// position = curr + dice + ump ( snake or ladder )
// it is unwgt grph as eachh edge wgt same not jump











#include <bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
    //int V;
 map<T,list<T>> l;

    public:

    void addedge(int x, int y)
    {
        l[x].push_back(y);
        

    }

    void bfs(T src, T dest)
    {
        // queue and vis array
        map<T,int> dist;
        map<T,T> parent;
        queue<T> q;
       
       
        
        // all other node have distance infinite
        for(auto x:l)
        {
            T node = x.first;
            dist[node]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        parent[src]=src;


        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            
       
            //cout<< node<<"  ";
            for(int nbr:l[node])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr]=dist[node]+1;
                    parent[nbr]=node;
                }
            }
            

        }

        // print dist to destiny 
        cout<< dist[dest]<<endl;
        // print path destiny to src;
        T temp = dest;
        while(temp!=src)
        {
            cout<<temp<<" <-- ";
            temp=parent[temp];
        }
        cout<<src<<endl;


         
    }



};


int main() {
    //cout<<"Hello World!";
    int board[50]={0};

    // snakes and ladder 
    board[2]=13; // it means that from 2 there is a ladder of jump 13 to reach 2 + 13 = 15 
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;
    
    // add edge to graph
    Graph<int> g;
    for(int i=0; i<=36 ; i++)
    {
        for(int dice =1 ; dice <= 6 ; dice++ )
        {
            int j = i + dice;
            j += board[j];

            if(j<=36  and j>0 )
            {
                g.addedge(i,j);
            }
        }
    }
    g.addedge(36,36);

    g.bfs(0,36);

    return 0;
}
