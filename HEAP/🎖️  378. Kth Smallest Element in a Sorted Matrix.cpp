https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/


class Solution {
public:
    // count all elements less than the current mid
    // we start from right top and find elements less than mid in curr line
    // after we take same jth column to next line and start finding less than mid
    // tc - O(2n)
    int count(vector<vector<int>>& matrix, int mid){
        int n = matrix.size();
        
        int cnt = 0;
        int j = n-1;
        for(int i = 0; i < n; i++){
            while(j >= 0){
                if(matrix[i][j] <= mid){
                    cnt += j+1;
                    break;
                }
                j--;
            }
        }
        
        return cnt;
    }
    

int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        // apply binary search to find no. of elements less than mid in matrix    
        // if cnt >= k , we know that curr mid can be or can`t be ans so we keep looking left
        // if cnt < k, we look to right of mid to find a mid which has k lesser elements in matrix
        int low = matrix[0][0], high = matrix[n-1][n-1];
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            int cnt = count(matrix, mid);
            
            if(cnt >= k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return ans;
        
    }
};
