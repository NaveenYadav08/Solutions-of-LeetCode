// LEETCODE - https://leetcode.com/problems/product-of-array-except-self/submissions/


// CODE

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n);
        
        ans[n - 1] = 1; // ans array used as right product array
        
        for(int i = n - 2; i >= 0; i--){
            ans[i] = nums[i + 1] * ans[i + 1];
        }
        
        int leftProd = 1;
        for(int i = 0; i < n; i++){
            ans[i] = leftProd * ans[i];
            leftProd = leftProd * nums[i];
        }
        
        return ans;
    }
};


// TC :: O(n) and SC :: O(1)


// if I can reuse divide 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int flag=0,mul=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0) mul=mul*nums[i];
            else flag++;
        }
        for(int i=0;i<n;i++){
            if(flag==1){
                if(nums[i]==0) nums[i]=mul;
                else nums[i]=0;
            }
            if(flag==0 && nums[i]!=0) nums[i]=mul/nums[i];
            if(flag>1 ) nums[i]=0;
           
        }
        return nums;
    }
};
