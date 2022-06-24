https://leetcode.com/problems/valid-tic-tac-toe-state/



// 1)  countX == countO or countX == countO + 1
// 2)  If O is in win condition then check 
//      a)     If X also wins, not valid
//      b)     If xbox != obox , not valid
// 3)  If X is in win condition then check if xCount is
//      one more than oCount or not 




class Solution {
public:
    
int win[8][3] = {{0, 1, 2}, // Check first row.
                {3, 4, 5}, // Check second Row
                {6, 7, 8}, // Check third Row
                {0, 3, 6}, // Check first column
                {1, 4, 7}, // Check second Column
                {2, 5, 8}, // Check third Column
                {0, 4, 8}, // Check first Diagonal
                {2, 4, 6}}; // Check second Diagonal
                
                
// Returns true if character 'c' wins. c can be either
// 'X' or 'O'
bool isCWin(char *board, char c)
{
    // Check all possible winning combinations
    for (int i=0; i<8; i++)
        if (board[win[i][0]] == c &&
            board[win[i][1]] == c &&
            board[win[i][2]] == c )
            return true;
    return false;
}


bool isValid(char board[9]){
    
        // code here
        int xCount=0, oCount=0;
    
    for (int i=0; i<9; i++)
    {
    if (board[i]=='X') xCount++;
    if (board[i]=='O') oCount++;
    }

    // Board can be valid only if either xCount and oCount
    // is same or xount is one more than oCount
    if (xCount==oCount || xCount==oCount+1)
    {
        // Check if 'O' is winner
        if (isCWin(board, 'O'))
        {
            // Check if 'X' is also winner, then
            // return false
            if (isCWin(board, 'X'))
                return false;

            // Else return true xCount and yCount are same
            return (xCount == oCount);
        }

        // If 'X' wins, then count of X must be greater
        if (isCWin(board, 'X') && xCount != oCount + 1)
        return false; 

        // If 'O' is not winner, then return true
        return true;
    }
    return false;
        
    }
    
    
    
bool validTicTacToe(vector<string>& board) {
        char Board[9];
        int i=0;
        for(auto x:board)
        {
            for(auto y:x)
            {
                Board[i++]=y;
            }
        }
        
        return isValid(Board);
    }
};
