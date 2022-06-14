https://leetcode.com/problems/remove-outermost-parentheses/



class Solution {
public:
string removeOuterParentheses(string s) {
// replace inner ( with other  char
    string res;
    
    stack<char>st; 
    
    int count = 0;
    
    for(int i =0; i<s.size(); i++){
        
        if(st.empty() and s[i]=='('){
            st.push('(');
        }
        
        else if(s[i] == '(' && (!st.empty())){
            res.push_back(s[i]); st.push('a');
        }
        
        else if(s[i] == ')' && st.top() == 'a'){
            res.push_back(s[i]); st.pop();
        }
        
        else if(s[i] == ')' && st.top() == '('){
            st.pop();
        }
    }
    
    
    
    return res;
    
}
};
