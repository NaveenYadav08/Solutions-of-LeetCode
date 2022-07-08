https://www.youtube.com/watch?v=2vGPqCcoxjM&t=206s

https://leetcode.com/problems/rabbits-in-forest/





to minimize we assume all same no are of same grp 
supporse R say 4 = so grp size  = 4 + 1
    
    Now if freq of this > 4  means other grp of same freq 



class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        
        for (auto n : answers) {
            ++mp[n];
        }
        
        int ans = 0;
        for (auto& [rab, cnt] : mp) {
            while (cnt > 0) {
                ans += rab + 1;
                cnt -= rab + 1;
            }
        }
        
        return ans;
    }
};
