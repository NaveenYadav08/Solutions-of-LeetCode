https://leetcode.com/problems/longest-duplicate-substring/

#define ull unsigned long long 

string ans="";

string duplicate(int l,string &s){
    if(l==0)
        return "";
    
    int d=131;
    unordered_map<ull,int>val;
	// using map to store the hash_codes of visited strings
	
	// Eg. hash_code for substring of length 5 from 0 to 4 is calculated as: s[4]+s[3]*d+s[2]*d^2+s[1]*d^3+s[0]*d^4
    
	// We can use this hash_code to calculate hash-code for next substring from 1 to 5 as: (hash_code*d)-(s[0]*d^5)+s[5]
	
    ull curr_hash=0,power=1;
    for(int i=0;i<l;i++){ 
        curr_hash=((curr_hash*d)+s[i]);
        power*=d;
    }
	
    val[curr_hash]++;
    
    for(int i=l;i<s.size();i++){
        curr_hash=((curr_hash*d)-(power*s[i-l])+s[i]);
		// generating new hash_code for current string
		
        if(val.find(curr_hash)!=val.end())
            return s.substr(i-l+1,l);
		// if current hash_code is present in map then it indicates that same substring has been visited previously hence returning the substring
		
        val[curr_hash]++;
		// storing hash_code to mark substring as visited
    }
    
    return "";
}

// using binary search to check wheather substring of "mid_len" length is duplicate or not

void binary_search(int mn_len, int mx_len, string &s){
    if(mn_len>mx_len)
        return;
    int mid_len=mn_len+(mx_len-mn_len)/2;
    
    string temp=duplicate(mid_len,s);
        if(temp!="")
            ans=temp,mn_len=mid_len+1;
        else
            mx_len=mid_len-1;
    binary_search(mn_len,mx_len,s);
}

string longestDupSubstring(string s) {
    int n=s.size();
    binary_search(1,n,s);
    return ans;
}
