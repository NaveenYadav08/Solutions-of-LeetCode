// LEETCODE - https://leetcode.com/problems/longest-palindrome/

// GFG 

class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(auto x:s){
            mp[x]++;
        }
        int sum=0;
        for(auto x:mp){
            if(x.second%2==0){
                sum+=x.second;
            }
            else{
                sum+=x.second-1;
            }
        }
        sum++;
        return min(sum,n);
    }
};
