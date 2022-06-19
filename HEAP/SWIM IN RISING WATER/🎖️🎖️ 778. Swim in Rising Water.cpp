https://leetcode.com/problems/swim-in-rising-water/
778. Swim in Rising Water

class Solution {
public:
    // checking the boundary conditions of a grid
    bool isSafe(int x, int y, int n){
        if(x>=0 && x<n && y>=0 && y<n){
            return true;
        }
        return false;
    }
    
    
int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        //take 1 visited vector of size n*n
        vector<int> visited(n*n, false); 
        
        //declaring priority queue(min heap)
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        
        q.push(make_pair(grid[0][0], make_pair(0,0)));
        visited[grid[0][0]] = true;
        pair<int, pair<int,int>> temp;
        int ans = 0;
        
        while(q.empty()==false){
            temp = q.top();
            q.pop();
            
            ans = max(ans, temp.first);
            
            int x = temp.second.first;
            int y = temp.second.second;
            
            // if we reach at the bottom right square then return ans
            if(x==n-1 && y==n-1){
                return ans;
            }
            
            // move to next row
            if(isSafe(x+1,y,n) && visited[grid[x+1][y]]==false){
                visited[grid[x+1][y]] = true;
                q.push(make_pair(grid[x+1][y], make_pair(x+1,y)));
            }
            // move to previous row
            if(isSafe(x-1,y,n) && visited[grid[x-1][y]]==false){
                visited[grid[x-1][y]] = true;
                q.push(make_pair(grid[x-1][y], make_pair(x-1,y)));
            }
            // move to next column
            if(isSafe(x,y+1,n) && visited[grid[x][y+1]]==false){
                visited[grid[x][y+1]] = true;
                q.push(make_pair(grid[x][y+1], make_pair(x,y+1)));
            }
            // move to previous column
            if(isSafe(x,y-1,n) && visited[grid[x][y-1]]==false){
                visited[grid[x][y-1]] = true;
                q.push(make_pair(grid[x][y-1], make_pair(x,y-1)));
            }
        }
        
        return ans;
    }
};
