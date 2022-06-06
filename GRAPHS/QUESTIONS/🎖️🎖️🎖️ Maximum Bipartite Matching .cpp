Kuhn algortihm 

FOR REFERNECE

https://www.tutorialspoint.com/Maximum-Bipartite-Matching


QUESTION LINK 

https://practice.geeksforgeeks.org/problems/maximum-bipartite-matching/1


THEORY 
The bipartite matching is a set of edges in a graph is chosen in such a way, that no two edges in that set will share an endpoint. \
The maximum matching is matching the maximum number of edges.
When the maximum match is found, we cannot add another edge. If one edge is added to the maximum matched graph, it is no longer a matching. 
For a bipartite graph, there can be more than one maximum matching is possible.

Algorithm

FUN 1
bipartiteMatch(u, visited, assign)

Input: Starting node, visited list to keep track, assign the list to assign node with another node.

Output − Returns true when a matching for vertex u is possible.

Begin
   for all vertex v, which are adjacent with u, do
      if v is not visited, then
         mark v as visited
         if v is not assigned, or bipartiteMatch(assign[v], visited, assign) is true, then
            assign[v] := u
            return true
   done
   return false
End




FUN 2
maxMatch(graph)

Input − The given graph.

Output − The maximum number of the match.

Begin
   initially no vertex is assigned
   count := 0
   for all applicant u in M, do
      make all node as unvisited
      if bipartiteMatch(u, visited, assign), then
         increase count by 1
   done
End



CODE :



class Solution {
public:
	vector<int>assign;
	vector<bool>visited;
	bool try_kunh(int u, vector<vector<int>>&G){
	    for (int v = 0; v < G[0].size(); v++){  //for all jobs 0 to n-1
	        if (G[u][v] && !visited[v])  //when job v is not visited and u is interested
	        {
	            visited[v] = true;
	             //mark as job v is visited
         //when v is not assigned or previously assigned
	            if (assign[v] < 0 || try_kunh(assign[v], G))
	            {
	                assign[v] = u;    //assign job v to applicant u
	                return true;
	            }
	        }
	    }
    return false;
	}
	
	
	
	int maximumMatch(vector<vector<int>>&G){
	    // G = A graph with M applicant and N jobs
		int m = G.size();
		int n = G[0].size();
		int N = max(n, m);  
		int ans = 0;
		assign.assign(N, -1); //an array to track which job is assigned to which applicant
		 //initially set all jobs are available
		 
		 
		for(int i = 0; i < m; i++){  //for all applicants

			visited.assign(N, false);  //initially no jobs are visited
			if(try_kunh(i, G))   //when u get a job
				ans++;
		}
		return ans;
	}

};


