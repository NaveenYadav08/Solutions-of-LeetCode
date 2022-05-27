https://leetcode.com/problems/convert-a-number-to-hexadecimal/

class Solution {
public:
    string toHex(int num) {
        unsigned int x = num;
        string ans;
        string hexaDec = "0123456789abcdef";
        if (x==0){
        return "0";
        }
        while(x > 0){
            ans += hexaDec[x%16];
            x/=16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
