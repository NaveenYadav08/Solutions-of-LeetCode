https://leetcode.com/problems/word-break-ii/

class Solution {
public:
vector<string> sentences;

void dfs(string s, string sentence, unordered_set<string>& setting)
{
    if(s.empty())
    {
        sentence.pop_back();
        sentences.push_back(sentence);
        return;
    }
    int n = s.size();
    for(int i = 1; i <= n; i++)
    {
        if(!setting.count(s.substr(0, i)))
            continue;
        dfs(s.substr(i), sentence + s.substr(0, i) + " ", setting);
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict)
{
    unordered_set<string> setting;
    setting.insert(wordDict.begin(), wordDict.end());
    dfs(s, "", setting);
    return sentences;
}


};
