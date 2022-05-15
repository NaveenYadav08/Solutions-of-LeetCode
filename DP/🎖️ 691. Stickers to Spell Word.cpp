// LINK  https://leetcode.com/problems/stickers-to-spell-word/

// CODE 

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
       
        int n = target.size(); 
        // mapping all char of target done or not done
        
        vector<uint> dp(1 << n, -1); 
        dp[0] = 0; 
        for (int mask = 0; mask < (1 << n); ++mask) // trying all mask
            
            if (dp[mask] != -1) 
                // traverse all the stickers 
                for (auto& sticker : stickers) {
                    
                    int mask0 = mask; 
                    // taking prev mask 
                    
                    for (auto& ch : sticker) // us sticker ke saare char ko dekha mene
                        for (int j = 0; j < n; ++j) 
                                      // all char liae and all the char of our target liae
                            
                            if (ch == target[j] && (mask0 & (1<<j)) == 0) {
                                
                                mask0 ^= 1 << j; 
                                break; 
                            }
                    
                    dp[mask0] = min(dp[mask0], 1 + dp[mask]);
                }
        
        return dp.back(); 
    }
};
