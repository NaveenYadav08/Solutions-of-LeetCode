// LINK https://leetcode.com/problems/counting-bits/

// CODE

class Solution {
public:
    vector<int> countBits(int n) {
      vector<int> res;
      res.push_back(0);
      for (int i = 1; i <= n; i++) {  
          // the dffrence between i and i-1 is that after least signifact bit all part is same 
          // in i-1 and i all bits are flipped from lsb to 0th bit 
        res.push_back(res[i&(i-1)] + 1);
      }
      return res;        
    }
};
