// A MUST DO QUESTION
// JUST FIND THE CASES THAT IS MAIN PART

// LEETCODE - https://leetcode.com/problems/maximum-equal-frequency/



// CODE 


class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnt;
        

        unordered_map<int, unordered_set<int> > occur;
        
        int ans = 1;
        for(int i=0; i<nums.size(); ++i) {

            int a = nums[i];
            if(!cnt.count(a)) {
                occur[1].insert(a);
            } else {
                occur[cnt[a]].erase(a);
                if(occur[cnt[a]].size() == 0) {
                    occur.erase(cnt[a]);
                }
                occur[cnt[a] + 1].insert(a);
            }
            cnt[a]++;


            if(occur.size() == 2) {

                if(occur.count(1) && occur[1].size() == 1) {  // 2 2 2 2 3
                    ans = i+1;
                }
                
                auto it1 = occur.begin();
                auto it2 = it1++;
               //  2 2 2 4 4 4 5 5 5 5
                if(it1->first == it2->first - 1 && it2->second.size() == 1) {
                    ans = i+1;
                } else if(it1->first == it2->first + 1 && it1->second.size() == 1) {
                    ans = i+1;
                }
            } else if(occur.size() == 1) {

                if(occur.count(1)) { // 1 2 3 4 5 
                    ans = i+1;
                } else {

                    auto it = occur.begin();  // 2 2 2 2 2 2 2
                    if(it->second.size() == 1){
                        ans = i + 1;
                    }
                }
            }
        }
        
        return ans;
    }
};
