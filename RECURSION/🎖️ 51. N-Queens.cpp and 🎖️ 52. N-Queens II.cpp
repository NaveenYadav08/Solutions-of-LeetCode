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










---------------------------------------------------------------------------------------------------------------------------------------------------------
https://leetcode.com/problems/n-queens-ii/    
class Solution {
public:
   
    int ans=0;
    void solve(int n, vector<bool>& cols, vector<bool>& d1, vector<bool>& d2, int i)
    {
        if(i==n) //last row: solution found
        {
            ans++;
        }
        for(int j=0; j<n; j++)
        {
            int id1=j-i+n;
            int id2=i+j;
            if(cols[j] || d1[id1] || d2[id2]) continue; //present in column, diagonal 1, diagonal 2
            
            cols[j]=true;
            d1[id1]=true;
            d2[id2]=true;
            solve(n, cols, d1, d2, i+1); //solve for next row
            cols[j]=false;
            d1[id1]=false;
            d2[id2]=false;
        }
    }
    
    int totalNQueens(int n) {
        vector<bool> cols(n, false), d1(2*n, false), d2(2*n, false);
        solve(n, cols, d1, d2, 0);
        return ans;
    }
    
    
    
};
