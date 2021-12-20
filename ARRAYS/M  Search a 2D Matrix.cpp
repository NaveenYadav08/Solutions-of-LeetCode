//leetcode - https://leetcode.com/problems/search-a-2d-matrix/

// code 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int start = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int end = n*m - 1;
        
        while(start<=end)
        {
            int mid = (start+end)/2;
            int i = mid/m;
            int j = mid%m;
            if(matrix[i][j]==target)
                return true;
            else if (target>matrix[i][j])
                start = mid+1;
            else 
                end = mid-1;
            
        }
        
        return 0;
        
    }
};
