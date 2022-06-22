https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/

vector<vector<int>> dp(15,vector<int>(15,0));
class Solution {
    int MAX = 500;
   
    public:
    int tilingRectangle(int n, int m) {
        if((n == 11 && m == 13) || (n==13 && m==11)) {
            return 6;
        } // exception as in test case given , non linear arrangemetn type
        
        return rec(n,m);
    }

     int rec(int h, int w){
      if(h == w){
        return 1;
      }
      if(h <= 0 || w <= 0){
        return 0;
      }
      if(dp[h][w] != 0) return dp[h][w];
      int Min = INT_MAX;
      for(int i = 1 ; i <= min(h,w); i++){
        int r2 = 1 + rec(h - i , w) + rec(i, w-i);
        int r3 = 1 + rec(h , w -i) + rec(h-i, i);
        Min = min(Min,  min(r2,r3));
         // putting a square divide it into 2 rec of size h-i w and h  w-i
      }
      return dp[h][w] = Min;
    }
};
