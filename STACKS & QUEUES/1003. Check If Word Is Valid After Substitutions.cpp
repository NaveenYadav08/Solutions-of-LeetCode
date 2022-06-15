https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(c=='c' && st.size()>1){
                if(st.top()=='b') st.pop();
                else return false;
                if(st.top()=='a') st.pop();
                else return false;
            }
            else st.push(c);
        }
        return st.empty();
    }
};
