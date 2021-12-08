// LEETCODE - https://leetcode.com/problems/interval-list-intersections/

// CODE 

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> ans;
        int n=f.size();
        int m=s.size();
        int i=0,j=0;
        while(i<n&&j<m){
            
                int l=max(f[i][0],s[j][0]);
                int h=min(f[i][1],s[j][1]);
                if(l<=h)
                ans.push_back({l,h});
            
            if(f[i][1]<s[j][1])i++;
            else j++;
        }
        return ans;
    }
};
