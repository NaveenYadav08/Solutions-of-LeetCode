// CPP program to implement traveling salesman
// problem using naive approach.
#include <bits/stdc++.h>
using namespace std;
#define V 4
int n=4;

int VISITED_ALL=(1<<n)-1;
int dp[16][4]; //mask , city
// implementation of traveling Salesman Problem

int travllingSalesmanProblem(int graph[][V], int mask, int pos)
{
     // if all city vis then add dis of going back to original city from curr pos
	if(mask==VISITED_ALL)
    return graph[pos][0];
    
    //loookup
    if(dp[mask][pos]!=-1)
    return dp[mask][pos];
    // vis unvisited citites
    int ans =INT_MAX;
    for(int city = 0; city<n; city++)
    {
        if((mask&(1<<city))==0)
        {
            int newAns= graph[pos][city]+travllingSalesmanProblem(graph,mask|(1<<city),city);
            ans=min(ans,newAns);
        }
    }
    return dp[mask][pos]=ans;
}

// Driver Code
int main()
{
	// matrix representation of graph
    for(int i=0; i<(1<<n); i++)
    for(int j=0; j<4; j++)
    dp[i][j]=-1;

	int graph[][V] = { { 0, 20, 42, 25 },
					{ 20, 0, 30, 34 },
					{ 42, 30, 0, 10 },
					{ 25, 34, 10, 0 } };
	
    
    //source city is 0
	cout << travllingSalesmanProblem(graph, 1, 0) << endl;
	return 0;
}
