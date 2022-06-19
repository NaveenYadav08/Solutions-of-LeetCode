
https://leetcode.com/problems/find-k-th-smallest-pair-distance/


class Solution {
public:
    int countArray(vector<int> &nums,int ele){
        
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            
            int pos = upper_bound(begin(nums),end(nums),ele+nums[i])-begin(nums)-i;
            
            count+=(pos-1);
        }
        
        return count;
    } 
    
    int smallestDistancePair(vector<int>& nums, int k) {
               
        sort(nums.begin(), nums.end());  //nlogn
        
        int n = nums.size();
        
        int l = 0;
        
       
        
        int r = nums[n-1] - nums[0];
        
        while(l<r){
            
            int mid = l + (r - l)/2;

            if(countArray(nums,mid) < k){
                l = mid+1;
            }
            else
                r = mid;
        }
        
        return l;
    }
};
