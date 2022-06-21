// https://youtu.be/4OL7WdGKC1Y
// 600. Non-negative Integers without Consecutive Ones
// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/

// fibonacci f[3] means n cons ones in bit represtation of length 3

// now for x = 150 BITS = 10010110 , 8 bits here 
// so MSB 8 = F( 7 ) = so it is all ans of 7 bit length and making 8th bit as 0 
// next msb at 5 = F( 4 ) = mmaing 8th bit as 1 and all ans of length 4 making the 5th bit as 0 
// Why it is so bcz at each time I have to make some bit 0 bcz it not done so I may get ans >= x 
// now for MSB( 3 ) = F ( 2 ) = making 8th bit as set and All ans of len 2 making 3rd bit as 0 
// now for MSB( 2 ) = F( 1 ) =  making 8th bit as 1 and ALL ans of len 1 making 2nd bit as 0 , 
// as prev bit is 1 so return ans





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
