Leetcode - https://leetcode.com/problems/largest-rectangle-in-histogram/
https://www.youtube.com/watch?v=jC_cWLy7jSI
// one soln is left right smaller 3 pass soln
CODE - 

class Solution {
  public:
    int largestRectangleArea(vector < int > & histo) {
      stack < int > st;
      int maxA = 0;
      int n = histo.size();

      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()]; // find ans for element in stack
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1; // cur i the right lim and st.top is left limit
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }

      return maxA;
    }
};
