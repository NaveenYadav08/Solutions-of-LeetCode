https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

class Solution {
public:
    int kadane(vector<int>  nums,int K){
        int result = INT_MIN;
        int sum=0;
        set<int> s;
        s.insert(sum);
        for(int num : nums){
            sum+=num;
            auto tmp = s.lower_bound(sum-K);
            if(tmp != s.end()) result = max(result, sum- *tmp);
            s.insert(sum);
        }
        return result;
    }

    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        int ans=INT_MIN;
        for(int i=0;i<a.size();i++){
            vector<int> v(a[0].size(),0);
            for(int j=i;j<a.size();j++){
                for(int k=0;k<a[0].size();k++)
                    v[k]+=a[j][k];
                ans=max(ans,kadane(v,k));
            }
        }
        return ans;
    }
};
