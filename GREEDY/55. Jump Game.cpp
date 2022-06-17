https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int re = 0;
        int tar = nums.size() - 1;
        
        for(int i=0;i<nums.size() - 1;i++) {
            if(i<=re) {
                re = max(re, i + nums[i]);
            } else {
                continue;
            }
        }
        
        return re >= tar;
    }
};
