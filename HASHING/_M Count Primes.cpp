// Problem Link : https://leetcode.com/problems/count-primes/

// Time : O(NloglogN)
// Space : O(N)

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;

        int Count = 0;
        vector<bool> isPrime(n+1, 1);
        isPrime[0] = isPrime[1] = 0;

        for (int i = 2; i < n; i++)
        {
            if (isPrime[i] == true)
            {
                for (int j = 2 * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
            if (isPrime[i]) Count++;
        }
        return Count;
    }
};
