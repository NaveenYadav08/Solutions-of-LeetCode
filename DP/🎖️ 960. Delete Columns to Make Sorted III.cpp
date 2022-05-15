// LINK  https://leetcode.com/problems/delete-columns-to-make-sorted-iii/

// CODE 



//     For a single string the problem this problem is equivalent to:  
//         Min columns to delete = string.length() - LIS (longest increasing subsequence).
    
//     You can find LIS for a string using DP by doing the following:

// L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
// L(i) = 1, if no such j exists.

//   int lengthOfLIS(vector<int>& nums) 
//   {
//             if (nums.empty()) {
//                 return 0;
//             }

//             int size = nums.size();
//             vector<int> dp(size, 1);

// eg for  b a b c a LIS array is 

//         1 1 2 3 1

//             for (int j = 0; j < size; ++j) {
//                 for (int i = 0; i < j; ++i) {
//                     if (nums[j] > nums[i]) {           // Modify this for multi string
//                         dp[j] = max(dp[j], dp[i] + 1);
//                     }
//                 }
//             }

//             return *max_element(dp.begin(), dp.end());
//         }
    
//     This problem involves extending the above approach for multi string case.


class Solution {
public:
    int minDeletionSize(vector<string>& A) {
    

        int columns = A[0].length();
        vector<int> dp(columns, 1);

        for (int j = 0; j < columns; ++j) {
            for (int i = 0; i < j; ++i) {
                if (isGreater(j, i, A)) {                     
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
// dp is LIS for multi string CASE
        return columns - *max_element(dp.begin(), dp.end());
    }
    
private:
    bool isGreater(int j, int i, vector<string>& A) {
        int rows = A.size();
        
        for (int k = 0; k < rows; ++k) {
            if (A[k][j] < A[k][i]) {
                return false;
            }
        }
        
        return true;
    }
};
