Single Element in a Sorted Array
https://leetcode.com/problems/single-element-in-a-sorted-array/description/

    int singleNonDuplicate(vector<int> &nums){
        int n=nums.size();
        // Edge Cases
        if(n==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];

        int low=1,high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            // Checking if element is found
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                // We are in left, eliminate that 
                return nums[mid];
            }
            // Now we have to eliminate one half
            if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
                // We are in right, eliminate that
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }

// CODE 2 //

    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                left = mid + 1;
            else
                right = mid;
        }
        
        return nums[left];
    }
