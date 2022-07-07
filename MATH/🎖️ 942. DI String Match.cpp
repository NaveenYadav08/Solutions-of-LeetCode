https://leetcode.com/problems/di-string-match/


// We track high (h = N - 1) and low (l = 0) numbers within [0 ... N - 1]. 
//When we encounter 'I', we insert the current low number and increase it. With 'D', we insert the current high number and decrease it. 
//In the end, h == l, so we insert that last number to complete the premutation

class Solution {
public:
vector<int> diStringMatch(string S) {
    vector<int> res;
    for (int l = 0, h = S.size(), i = 0; i <= S.size(); ++i)
        res.push_back(i == S.size() || S[i] == 'I' ? l++ : h--);
    return res;
}
};
