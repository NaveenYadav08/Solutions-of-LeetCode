https://leetcode.com/problems/global-and-local-inversions/


class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        //We can observe that each local inversion is global inversion (or local inversions are subset of global inversions).
        //For both of them to be equal, every global inversion must only be a local inversion.
        
        //KEY  : //So, if we find any global inversion which is not local inversion, we return false
        
        //Hint : 0 can be placed in either 0th position or 1st position
        //Because if we put it anywhere else we will have more global inversions
        //Similarly, any element can be placed in either i , i-1 or i+1 index only
        
        //For example : 0 1 2 3 -> 1 0 3 2
        //So, abs(A[i]-i) should always be smaller than or equal to 1
        int n = A.size();
        for(int i = 0; i<n; i++) {
            if(abs(A[i]-i) > 1)
                return false;
        }
        
        return true;
    }
};
