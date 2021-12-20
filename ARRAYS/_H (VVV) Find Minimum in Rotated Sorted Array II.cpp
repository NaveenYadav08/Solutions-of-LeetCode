// leetcode https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int r = nums.size()-1, l = 0, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else if (nums[mid] < nums[r]) r = mid;
            else r--; // bcz here i dont know where is ans so i did r-- i can also do s++)
          
               
        }
        return nums[mid];
    }
};


               mid is here i dont knw where to go so i can do r-- pr s++ monotonically
_______________|_________     _________
                            /
                           /
