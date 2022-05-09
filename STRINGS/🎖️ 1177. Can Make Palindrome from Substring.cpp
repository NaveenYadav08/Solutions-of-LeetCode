// link https://leetcode.com/problems/can-make-palindrome-from-substring/
// mene prefix frequency array bna lia taki 
// easily hr substr me fr of char dekh lu 
// ab odd no of freq count kri
// agr odd freq <= 2* jinte change kr skta to ok 
// else no 

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        
        vector<bool> ans;
        
        
        vector<vector<int>> str;
        vector<int> mapp(26, 0);
        str.push_back(mapp);
        
        for(int i=0; i<s.length(); i++)
        {
            mapp[s[i]-'a']++;
            str.push_back(mapp);
        }
        


        
        
        
        for(int i=0; i<q.size(); i++)
        {
            int I=q[i][0];
            int J=q[i][1];
            int K=q[i][2];
            
            int len =J-I+1;
            
            if(len==1)
            {ans.push_back(true); continue;}
            

            
            else   
            {
                int JJ= J+1;
                int odd=0;
                
                for(int ii=0; ii<26; ii++)
                {
                  int tt = str[JJ][ii]-str[I][ii];
                    if(tt%2==1)
                        odd++;
                }
                
                
                
               

            if(odd/2<=K)
                ans.push_back(true);
            else
                ans.push_back(false);
                
            }
        }
        
        return ans;
        
        
    }
};
