// code 
// GFG https://practice.geeksforgeeks.org/problems/remove-duplicates3034/1

class Solution{
public:
	string removeDups(string s) 
	{ 
	    int j = 0;
	  
	    int fre[26] = {0};

	    for(int i = 0; i < s.size(); i++)
	    {
	    	if(fre[s[i] - 'a'] == 0)
	    		s[j++] = s[i];

	    	fre[s[i] - 'a'] = 1;
	    }
	    
	    return s.substr(0, j); 
	} 
   
};
