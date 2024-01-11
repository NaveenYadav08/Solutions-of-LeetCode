https://leetcode.com/problems/integer-replacement/

397. Integer Replacement

class Solution {
public:
    int solve(long long n) {
        if(n == 1) return 0;
        int ans = 0;
        if(n%2 != 0) {
            ans = 1+min(solve(n+1),solve(n-1));
           
        } else {
            ans = 1+solve(n/2);
        }
        
        return ans;
    }
    
    int integerReplacement(int n) {
        return solve(n);
    }
};


/*-----------------IDEA---------------
If number is odd
    If number in 32-bit repesentaion is 'abccd....11'(rightmost 2nd bit is 1) then we add 1 because by adding one we will convert all righmost contineous 1 bits to 0, and more contineous rightmost bits be 0, we can get more contineous even numbers, so we can contineous keep dividing it by 2
    
    else if number in 32-bit repesentaion is 'abccd....01'(rightmost 2nd bit is 0) so we will subtract 1, so that most of right bits remains zero, so and more contineous rightmost bits be 0, we can get more contineous even numbers, so we can contineous keep dividing it by 2
    
ALTHOUGH 3 is exeptional because in bit representaion it is 00....011(2nd rightmost bit is one), but total number to make 3->1 increases if we add 1. So, we handle this case seprately
*/
