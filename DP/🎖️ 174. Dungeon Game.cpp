https://leetcode.com/problems/dungeon-game/


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // min health path
        int r=dungeon.size();
        int c=dungeon[0].size();
        
        vector<vector<int>> dp(r,vector<int>(c));
        
        for(int i=r-1;i>=0;--i)
        {
            for(int j=c-1;j>=0;--j)
            {
                if(i==r-1 && j==c-1)    //Bottom-Right cell (Princess Cell)
                    dp[i][j] = min(0,dungeon[i][j]); // as -ve health
                else if(i==r-1)   //last row
                    dp[i][j] = min(0,dungeon[i][j]+dp[i][j+1]);
                else if(j==c-1)   //last col       
                    dp[i][j] = min(0,dungeon[i][j]+dp[i+1][j]);
                else
                    dp[i][j] = min(0,dungeon[i][j]+max(dp[i][j+1],dp[i+1][j]));
            }
        }
        return abs(dp[0][0])+1;
    }
};

// https://www.youtube.com/watch?v=4uUGxZXoR5o
