// LEETCODE     https://leetcode.com/problems/two-sum/

// Hash Map Algorithm:
// Time Complexity: O(n)

// A much more efficient algorithm would be to use a hash map that stores a value x and its index i.
// We iterate through the array, and add values and their index ( x, i ) into the hash map. 
// If we find a corresponding value of x already inside of the map, we return their indexes. Looking at the implementation will make this make a lot more sense:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // our hash map that stores nums[i] --> i
        unordered_map<int,int> indexes;
        
		// iterating through the array
        for(int index = 0; index != nums.size(); index++){
			// if we find a corresponding value of nums[i] already in the hash map,
			// we have found the two values
            if(indexes.find(target-nums[index]) != indexes.end()){
                return {index, indexes[target-nums[index]]};
            }
            
			// inserts value x and its index i
            indexes[nums[index]] = index;
        }
        
		// again, returning a temporary array
        return {};
    }   
};
