// LINK  https://leetcode.com/problems/knight-probability-in-chessboard/

// CODE 


class Solution {
public:

int dx[8] = {-2,  -1,  1,  2,  2,  1,  -1,  -2};
int dy[8] = { 1,   2,  2,  1, -1, -2,  -2,  -1};
// DIRECTIONS 
    
bool inbound(int i,int j,int n)
{
    if(i>=0 && i<n && j>=0 && j<n)
        return true;
    return false;
}
    
// make 2 borads prevstarte and currstate    
double knightProbability(int n, int k, int r, int c) {
    
    vector<vector<double>>cur(n,vector<double>(n,0.0));
    vector<vector<double>>next(n,vector<double>(n,0.0));
    
    cur[r][c]=1.0;
    // for k=0 knight jst stay at pt (r,c), he can't move 
    
    for(int m=1;m<=k;m++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                double prob = cur[i][j]/8.0;
                if(cur[i][j]!=0)
                {
                    for(int k=0;k<8;k++)
                    {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        
                        if(inbound(ni,nj,n))
                        {
                            next[ni][nj] += prob;
                        }
                    }
                    
                }
            }
        }
        
        cur = next;
        fill(next.begin(),next.end(),vector<double>(n,0.0));
    }
    
    double sum = 0.0;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=cur[i][j];
            }
        }
    
    return sum;
}
};
