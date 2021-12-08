// GFG -  https://practice.geeksforgeeks.org/problems/common-elements5420/1
// CODE 
class Solution{
    public:
        vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        // Your code here
        
        unordered_map<int,int> m;
        unordered_map<int,int> M;
        for(int i=0;i<v1.size();i++)
        {
            m[v1[i]]++;
        }
        
        for(int i=0;i<v2.size();i++)
        {
            M[v2[i]]++;
        }
        
        vector<int> ans;
        for(auto x:m)
        {
            if(M.find(x.first)!=M.end())
            { int t=min(x.second,M[x.first]);
              while(t--)
              {ans.push_back(x.first);}
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
