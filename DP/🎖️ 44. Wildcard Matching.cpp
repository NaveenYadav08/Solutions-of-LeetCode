https://leetcode.com/problems/wildcard-matching/


class Solution {
public:
bool isMatch(string s, string p) 
{
	vector<vector<int>> memo(s.size()+1, vector<int>(p.size()+1, -1));
	return isMatch(s, p, 0, 0, memo);
}

bool isMatch(string& s, string& p, int si, int pi,vector<vector<int>>& memo) 
{
	if (si == s.size() && pi == p.size()) return true;
	if (pi == p.size()) return false;
	if (memo[si][pi] != -1) return memo[si][pi];
    
	if (si < s.size() && (s[si] == p[pi] || p[pi] == '?')) 
        return memo[si][pi] = isMatch(s, p, si + 1, pi + 1, memo);

	for (int sii = si; p[pi] == '*' && sii <= s.size(); ++sii)
		if (isMatch(s, p, sii, pi + 1, memo)) return memo[si][pi] = true;

	return memo[si][pi] = false;
}
};
