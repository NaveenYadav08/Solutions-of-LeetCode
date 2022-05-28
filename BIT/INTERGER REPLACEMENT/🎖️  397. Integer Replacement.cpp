https://leetcode.com/problems/integer-replacement/

397. Integer Replacement

class Solution {
public:
    int solve(long long n) {
        if(n == 1) return 0;
        int ans = 0;
        if(n%2 != 0) {
            ans = 1+min(solve(n+1),solve(n-1));
           
        } else {
            ans = 1+solve(n/2);
        }
        
        return ans;
    }
    
    int integerReplacement(int n) {
        return solve(n);
    }
};
