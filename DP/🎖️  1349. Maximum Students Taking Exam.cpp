https://leetcode.com/problems/maximum-students-taking-exam/discuss/1953941/C%2B%2B-Clean-bit-masking-solution-Detailed-Explanation





/*
    https://leetcode.com/problems/maximum-students-taking-exam/
    
    Core idea is for the ith row, we need to decide the sitting arrangement based on the
    arrangement of previous row.
    We use bit masking for storing the seating layout for each row, since there are can be
    2^cols arrangements, we create a dp[rows+1][2^cols].
    
    Now iterate through each row and for each row, check if the layout is valid or not (seats are avail).
    Then check with each of the possible seating layouts of prev row, each time ensuring that there are 
    no diagonal seats, left and right seats in the current row. If the previous layout is compatible with
    current row layout, then update the number of students that can sit till current row.
    
    TC: O(N * 2^M * 2^M)
    SC: O(N*2^M)
*/


class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        
        // generate a mask for each row in seats
        vector<int> availableSeats(m + 1, 0); //EACH ROW KA BITMASK
          // avail_seats[i] = bit encoded representation of all avail seating positions
        // 1: avail seat, 0: seat not avail
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                if (seats[i - 1][j] == '.') {
                    availableSeats[i] = availableSeats[i] | (1 << j);
                }
            }
        }
        
        // dp table: [row, mask] the max students given row id ans a mask
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, -1));
        
        // init dp row 0
        // // To make the code simpler, one extra row is taken, which doesnt exists
        for (int mask = 0; mask < (1 << n); mask++) dp[0][mask] = 0;
        
        // for each row
        for (int i = 1; i <= m; i++) {
            // for mask in the current row
            for (int mask = 0; mask < (1 << n); mask++) {
                // if the mask is not allowed according to the available seats -> continue
                // // below line checks if mask layout is a subset of avail_seats[i] (valid positions)
                if ((mask & availableSeats[i]) != mask) continue;
                // if the mask has two adjacent seats -> continue 
                if (mask & (mask << 1) || mask & (mask >> 1)) continue;
                
                // for mask in the prev row
                
                 // once we know current layout has valid sitting positions,
                // we check tha max students that can sit in this layout by comparing
                // against the positions of student in prev row
                
                for (int prevMask = 0; prevMask < (1 << n); prevMask++) {
                    // if the previous mask does not exist -> continue
                    if (dp[i - 1][prevMask] == -1) continue;
                    
                    // if the previous mask has any seat diagonal to the current mask -> continue
                    if (((prevMask << 1) & mask) || ((prevMask >> 1) & mask)) continue;
                    
                    // update the dp table -> previous # of student + the # of 1 in the current mask
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][prevMask] + __builtin_popcount(mask));
                }
            }
        }
        return *max_element(dp[m].begin(), dp[m].end());
    }
};






































