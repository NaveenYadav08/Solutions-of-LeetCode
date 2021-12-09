// LEETCODE - https://leetcode.com/problems/valid-sudoku/

// CODE 

class Solution {
public:
    
    bool isSafe(vector<vector<char>> board, int i, int j , char ch)
    {    
        

        
        
        for(int k=0;k<9;k++)
        {
            if(board[k][j]==ch and k!=i)
                return false;
        }  
        
        
        for(int k=0;k<9;k++)
        {
            if(board[i][k]==ch and k!=j)
                return false;
        }
        
        
            // find in sub-grid
    int rn = sqrt(9);
    int sx=( i/rn)*rn;
    int sy =( j/rn)*rn;
    for( int x =sx; x<sx+rn; x++)
    {
        for( int y=sy; y<sy+rn; y++)
        {
            if( board[x][y]==ch and i!=x and j!=y)
            {
                return false;

            }
        }
    }

        
         return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n=9;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {    
                
            char ch=board[i][j];
             if(ch!='.')
             if(isSafe(board, i, j, ch)==false)
                    return false;
            }
        }
        
        return true;
        
    }
};
