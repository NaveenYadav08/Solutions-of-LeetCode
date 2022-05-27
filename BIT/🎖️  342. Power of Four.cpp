https://leetcode.com/problems/power-of-four/

class Solution {
public:
    
    bool isPowerOfFour(int n) {
        if(n<0)
            return false;
        if(n==1)
            return true;
        if(n==0)
            return 0;
        if(n%4!=0)
            return false;
        float k = log(n)/log(4);
        int N=k;
        return(k-N==0);
        
    }
};


//  Change  log ( a )  to base b  =  log ( a )/ log (  b )
