// https://leetcode.com/problems/repeated-string-match/description/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        int n = b.size() / a.size();
        int N=n;

        string j="";
        while(n--)
        {
           j+=a;
        }
        
        auto found = j.find(b);
        if(found != string::npos) return N;
        j+=a;
        auto FOUND = j.find(b);
        if(FOUND != string::npos) return N+1;  //  8/3 
        j+=a;
        auto Found = j.find(b);
        if(Found != string::npos) return N+2;
        // spans from the last character of the first repetition, 
        
        return -1;
    }
};
