https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxL=0;
        for(int i=0;i<s.size();i++)
        {
            int t=stk.top();
            if(t!=-1&&s[i]==')'&&s[t]=='(')
            {
                stk.pop();
                maxL=max(maxL,i-stk.top());
            }
            else
                stk.push(i);
        }
        return maxL;
    }
};


https://www.youtube.com/watch?v=VdQuwtEd10M&t=495s

https://github.com/Algorithms-Made-Easy/Leetcode-Challenge/blob/main/32.%20Longest%20Valid%20Parentheses
