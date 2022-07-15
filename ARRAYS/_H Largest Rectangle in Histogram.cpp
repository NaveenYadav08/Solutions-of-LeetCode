Leetcode - https://leetcode.com/problems/largest-rectangle-in-histogram/

CODE - 

class Solution {
public:
    int largestRectangleArea(vector<int>& hist ) {
        
        int n = hist.size();stack<int> s;
        int max_area = 0;
        int tp;
        int awt;
        int i=0;
        while(i<n)
        {
           if(s.empty() or hist[s.top()]<=hist[i] )
               s.push(i++);
            else
            {
                tp = s.top();
                s.pop();
                awt = hist[tp]*(s.empty()?i:(i-s.top()-1));
                max_area= max(max_area,awt);
                
            }
        }
        
        while(s.empty()==false)
        {
             tp = s.top();
                s.pop();
                awt = hist[tp]*(s.empty()?i:(i-s.top()-1));
                max_area= max(max_area,awt);
                
        }
        
        return max_area;
        
        
    }
};
