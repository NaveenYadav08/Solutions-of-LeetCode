https://leetcode.com/problems/palindrome-partitioning/


class Solution {
public:
    
    bool isPali(string s)
    {
        int i=0;
        int j=s.size()-1;
        bool flag=true;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                flag=false;
                break;
            }
            i++;
            j--;
        }
        return flag;
    }
    
    void helper(vector<vector<string>>& ans, vector<string> tmp, int i, string s, int n)
    {
        if(i==n)
        {
            ans.push_back(tmp);
            return;
        }
        
        if(i>n)
            return;
        
        for(int I=i;I<n;I++)
        {
            string prefix = s.substr(i,I-i+1);
            if(isPali(prefix))
            {   //cout<<prefix<<endl;
                tmp.push_back(prefix);
                helper(ans,tmp,I+1,s,n);
                tmp.pop_back();
            }
        }
        
        
            
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        int i=0;
        vector<string> tmp;
        int n=s.size();
        helper(ans,tmp,i,s,n);
        return ans;
        
    }
};
