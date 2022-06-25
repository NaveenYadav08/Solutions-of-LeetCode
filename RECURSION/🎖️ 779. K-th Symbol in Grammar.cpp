https://leetcode.com/problems/k-th-symbol-in-grammar/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 and (k==1))
            return 0;
        
        if(k%2==0)
        {int t=kthGrammar(n-1, (k+1)/2);
         if(t==0)
             return 1;
         else
             return 0;
        }
        else
            return kthGrammar(n-1, (k+1)/2);
        
    }
};

/* n=1 k=1        0
                  0 | 1
                  0 1 | 1 0    first half is same as prev. row and second half is just complement of prev row
                  0 1 1 0 | 1 0 0 1
*/
