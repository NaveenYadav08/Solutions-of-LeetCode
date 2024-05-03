if we have p and q elements with repetations 

formula is = ( p + q )!/ (p! * q!)

Used in GRID PATH problem 

// CODE //
class Solution {
public:
    int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
};
