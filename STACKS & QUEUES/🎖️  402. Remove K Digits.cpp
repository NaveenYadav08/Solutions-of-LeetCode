// https://www.youtube.com/watch?v=3QJzHqNAEXs

// https://leetcode.com/problems/remove-k-digits/



class Solution {
public:
    string removeKdigits(string num, int k) {
        
        //maintain an increasing sequence of characters
        string stack;
        
        for(int i=0;i<num.size();i++){
            //if the current digit is greater than the stack top
            //we will pop the stack till either the stack top becomes 
            //less than or equal to the current digit or we have removed k
            //digits
            
            while(stack.size() and stack.back()>num[i] and k>0){
                stack.pop_back();
                k--;
            }
            
            stack.push_back(num[i]);
        }
        
        //if any digits have to be removed, remove them from the back as they
        //are the largest ones
        if(k!=0){
            while(k!=0){
                stack.pop_back();
                k--;
            }
        }
        
        
        
        //remove the leading zeroes
        int nonZero=-1;
        for(int i=0;i<stack.size();i++){
            if(stack[i]!='0'){
                nonZero=i;
                break;
            }
        }
        
        
        
        if(nonZero==-1){
            return "0";
        } else {
            return stack.substr(nonZero,stack.size()-nonZero);
        }
    }
};
