https://leetcode.com/problems/jump-game/


// we are only concerned with max jumps
class Solution {
    public:
    bool canJump(vector<int>& nums) { 
        int n = nums.size();
        
        if(n==1) return true;
        
        int Max = 0;
        
        for(int index=0; index<n-1 && Max>=index; index++){
            Max=max(Max,index + nums[index]);
            
            if(Max>=n-1){
                return true;
            }
        }
        
        return false;
    }
};
