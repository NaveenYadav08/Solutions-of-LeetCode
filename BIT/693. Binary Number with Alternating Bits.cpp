https://leetcode.com/problems/binary-number-with-alternating-bits/

class Solution {
public:
bool hasAlternatingBits(int n) {
int a = n^(n>>1);
int count;
count = log2(a) + 1;
if(a ==pow(2,count)-1)
return true;
else return false;}
};
