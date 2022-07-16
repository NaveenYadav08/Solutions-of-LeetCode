https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int freq[26]={0};
        for(auto ch:s )
            freq[ch-'a']++; // freq li sbki
        
        string ans;
        
        bool isadded[26];
        memset(isadded,false,26); // used or not
        
        
        for(auto ch:s) // string traverse kia
        {
            freq[ch-'a']--;
            
                if(isadded[ch-'a'])
                {  
                    continue;
                }
            
             if(!ans.empty())
             { 
            
                 // if last char addd > curr char 
    while(!ans.empty() and *prev(ans.end())>ch and freq[(*prev(ans.end()))-'a']>0)
            {   
                isadded[(*prev(ans.end()))-'a']=false;
                ans.pop_back();
            }
            
             }
            
            ans.push_back(ch);
            isadded[ch-'a']=true;
            
            cout<<ans<<endl;
        }
        cout <<flush;
        return ans;
    }
};
