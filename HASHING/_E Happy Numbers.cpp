// LEETCODE - https://leetcode.com/problems/happy-number/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// Here is my code in C++ with explanation.

// As mentioned it is similar to slow and fast pointer used in Linkedlist cycle detection. So the main idea here is to compute fast and check if fast pointer could lead us to 1.

// We create a function calcSq which calculates a new number formed by sum of squares of the digits of the number

// for example:19 then 1^2 + 9^2 = 82

// Initialise slow equal to n and fast == calcSq(n)
// While they're not equal, perform -

// slow = calcSq(n)
// fast = calcSq(calcSq(n)), always one step ahead than slow
// Lastly, check if fast ==1

// Stats: 
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
// Memory Usage: 5.9 MB, less than 85.97% of C++ online submissions for Happy Number.






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









// CODE 


class Solution {
private:
    int calcSq(int n){
        int res=0;
        while(n!=0){
            int rem = n%10;
            res += rem * rem;
            n/=10;
        }
        return res;
    }    
    
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        bool flag=0;
        while(slow!=fast or flag==0){
            slow = calcSq(slow);
            fast = calcSq(calcSq(fast));
            flag=1;
        }
        return fast==1;
    }
};
