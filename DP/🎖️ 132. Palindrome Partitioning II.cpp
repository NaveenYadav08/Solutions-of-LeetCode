https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
    // TC : O(n2)
    // SC: O(n2)
    public:
    int minCut(string s) {
        
        if (s.size() == 0) {
            return 0;
        }

        int n = s.size();

        vector<vector<bool>> dp = buildMatrix(s,n); // i to j is pali or not
        int totalCuts[n];

        for (int j = 0; j < n; j++) {
            int cut = j; // max cuts
            for (int i = 0; i <= j; i++) {
                if (dp[i][j]) {
                    cut = min(cut, i == 0 ? 0 : totalCuts[i - 1] + 1);
                }
            }
            totalCuts[j] = cut;
        }

        return totalCuts[n - 1];
    }

    vector<vector<bool>> buildMatrix(string s, int n) {
        vector<vector<bool>> dp(n,vector<bool>(n));
// Filling is done  from bottom to up 
        // last row           1
        //     2nd lasst row 11
        //                  111
            
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        return dp;
    }
};
