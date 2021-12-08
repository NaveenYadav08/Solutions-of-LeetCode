// LEETCODE _ https://leetcode.com/problems/longest-repeating-character-replacement/

// SLIDING WINDOW 

//CODE
class Solution {
    
    /*
    
    ALGO:------
    
    
       1:- take a vector for count the frequncy of the char
       
       2:- run a loop from 0 to n {
       
         A:-   increase the frequncy of each char in the vector by v[s[j]-'A']++; this;
            
          B:- then check if the highest frequency -window size is greater than k
          that means one extra char that is diffrent and we dont have k to change 
          
          C:- now decrease the frequency and increase the i
          
          D:- and every time count the size of the window..
       }
       
       
       
       DRY RUN...........
       
       for example :-   s = "AABABBA", k = 1
       
      for j=0,,,,,, v=[1,0,0,0,0,0,0,0,0,.....]  window size=1
      
      for j=1,,,,,, v=[2,0,0,0,0,0,0,0,0,.....]  window size=2
      
      for j=2,,,,,, v=[2,1,0,0,0,0,0,0,0,.....]  window size=3
      
      for j=3,,,,,, v=[3,1,0,0,0,0,0,0,0,.....]  window size=4
      
      for j=4,,,,,, v=[3,2,0,0,0,0,0,0,0,.....]  window size=5
      
      now (window size-highest frequency){ 5-3 which is >k}
      {
        so increase i..
      
        for j=4,,,,,, v=[2,2,0,0,0,0,0,0,0,.....]  window size=4
        
         for j=4,,,,,, v=[1,2,0,0,0,0,0,0,0,.....]  window size=3
         
       }  
        for j=5,,,,,, v=[1,3,0,0,0,0,0,0,0,.....]  window size=4
    */
public:
    int characterReplacement(string s, int k) {
        
        int i=0;
       
        vector<int>v(26,0);
        
        int ans=INT_MIN;
        
       for(int j=0;j<s.size();j++)
        {
            v[s[j]-'A']++;
           
            while(j-i+1-*max_element(v.begin(),v.end())>k)
            {
                v[s[i]-'A']--;
                
                i++;
            }
           
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
