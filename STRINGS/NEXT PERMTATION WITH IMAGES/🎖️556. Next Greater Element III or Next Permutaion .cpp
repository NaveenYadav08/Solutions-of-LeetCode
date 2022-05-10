// https://leetcode.com/problems/next-greater-element-iii/


//code

class Solution {
public:
    int nextGreaterElement(int n) {
        
        string str = to_string(n);
        int i = str.size()-2;
        while(i>=0 and str[i]>=str[i+1])
        {
            i--;   
        }
        
        if(i<0)
            return -1;
        
        int j=str.size()-1;
        while(str[j]<=str[i])
        {
            j--;
        }
        
        swap(str[j],str[i]);
        
        reverse(str.begin()+i+1,str.end());
        
        long long nn=0;
        for(int I=0; I<str.size(); I++)
        {
            if( (nn*10 + (str[I]-'0')) > INT_MAX )
                return -1;
            else
                nn = nn*10 + (str[I]-'0');
            
        }
        return (int)nn;
        
    }
};
