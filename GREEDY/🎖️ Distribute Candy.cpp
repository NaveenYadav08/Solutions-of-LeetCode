https://www.interviewbit.com/problems/distribute-candy/
https://leetcode.com/problems/candy/


class Solution {
public:
    int candy(vector<int>& ratings) {
      int len = ratings.size();
      vector<int>L2R(len, 1);
      vector<int>R2L(len, 1);
      
      for(int i=1; i<len; i++)
        if(ratings[i] > ratings[i-1])
          L2R[i] = L2R[i-1]+1;
      
      for(int i=len-2; i>=0; i--)
        if(ratings[i] > ratings[i+1])
          R2L[i] = R2L[i+1]+1;
        
      int ans = 0;
      for(int i=0; i<len; i++)
        ans += max(L2R[i], R2L[i]);
      return ans;
    }
};
