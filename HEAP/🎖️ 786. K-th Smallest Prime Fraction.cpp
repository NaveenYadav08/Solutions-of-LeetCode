https://leetcode.com/problems/k-th-smallest-prime-fraction/
786. K-th Smallest Prime Fraction

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0, r = 1;
        
        while (l < r) {
            double m = (l + r) / 2;
            int numerator = 0, denominator = 0, count = 0;
            
            for (int i = 0; i < arr.size(); ++i) {
                auto it = lower_bound(arr.begin(), arr.end(), m * arr[i]);
                count += it - arr.begin();
                
                if (it != arr.begin() && numerator * arr[i] <= *(it - 1) * denominator) {
                    numerator = *(it - 1);
                    denominator = arr[i];
                }
            }
            
            if (count == k) {
                return {numerator, denominator};
            } else if (count < k) {
                l = m;
            } else {
                r = m;
            }
        }
        
        return {0, 0};
    }
};
