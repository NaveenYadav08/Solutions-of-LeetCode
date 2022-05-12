// LINK - https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

CODE 

class Solution {
public:
 int maximumSum(vector<int>& arr) {
     
        int n =arr.size();
        if(n==1) return arr[0];
     
        vector<int> max_left(n),max_right(n);
        
        int ans=max(arr[0],arr[n-1]),curmax=0;
     
     
     // max from left
        max_left[0]=arr[0];
        for(int i=1;i<n;i++){
            max_left[i] =max(max_left[i-1]+arr[i],arr[i]);
            ans=max(max_left[i],ans);
        }
     
     //msx from right
        max_right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            max_right[i] =max(max_right[i+1]+arr[i],arr[i]);
            ans=max(max_right[i],ans);
        }
     
     // skip curr leftMax + rightMax
        int left,right;
        for(int i=0;i<n;i++){
            left = i==0?0:max_left[i-1];
            right = i==n-1?0:max_right[i+1];
            
            ans=max(left+right,ans);
        }
        return ans;
    }
};
