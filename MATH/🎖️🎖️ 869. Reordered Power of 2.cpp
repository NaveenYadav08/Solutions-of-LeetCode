https://leetcode.com/problems/reordered-power-of-2/


class Solution {
public:
bool reorderedPowerOf2(int n) {
     
    // storing all powers of 2 in map
        unordered_set<string> set1;
        for(int i=0;i<32;i++)
        {
            int n=1<<i;
            // generating all power of two sorting that sting no 
            // storing in map 
            string str=to_string(n);
            sort(str.begin(),str.end());
            set1.insert(str);
        }
        
        string str2=to_string(n);
   
        sort(str2.begin(),str2.end());
        if(set1.find(str2)!=set1.end())
            return true;
        else
            return false;
        
    }
};
