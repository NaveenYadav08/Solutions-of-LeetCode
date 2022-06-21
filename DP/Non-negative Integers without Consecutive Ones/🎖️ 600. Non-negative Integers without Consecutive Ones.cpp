// https://youtu.be/4OL7WdGKC1Y
// 600. Non-negative Integers without Consecutive Ones
// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/


class Solution {
  public:
  int findIntegers(int n) {
    int f[31];
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i < 31; ++i)
      f[i] = f[i-1]+f[i-2];

    int ans = 0, k = 30, pre_bit = 0;
    while (k >= 0) { // mving msb to lsb
      if (n&(1<<k)) { 
          cout<<k<<endl;// if set
        ans += f[k]; // ans += f[k]
        //cout<<ans<<endl;
        if (pre_bit) return ans; // if prev bit 1 curr bhi 1 abort krdo
        pre_bit = 1;
      }else {
        pre_bit = 0;
      }
      --k;
    }
    return ans+1;
  }
};
