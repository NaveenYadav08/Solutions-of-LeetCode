// https://leetcode.com/problems/special-binary-string/discuss/1241027/C%2B%2B-code-detailed-explanation-and-thought-process-with-example-and-pictures.

// Think of 1's as "(" and 0's as ")". Then the problem will become finding the lexigraphically largest string.
// There are two forms of strings:
// a. "()(())": the string can be separated into two sub strings, "()" and "(())". We just need to reorganize the two substrings to produce the result: "(())()".
// b. "(()(()))": this string is the string is case (a) with a parenthesis on the outside. to produce the result string, 
we need to first look at the inside string "()(())", and produce its result "(())()", then put it inside the large parenthesis to make result "((())())".
// From the two cases, we can see that case (a) is a subproblem of case (b). In fact, all inputs are valid, 
we can ignore the inside of case (b) and see it as "(M)", where M is "()(())". We can then think of "(M)" as a substring itself.
// Note that each substring will be in the form ”(something here)" or empty because they would have balanced parentheses.
// Therefore, the logic for solving the problem goes as follows:
// find the highest level substrings in the input. Now each substring would be in the form "(something)". We can use counters of 1's and 0's to find each substring. 
We use two pointers to keep track of the beginning and end of each string
// when we find a substring, take its inside and make sure the inside is lexigraphically largest. We can recursively call the function itself on the inside part. 
Then we store the transformed result for this substring in a list.
// After storing all the transformed results of the substrings, sort them lexigraphically and join them together. Then return the result.

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> res;
        int i = 0, level = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1') level++;
            else level--;
            if (level == 0) {
                res.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - (i + 1))) + '0');
                i = j + 1;
            }
            
        }

        sort(res.begin(), res.end(), greater<string>());
        string ret = "";
        for (string& s : res) {
            ret += s;
        }

        return ret;
    }
};
