https://leetcode.com/problems/n-queens/

class Solution {
public:

bool isSafe(vector<string>&board,int row,int col,vector<vector<string>>&ans){
    for(int i=0;i<board.size();i++){
        if(board[i][col]=='Q'){
            return false;
        }
        if(row-i>=0 && col-i>=0 && board[row-i][col-i]=='Q' ){
            return false;
        }
        if(row-i>=0 && col+i<board.size() && board[row-i][col+i]=='Q'){
            return false;
        }
    }
    return true;
}

void solve(int row,vector<string>&board,vector<vector<string>>&ans){
    if(row==board.size()){
        ans.push_back(board);
        return;
    }
    for(int col=0;col<board.size();col++){
        if(isSafe(board,row,col,ans)){
            board[row][col]='Q';
            solve(row+1,board,ans);
            board[row][col]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<string> board(n, string(n,'.'));
    solve(0,board,ans);
    return ans;
}
};
