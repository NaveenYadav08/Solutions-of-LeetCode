// GFG - https://practice.geeksforgeeks.org/problems/check-frequencies4211/1

// CODE 


class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char,int> m;
	    unordered_map<int,int> M;
	    
	    for(auto x:s)
	    m[x]++;
	    
	    
	    for(auto x:m)
	    {
	        M[x.second]++;
	    }
	    
	    
	    if(M.size()==1)
	    return true;
	    
	    
	    vector<pair<int,int>> v;
	    if(M.size()==2)
	    {
	        for( auto x:M )
	        {
	            v.push_back({x.first,x.second});
	        }
	        
	        auto p1=v[0];
	        auto p2=v[1];
	        pair<int,int> p3 = {1,1};
	        
	        if(p1==p3 or p2==p3)
	        return true;
	        
	        int diff = abs(p1.first-p2.first);
	        if(diff==1 and (p1.second==1 or p2.second==1))
	        return true;
	        
	         
	    }

	    
	    
	    
	    

	    
	    return false;
	}
};
