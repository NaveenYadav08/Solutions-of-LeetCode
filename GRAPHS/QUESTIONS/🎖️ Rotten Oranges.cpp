https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1





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
