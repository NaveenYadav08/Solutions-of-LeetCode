// LEETCODE https://leetcode.com/problems/find-common-characters/

// CODE
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        int n=words.size();
        int counting[n][256];
        memset(counting,0,sizeof(counting));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                counting[i][words[i][j]]++;
            }
        }
        
        
        vector<string> ans;
        
        for(int i=0;i<256;i++)
        {   int minn =INT_MAX;
            //int flag=0;
            for(int j=0;j<n;j++)
            {
               minn=min(minn,counting[j][i]);
            }
            if(minn!=0)
            {
                string A="";
                char ch=i;
                A+=ch;
                int tt=minn;
                while(tt--)
                ans.push_back(A);
            }
        }
        
        return ans;

        
    }
};
