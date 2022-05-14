// LINK  https://leetcode.com/problems/longest-string-chain/

// CODE

class Solution {
private:
    static bool compare(string &s1, string &s2){
        return s1.size() < s2.size();
    }

    bool possible(string &s1, string &s2){
        if(s1.size() != 1+s2.size())    return false;
        int first = 0, second = 0;
        while(first < s1.size()){
            if(s1[first] == s2[second]) first++, second++;
            else    first++;
        }

        return (first == s1.size() && second == s2.size());
    }

public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), compare);
        int maxi = 1;
        int n = words.size();
        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                // words[i] predecessor of words[j]
                if(possible(words[i], words[j]))
                    dp[i] = max(dp[i], 1+dp[j]);
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
