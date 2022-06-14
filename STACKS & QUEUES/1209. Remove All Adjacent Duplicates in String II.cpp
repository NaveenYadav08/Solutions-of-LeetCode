// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/








class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> stk; 
        for(int i = 0 ; i<n; ++i){
	        // first of a character
            if(stk.empty() || stk.top().first != s[i]){
                stk.push({s[i], 1}); 
            }
            // repeated character
            else if(stk.top().first == s[i]){
                auto top = stk.top(); 
                stk.pop(); 
                stk.push({top.first, top.second+1}); 
            }
            // if after inserting the character the frequency becomes k 
            // pop the stack
            if(stk.top().second == k)
                stk.pop(); 
        }
        string ans; 
        // fill answer according to the frequency of various characters
        while(!stk.empty()){
            auto top = stk.top(); 
            for(int i = 0; i<top.second; ++i)
                ans += top.first; 
            stk.pop(); 
        }
        // reverse the string to get the answer
        reverse(ans.begin(), ans.end()); 
        return ans; 
    }
};
