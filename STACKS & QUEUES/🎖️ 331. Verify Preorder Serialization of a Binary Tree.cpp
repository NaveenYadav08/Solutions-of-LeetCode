// https://www.youtube.com/watch?v=RzNYwhSQjHQ

// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

// 


class Solution {
public:
    vector<string> charary;
    bool isValidSerialization(string preorder) {
       split(preorder);
       int diff=1;
       for(string pre: charary){
           if(--diff<0) return false;
           if(pre!="#") diff+=2;
       }
        return diff==0;
    }
    
    void split(string s) {
        string S="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=',')
                S+=s[i];
            else
            {
                charary.push_back(S);
                S="";
            }
                

        }
        charary.push_back(S);
    }
    
};
