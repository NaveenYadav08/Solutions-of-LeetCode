

// leetcode - https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

// code
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        // only those rows which are same or complement of each other will give us the answer
        
    int M=matrix.size();
        int N=matrix[0].size();
        
        unordered_map<string,int> m;
        
        for(int i=0;i<M;i++)
        {
            string s="";
            string S="";
            for(int j=0;j<N;j++)
            {
                if(matrix[i][j])
                {s+='0'; S+='1';}
                else
                {s+='1'; S+='0';}
            }
            m[s]++;
            m[S]++;
            
        }
        
        int ans =0;
        for(auto x:m)
        {
            ans=max(ans,x.second);
        }
        
        return ans;
        
        
        
        
    }
};
