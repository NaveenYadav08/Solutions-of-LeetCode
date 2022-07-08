https://leetcode.com/problems/spiral-matrix-iii/


class Solution {
public:
    
    bool isValid(int r, int c, int R, int C)
    {
        if(r>=0 and c>=0 and r<R and c<C) return 1;
        return 0;
    }
    
    
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        
        int mul = 1;
        int R=rStart, C=cStart;
        vector<vector<int>> ans;
        vector<int> t;
        t.push_back(rStart);
        t.push_back(cStart);
        ans.push_back(t);
        
        int count=1;
        bool flag=true;
        
        while(count!=rows*cols)
        {
            vector<int> tmp;
            int t=mul;
            while(t and count!=rows*cols)
            {
                t--;
                if(flag)
                {
                    C++;
                }
                else
                    C--;
                
                if(isValid(R,C, rows, cols))
                {
                    tmp.push_back(R);
                    tmp.push_back(C);
                    ans.push_back(tmp);
                    tmp.clear();
                    count++;
                }
                else if(count==rows*cols)
                    return ans;
                
                    
            }
            
            t=mul;
            while(t and count!=rows*cols)
            {
                t--;
                if(flag)
                {
                    R++;
                }
                else
                    R--;
                
                if(isValid(R,C, rows, cols))
                {
                    tmp.push_back(R);
                    tmp.push_back(C);
                    ans.push_back(tmp);
                    tmp.clear();
                    count++;
                }
                else if(count==rows*cols)
                    return ans;
                
                    
            }
            
            mul++;
            flag=!flag;
            
            
            
            
        }
        return ans;
        
    }
};
