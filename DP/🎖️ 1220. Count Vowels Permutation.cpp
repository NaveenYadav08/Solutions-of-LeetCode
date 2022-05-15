// LINK https://leetcode.com/problems/count-vowels-permutation/

// CODE 

class Solution {

  private: unordered_map<string,long> mp;
  private: int MOD = 1000000007;

  public:
    int countVowelPermutation(int n) {
    long total = 0;
    char charSet[] = {'a','e','i','o','u'};
        // starting with each char
    for(char c : charSet) {
      total = (total + helper(n-1,c)) % MOD;
    }
    return (int)total;
  }

  public:
    long helper(int remaingChar, char prevChar) {
    if(remaingChar == 0) return 1;
    string key = "" + to_string(remaingChar) + to_string(prevChar);
    if(mp.count(key)) return mp[key];
    long total = 0;
        // rules as given
    switch(prevChar) {
      case 'a': total = (helper(remaingChar - 1,'e')) % MOD;
        break;
      case 'e': total = (helper(remaingChar - 1,'a') + helper(remaingChar - 1, 'i')) % MOD;
        break;
      case 'i': total = (helper(remaingChar - 1,'a') + helper(remaingChar - 1, 'e') + helper(remaingChar - 1, 'o') + helper(remaingChar - 1, 'u')) % MOD;
        break;
      case 'o': total = (helper(remaingChar - 1,'i') + helper(remaingChar - 1,'u')) % MOD;
        break;
      case 'u': total = (helper(remaingChar - 1,'a')) % MOD;
        break;
    }
    mp[key]= total;
    return total;
  }
};

//https://www.youtube.com/watch?v=so4zgmaKO9w&t=54s
