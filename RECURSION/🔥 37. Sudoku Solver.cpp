https://leetcode.com/problems/sudoku-solver/


class Solution {
public:

bool isvalid(vector<vector<char>>&board, int row, int col, char num){
        for(int i=0; i<9;i++){
            if(board[i][col]==num)
                return false;
        }
        for(int i=0; i<9;i++){
            if(board[row][i]==num)
                return false;
        }
        int rn = sqrt(9);
        int r=(row/3)*3;
        int c=(col/3)*3;
        for(int i=r; i<r+rn; i++){
            for(int j=c; j<c+rn; j++){
                if(board[i][j]==num)
                    return false;
            }
        }
        return true;
    }

bool answer(vector<vector<char>>&board, int i, int j){
       
    if(i==9)
            return true;
    
    if(j==9){
            i=i+1;
            j=0;
        return answer(board,i,j);
            }
    
        
    
        if(board[i][j]=='.'){
            for(char c='1'; c<='9'; c++){
                if(isvalid(board, i,j,c)){
                    board[i][j]=c;
                    if(answer(board,i,j+1)==true){
                        return true;
                    }
                    board[i][j]='.';
                }
            }
        }
    
        else{
            if(answer(board,i,j+1))
                return true;
        }
    
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
       answer(board,0,0);
    }
};
