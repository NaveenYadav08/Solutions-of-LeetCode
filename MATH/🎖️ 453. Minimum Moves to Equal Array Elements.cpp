https://leetcode.com/problems/minimum-moves-to-equal-array-elements/


Incrementing n-1 elements =decrementing 1 element
Since after Decrementing all elements they should be equal and also min. moves
so decrement them to min. element present.

Here sort done to find Min . Element Could be find more effeciently in O(n) time.
Here Temp Stores min. Element
Here ct used to count moves to convert each element to min. element.

Finally return ct;




class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end()); // now the minimum element is at 0th index
        int minimum_element = nums[0];
        int answer = 0;
        
        for(int i=n-1; i>=0; i--)
        {
            answer += (nums[i] - minimum_element);
        }
        
        return answer;
    }
};
