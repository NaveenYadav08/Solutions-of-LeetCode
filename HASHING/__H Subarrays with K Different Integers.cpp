

// subarray with atleast k int - atleast (k-1) int 
// LEETCODE -https://leetcode.com/problems/subarrays-with-k-different-integers/

// CODE 



class Solution {
public:
    
int noofsubarray(vector<int> &nums, int k)
{
if(k==0) return 0;
int ans=0;
int a= *max_element(nums.begin(), nums.end());
int arr[a+5];
int currdistict=0;
fill(arr, arr+a+5 , 0);
int start=0, end=0;

    for(; end<nums.size(); end++)
    {
         if(arr[nums[end]]==0)
        {
            arr[nums[end]]++;
            currdistict++;
        }
        
        else arr[nums[end]]++;
        if(currdistict<=k)
            ans+=end-start+1;
        
        else 
        {
            while(start<=end && start<nums.size() && currdistict>k)
            {
                arr[nums[start]]--;
                if(arr[nums[start]]==0)
                    currdistict--;
                start++;
            }
            
            ans+=end-start+1;
        }
        
    }
        return ans;
    }

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return (noofsubarray(nums, k))-(noofsubarray(nums, k-1));
}
    
};
