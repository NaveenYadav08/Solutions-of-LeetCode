https://leetcode.com/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(int c) {
        int sr=sqrt(c);
        if(sr*sr==c)return 1;
        
        unsigned long long r=sqrt(c);
        
        unsigned long long l=1;
        
        while( l<=r){
          unsigned long long val= l*l+r*r;
            if(val==c)return 1;
            
            if(val>c){
                r-=1;
            }
            
            else{ 
                l+=1;
            }
        }
        return 0;
    }
};
