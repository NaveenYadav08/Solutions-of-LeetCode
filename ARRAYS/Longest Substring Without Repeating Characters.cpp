https://leetcode.com/problems/longest-substring-without-repeating-characters/

2 pointers

class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        int ANS = 0;
        int e = 0;
        int s = 0;
        int n = S.size();
        unordered_map<int,int> m;
        while(e<n)
        {
            char ch = S[e];
            m[ch]++;
            if(m[ch]==1)
            {
               ANS=max(ANS,e-s+1);
            }
            else
            {
                while(m[ch]!=1)
                {
                    m[S[s]]--;
                    s++;
                }
                ANS=max(ANS,e-s+1);
            }
            e++;
        }
        return ANS;
    }
};
