//Leetcode - 

// CODE 
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size(), element = -1, count = 0;
        
        for(int i = 0; i < arr.size(); ++i) {
            element = max(element, arr[i]);
            if(element == i) count += 1;
        }
        
        return count;
    }
};
