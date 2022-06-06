
https://practice.geeksforgeeks.org/problems/possible-paths3834/1#



class Solution {
  public:
	long mod = 1000000007;
    long fun(vector<vector<int>>&graph, int u, int v, int k, vector<vector<int>>& dp){
        if(k==0){
            if(u==v)
                return 1;
            return 0;
        }
        
        if(dp[u][k]!=0){
            return dp[u][k] % mod;
        }
        
        long cou=0;
        
        for(int i=0; i<graph.size(); i++){
            if(graph[u][i]==1)
                cou += fun(graph, i, v, k-1, dp) % mod;
        }
        
        cou = cou%mod;
        if(cou<0){
            cou += mod;
        }
        
        dp[u][k] = cou ;
        
        return cou;
    }
    
    int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k)
    {
        // Code here
        vector<vector<int>> dp(graph.size(),vector<int>(k+1,0));
       
        
        return (int)fun(graph, u, v, k, dp);
    }
	

};
