
https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

class Solution {
public:
    int isLands=0,r,c;
    
    int vis[31][31];
    
    void dfs(vector<vector<int>>& g,int i,int j){
        if(i<0 || i>=r || j<0 || j>=c || vis[i][j] || !g[i][j]) return;
        vis[i][j]=1;
        dfs(g,i+1,j);
        dfs(g,i-1,j);
        dfs(g,i,j+1);
        dfs(g,i,j-1);        
    }
    
    void countALL(vector<vector<int>>& g){
        
        isLands=0;
        memset(vis,0,sizeof(vis));
        
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j){
                if(!vis[i][j]&&g[i][j]) {dfs(g,i,j),isLands++;}
                
            }
    }
    
    int minDays(vector<vector<int>>& g) {
        // 1 LAND 0 WATER 
        r=g.size();
        c=g[0].size();
        
        
        countALL(g); // COUNTING ISLANDS
        
        
        if(isLands!=1) return 0;
        
        
        
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j){
                if(g[i][j]){
                    g[i][j]=0; // remove it and count is valid now
                    countALL(g);
                    if(isLands>1 or isLands==0) return 1;
                    g[i][j]=1;
                }
            }
        
        return 2;
        
        // if by removing 1 land we get 2 or 0 compo ans is 1 
       // else for all case ans is 2
        // as shown below 
        
        
        
//         1 1 1 
//         1 1 1 
//         1 1 1 
            
//         1 0 1
//         1 1 0
//         1 1 1
    }
};
