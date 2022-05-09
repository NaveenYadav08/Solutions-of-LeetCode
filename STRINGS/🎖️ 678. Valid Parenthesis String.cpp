// LINK https://leetcode.com/problems/valid-parenthesis-string/

// VIDEO https://www.youtube.com/watch?v=KuE_Cn3xhxI

// CODE 

class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> open,star;
        int len = s.length();
        
        // I took two stacks 
       //  * ( // it is an invalid case 
        
        // I push position of star in star stack and 
// ( position in open stack & pop from it when close bracket seen
        
        for(int i=0;s[i]!='\0';++i)
        {
            if(s[i]=='(')
                open.push(i);
            else if(s[i]=='*')
                star.push(i);
            else
            {
                if(!open.empty())
                    open.pop();
                
                // if there is no thing in open we look for stars
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        
        //Now process leftover opening brackets
        // we will not take step of if only star left bcz they will thn bcm empty string 
        while(!open.empty())
        {
            if(star.empty())
                return false;
            
            else if(open.top() < star.top())
            {
                open.pop();
                star.pop();
            }
            else    //CASE: open.top() > star.top()  * C case invalid 
                return false;
        }
        
        return true;
    }
};


// constant space O ( 1 ) space 

// code 
class Solution {
public:
    bool checkValidString(string s) {
        
        int ext = 0, cnt = 0; // ext star and cnt bracket
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i]=='(')
                cnt++;
            
            else if(s[i] == '*')
                ext++;
            
            else
            {
                cnt--;
               //  more close bracket  and stars cant compensate them 
                if(cnt < 0 && (cnt + ext) < 0)
                    return false;
            }
        }
        
        
        cnt = 0;
        ext = 0;
        for(int i = s.length()-1;i >= 0; i--)
        {
            if(s[i]==')')
                cnt++;
            else if(s[i] == '*')
                ext++;
            else
            {
                cnt--;
                if(cnt < 0 && (cnt + ext) < 0)
                    return false;
            }
        }
        return true;
    }
};
