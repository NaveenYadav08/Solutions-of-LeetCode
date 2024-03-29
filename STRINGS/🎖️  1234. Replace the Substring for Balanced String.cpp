// link - https://leetcode.com/problems/replace-the-substring-for-balanced-string/

// sliding window and hahsmap

// code

class Solution {
public:
   int balancedString(string s) {
       int n=s.size();
       unordered_map<char,int>count;    // Used to count the repeatition of a character
       for(int i=0;i<n;i++)
       {
           count[s[i]]++;               // Increment count
       }
       int l=0;       
       int i=0;
       
       int window=n;   // The window we need to replace ,and we want to search for
                       // a minimum window there
       int m=n/4;    
       
       while(i<n)
       {
           count[s[i]]--;
           // if is ek len ki window ke bahar sb ki freq is balanced 
           // means isi window mae excess bhrari hea
           while(count['Q']<=m && count['W']<=m && count['E']<=m && count['R']<=m)
           {   // then minimize size of that window 
               count[s[l]]++;
               window=min(window,i-l+1);    // Update window size 
               l++;                         // remove l'th character from window
               
               if(l>=n)                     // If it reaches to n simply back of
                   break;
           }
           i++;
       }
       return window;
   }
};

