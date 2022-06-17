https://leetcode.com/problems/cinema-seat-allocation/



class Solution {
public:
    bool vacant(int start,int end,vector<int> &r)
    {
        for(auto pos:r)
            if(start<=pos&&pos<=end)
                return false;
        return true;
    }
    
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        unordered_map<int,vector<int > > mp;
        
        
        for(int i=0;i<r.size();i++)
        {
            //because group can sit starting from 2,4,6 as given in problem statement
            if(r[i][1]!=1&&r[i][1]!=10)
            {
                mp[r[i][0]].push_back(r[i][1]);   
            }
        }
        
        
        //in blank row 2 family can sit;
        int count=(n-mp.size())*2; // he is doing that 1 , 10 bcz of it
        for(auto c:mp)
        {
            if(vacant(2,5,c.second)||vacant(4,7,c.second)||vacant(6,9,c.second))
                count++;
        }
        
        return count;
    }
};
