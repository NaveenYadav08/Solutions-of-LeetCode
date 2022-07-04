https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        int ans;
        if(n==0){
            return 1;
        }
        if (n < 0) { 
            n = abs(n);
            x = 1/x;
        }
        
        double subprob = myPow(x,n/2);
        
        if(n%2==0){
            return subprob * subprob; // x^2 ki power n/2
        
        }else{
            return x* subprob * subprob;
        }
    }
};
// TC - O(log n)
