https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
// 2 Approaches BFS - DFS

// BFS - multi source
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int ct=0, res=-1;  
       // ct is count of fresh orange at end ct == 0 must so that all fresh ones rotted
      // res is min time
        //queue to store cells which have rotten oranges
        queue<vector<int>> q;
        vector<vector<int>> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        //traversing over all the cells of the matrix.
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++) 
            {
                //if grid value is more than 0, we increment the counter.
                if(grid[i][j]==1) 
                    ct++;
                //if grid value is 2, we push the cell indexes into queue.
                if(grid[i][j]==2) 
                    q.push({i, j});
            }
        }
      
      
      
        while(!q.empty())
        {
            //incrementing result counter
            res++;
            int size=q.size();
          // ek level pr kaam krna will res++
          // means at curr level rotting taking place simultanesly 
            for(int k=0;k<size;k++) 
            {
                //popping the front element of queue and storing cell indexes.
                vector<int> cur=q.front();
                ct--;
                q.pop();
                
                //traversing the adjacent vertices.
                for(int i=0;i<4;i++) 
                {
                    int x=cur[0]+dir[i][0], y=cur[1]+dir[i][1];
                    
                    //if cell indexes are within matrix bounds and grid value
                    //is not 1, we continue the loop else we store 2 in current
                    //cell and push the cell indexes in the queue.
                    if(x>=grid.size()||x<0||y>=grid[0].size()||y<0||grid[x][y]!=1) 
                        continue;
                    grid[x][y]=2;
                    q.push({x, y});
                }
            }
        }
        //returning the minimum time.
        if(ct==0) return res;
        return -1;
    }
};


// DFS 
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    dfs(grid,i,j,r,c,0,true);
                    
                }
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    return -1;
                ans=max(abs(grid[i][j]),ans);
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>&grid,int x, int y,int r, int c,int count,bool start){
        if(x<0 || x>=r || y<0 || y>=c || grid[x][y]==0 || grid[x][y]<0 && -grid[x][y]<count )
            return;
 // If the condition were not there, the DFS might overwrite a cell that was 
 // previously processed with a more optimal (shorter) path, leading to incorrect results.
 // This ensures that each cell always holds the minimum time required to rot the orange there.
        if(grid[x][y]==2 && !start)
            return;
            
        grid[x][y]=-count; // marking the cells as negative of the count
        
        dfs(grid,x+1,y,r,c,count+1,false);
        dfs(grid,x,y+1,r,c,count+1,false);
        dfs(grid,x-1,y,r,c,count+1,false);
        dfs(grid,x,y-1,r,c,count+1,false);
    }
};
