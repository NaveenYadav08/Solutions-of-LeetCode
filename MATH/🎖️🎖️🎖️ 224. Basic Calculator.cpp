https://leetcode.com/problems/basic-calculator/




class Solution {
public:
    
    int calculate(string s) {
        //we basically calculate everything at a time and update it in result varibale
        int result=0;
        
        int sign=1; //1 represents +ve -1 represents -ve
       
        int j=0;
        int len=s.length();
        
        stack<int> stk;
        
        while(j<len){ 
            if(s[j]=='+')
            {
                sign=1;
            }
            else if(s[j]=='-')
            {
                //we got a negative value
                sign=-1;
            }
            
            else if(isdigit(s[j]))
            {
                //get the number 
                int num=s[j]-'0';
                while(j+1<len && isdigit(s[j+1])){
                    num=num*10+(s[j+1]-'0');
                    j++;
                }
                //now add it to the result along with sign
                result+=num*sign;
            }
            else if(s[j]=='(')
            {
                //we push the current result and current sign into the stack
                stk.push(result);
                stk.push(sign);
                result=0;
                sign=1;
            }
            else if(s[j]==')')
            {
                //get the last result and the sign from the stack
                int xsign=stk.top();
                stk.pop();
                int xresult=stk.top();
                stk.pop();
                //add the curr result in parenthesis to prev result and update the entire result
                result=result*xsign + xresult;
                //xsign will be the sign before the begin of parenthesis
            }
            j++;
        }
        
        
        return result;
    }
};
