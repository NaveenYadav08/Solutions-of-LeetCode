ALSO 
(n+m)! / m! n!
it is use in https://practice.geeksforgeeks.org/problems/number-of-paths0926/1#
formula



https://leetcode.com/problems/path-with-maximum-gold/


class Solution {
public:
    
    
    bool isValid(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size())
            return false;
        if(grid[i][j]==0)
            return false;
        return true;
    }
    
    int helper(vector<vector<int>>& grid, int i, int j)
    {  
        if(isValid(grid, i, j))
        {   int gold= grid[i][j];
            grid[i][j]=0;;
         
            int ans=0;
            int op1=helper(grid,i+1, j);
            int op2=helper(grid,i-1, j);
            int op3=helper(grid,i, j+1);
            int op4=helper(grid,i, j-1);
         ans=gold+max(op1,max(op2,max(op3,op4)));
         grid[i][j]=gold;
         return ans;
            
        }
        return 0;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int glod=0;
        for(int i=0;i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
            {  
                if(grid[i][j]!=0)
                { 
                int gold=helper(grid, i, j);
                glod=max(glod,gold);}
            }
        
        
        return glod;
        
        
    }
};
