// leetcode  Preimage Size of Factorial Zeroes Function


// isme binary search lgakr let x is the ans to mae x kae kitne zero aaenge wo pta kr skta hu agr mil gya to bdya jada aaya to mid-1 else mid+1;
// mila hi nhi to 0;


// BINARY SEARCH 

class Solution {
public:
    long long int solve(long long int n){
        long long int count = 0;
        long long int x = 5;
        while(x<=n){
            count+= n/x;
            x = x*5;
        }
        return count;
    }
    
    
    int preimageSizeFZF(int k) {
        long long int start = 0;
        long long int end = LLONG_MAX;
        while(start<=end){
            long long int mid = start + (end - start)/2;
            long long int x = solve(mid);
            if(x==k){
                return 5;
            }else if(x>k){
                end = mid -1;
            }else{
                start = mid +1;
            }
        }
        return 0;
    }
};
