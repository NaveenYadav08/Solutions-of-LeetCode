// Stack sae hoga 


// link https://leetcode.com/problems/basic-calculator-ii/

// code 

class Solution {
public:
    int calculate(string S) {
        
        string s="";
        
        for(int i=0;i<S.size();i++)
        {
            if(S[i]==' ')
                continue;
            else
                s+=S[i];
        }
        
        //cout<<s<<endl;
        // copied all the thing into new string without spaces
        
        // used a stack 
        
        
        stack<int> st;
        
        for(int i=0;i<s.size(); i++)
        { // if  no found 
            if(s[i]>='0' and s[i]<='9') 
            {
                string stemp="";
                stemp+=s[i];
                
                i++;
                // tab tk add kro jab tk number aa rhe ahe
                
                while(i<s.size() and s[i]>='0' and s[i]<='9')
                {
                    stemp+=s[i++];
                }
                i--;
                // toko store int form of string 
                // ans push that number in the stack
                
                int toko = stoi(stemp);
                st.push(toko);
                
            }
            
            // if - ya + aaya to 
            else if(s[i]=='-')
            {
              i++;
             string stemp="";
                
             while(s[i]>='0' and s[i]<='9' and i<s.size()) 
            {
                
                stemp+=s[i];
                i++; 
            }
                
                i--;
                int toko = stoi(stemp);
                toko = toko*(-1);
                st.push(toko);
                
                
            }
            
            //  so basically i put all + and - in stack 
            // add them , here I am computing only * and /
            
            
            // agr - dikha to no ka negative daal dia
            // agr + dia to wo no hi daal dia 
            // agr * ya / dikha to usse agla no or stack kae top ko 
            // computre krke satck me daal dia
            
            else if(s[i]!='+')
            { char ch = s[i];
              i++;
             
             if(s[i]>='0' and s[i]<='9' and i<s.size()) 
            {
                string stemp="";
                stemp+=s[i];
                
                i++;
                while(i<s.size() and s[i]>='0' and s[i]<='9')
                {
                    stemp+=s[i++];
                }
                i--;
                 
                int toko = stoi(stemp);
                
                 int moko = st.top(); st.pop();
                 int jomo;
                 if(ch=='*')
                 {
                     jomo=toko*moko;
                 }
                 else if(ch=='/')
                 {
                     jomo=moko/toko;
                 }
                 st.push(jomo); 
            }
              
               
            }
            
            
        }
        
        
        
        
        int ans = 0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        return ans;
        
    }
};
