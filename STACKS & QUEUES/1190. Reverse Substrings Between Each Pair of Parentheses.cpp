https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/



class Solution 
{
public:
    string reverseParentheses(string s) 
    {
        stack<string>stk;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                stk.push("");
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                if(stk.empty())
                {
                    string tmp="";
                    tmp.push_back(s[i]);
                    stk.push(tmp);
                }
                else
                {
                    stk.top().push_back(s[i]);
                }
            }
            else if(s[i]==')')
            {
                string tmp=stk.top();
                stk.pop();
                reverse(tmp.begin(),tmp.end());
                if(stk.empty())
                {
                    stk.push(tmp);
                }
                else
                {
                    stk.top()+=tmp;
                }
            }
        }
        return stk.top();
    }
};
