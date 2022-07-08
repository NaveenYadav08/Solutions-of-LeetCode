https://leetcode.com/problems/corporate-flight-bookings/



class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int>v(n+1,0);
            for(int i = 0 ; i < bookings.size(); i++){
                    v[bookings[i][0]-1] += bookings[i][2];
                    v[bookings[i][1]] += -bookings[i][2]; 
            }
        
            vector<int> ans(n,0);
            ans[0] = v[0];
            for(int i = 1;i < n; i++){
                    ans[i] = ans[i-1] + v[i];
            }
            return ans;
    }
};
