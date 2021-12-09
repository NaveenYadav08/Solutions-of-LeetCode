// LEETCODE - https://leetcode.com/problems/subarray-sums-divisible-by-k/


// CODE 



class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        int ans=0;
        int sum=0;
        m[0]++;
        cout<<-10%7<<endl;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int t = sum%k;
            if(t<0) t+=k;
            ans+=m[t];
            m[t]++;
        }
        return ans;
    }
};
