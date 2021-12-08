// LEETCODE _  https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

// CODE 
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunk = 0;
        vector<int> rmin(n+1,INT_MAX);
        for(int i = n-1;i>=0;i--){
            rmin[i] = min(rmin[i+1],arr[i]);
        }
        int lmax = INT_MIN;
        for(int i =0; i<n;i++){
            lmax = max(lmax,arr[i]);
            if(lmax <= rmin[i+1]){
                chunk++;
            }
        }
        
        return chunk;
    }
};
