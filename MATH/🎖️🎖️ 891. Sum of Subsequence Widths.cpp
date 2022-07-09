https://leetcode.com/problems/sum-of-subsequence-widths/


Logic -
Observations 1: Order doesn't matter
Observations 2: Every numbers contribute based on its index in the sorted array.

Mathematical Derivations -
Consider that there are total (n) number in a sorted array, then (i) numbers will be <= nums[i] and (n-i-1) numbers will be >= A[i]

A[i] will be upper bound of (2^i) subsequences <-------- when A[i] as maxm value
A[i] will be lower bound of (2^(n-i-1)) subsequences <-------- when A[i] as minm value

so, contribution of A[i] = upper - lower = A[i]*(2^i) - A[i]*(2^(n-i-1))
                                          
Ans  = Sum{A[i]* 2^i - A[i] * 2^(n-i-1)}  , for 0 <= i < n 
     = (A[0]*2^0 - A[0]*2^(n-1) + (A[1]*2^1 - A[1]*2^(n-2) + ... 
       + (A[i]*2^i - A[i]*2^(n-i-1) + ...  + (A[n-i-1]*2^(n-i-1) - A[n-i-1]*2^i + ... + (A[n-1] * 2^(n-1) - A[n-1]*2^0)
        
		//some of the terms in above expression will cancel each other,
		
Ans = Sum{A[i] * 2^i - A[n-i-1]* 2^i} ..........on taking 2^(i) common, the sum can be re-written as 
     =Sum{ (A[i] - A[n-i-1]) * 2^(i)  }

Now,
Step 1 : Sort the array first,
Step 2 : Once array is sorted, Calculate the result by summation of above derived results.


class Solution {
public:
    int MOD=1e9+7;
    
    int sumSubseqWidths(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long power = 1;
        long long res = 0;
         int  n = arr.size();
        
        
        for(int i=0;i<n;i++){
            res = (res + arr[i]*power)%MOD;
            power = (power*2)%MOD;
        }
        
        
        power = 1;
        
        for(int i=n-1;i>=0;i--){
            
            res = (res - arr[i]*power +MOD)%MOD;
            
            power = (power*2)%MOD;
        }
        
        return (res+MOD)%MOD;
    }
};
