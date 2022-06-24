https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    
    void helper(vector<string>& ans, string &tmp, int op, int cl, int n )
    {
        if(op==cl and op==n)
        {
            ans.push_back(tmp);
        }
        if(op>n or cl>n or tmp.size()>2*n) return;
        
        if(op==0)
        { tmp+='(';
         helper(ans, tmp, op+1, cl, n);
         tmp.pop_back();
            
        }
        else if(op<n)
        {
            tmp+='(';
            helper(ans, tmp, op+1, cl, n);
            tmp.pop_back();
            
        }
        if(op>cl)
        {
            tmp+=')';
            helper(ans, tmp, op, cl+1, n);
            tmp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int o=0;
        int cl=0;
        string tmp="";
        helper(ans,tmp, o, cl,n );
        return ans;
    }
};
