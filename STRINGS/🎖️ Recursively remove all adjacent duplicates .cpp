// QUES - https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1

// ITERATIVE CODE 
class Solution{
public:
    string rremove(string s){
        // code here
        while(1)
        {
            string temp;
            int i=0,n=s.size();
            while(i<n)
            {
                int j=i+1;
                while(j<n and s[j]==s[i]) j++;
                if(j==i+1) temp+=s[i];
                i=j;
                
            }
            if(s==temp) break;
            s=temp;
        }
        return s;
    }
};


// RECURSIVE CODE 
class Solution{
public:
void helper(string &s)
{ 
            string temp;
            int i=0,n=s.size();
            while(i<n)
            {
                int j=i+1;
                while(j<n and s[j]==s[i]) j++;
                if(j==i+1) temp+=s[i];
                i=j;
                
            }
            if(s==temp) return;
            s=temp;
            helper(s);
            
            
}

    string rremove(string s){
        // code here
        helper(s);
        return s;
    }
};
