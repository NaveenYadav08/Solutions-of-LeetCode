https://leetcode.com/problems/nth-magical-number/



class Solution {
public:
    
    // love this question 
    // Based on basic of LCM and HCF(GCD)
    
    int nthMagicalNumber(int n, int a, int b) {
        int  mod =1e9+7;
        // int LCM =(a*b)/ hcf(a,b); // finding lcm of a and b
        int LCM = (a*b)/__gcd(a,b); // inbuilt C++

        long l=0, r= (long)1e15;
          while(l<r) // searching towards infinity  using  - BINARY SEARCH
          {
              long mid= l+(r-l)/2; // finding mid
              
              //finding how much number are divisible with no repeatable 
              long num = mid/a + mid/b - mid/LCM;
              
              if(num<n) l=mid+1; // handling mid value by making it first traversal value
              
              else r=mid; // handling mid value by making it last traversal value
              
          }
        
        return (int) (l%mod);
    }
    
    
    // HCF == GCD
//     int hcf(int a,int b)
        
//     {
//         if(a==0) return b;
//         return hcf(b%a,a);
        
//     }
};
