https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    
            string mapping[10] = {"", "", "abc", "def",
                              "ghi", "jkl", "mno", 
                              "pqrs", "tuv", "wxyz"};
    
    void helper(vector<string> &ans, string tmp, int i, string &digits)
    {
        if(i==digits.size())
        {
            ans.push_back(tmp);
            return;
        }
        
        if(i>digits.size()) return;
        
        for(int j=0; j<mapping[digits[i]-'0'].size(); j++)
        {
            helper(ans,tmp+mapping[digits[i]-'0'][j], i+1, digits);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        
        string tmp="";
        int i=0;
        helper(ans, tmp, i, digits);
        return ans;
        
        
    }
};
