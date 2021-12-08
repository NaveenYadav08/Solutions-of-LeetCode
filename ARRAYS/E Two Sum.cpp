// Leetcode -  https://leetcode.com/problems/two-sum/submissions/

// 3 Approaches 


// Approach - 1
// 2 loops



// Approach - 2
// map or hashing 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[target-nums[i]] = i;
            }
            else{
                return {m[nums[i]],i};
            }
        }
        return {};
    }
};



// Approach - 3
// sort and binary search

// code
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,l,r;
        vector<pair<int,int>>v;
        vector<int>ans;
        
        for(i=0;i<nums.size();i++){
            v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(),v.end());
        
        l=0,r=v.size()-1;
        
        while(l<r){
            if(v[l].first+v[r].first==target){
                ans.push_back(v[l].second);
                ans.push_back(v[r].second);
                break;
            }
            else if(v[l].first+v[r].first>target){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};
