https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/


1178. Number of Valid Words for Each Puzzle


class Solution {
public:
    int maskWord(string word) {
        int mask = 0;
        for (auto c : word) mask |= (1 << c-'a');
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mask_freq;
        for (auto word : words) mask_freq[(maskWord(word))]++;
        
        vector<int> res;
        
        for (auto p : puzzles) {
            int mask = maskWord(p), submask = mask, first = (1 << p[0]-'a'), curr = 0;
            
            while (submask) {
                if (submask & first) curr += mask_freq[submask];
                
                submask = (submask-1) & mask;
            }
            
            res.push_back(curr);
        }
        return res;
    }
};
