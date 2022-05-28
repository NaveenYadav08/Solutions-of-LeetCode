https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/


1178. Number of Valid Words for Each Puzzle







//  THE SOLN GIVE IN PICTURE WILL GIVE TLE 


// Firstly we calculate frequency of different masks from all words storing them in unordered_map. 
//We remove duplicate characters from each word and calculate its corresponding mask and increase its frequency.
// What mask here means is- Eg, word=abdaa, set of characters=abd, its mask is 1011=11(decimal) set bits are for a,b and d.

// After that for each word in puzzle we calculate all its different masks which contains first character always, 
//so these would be total 2^6 different masks(for each character either include it or not). 
// Calcsubset funtion is used for this purpose.
// Then we iterate through 64 masks of each word in puzzle and for each mask add its corresponding frequency 
//by looking into our hash table and finally store it in our answer vector.
// I hope it's all clear now.

class Solution {
public:
    void calcsubset(string s,vector<int> &tp){
        int bit=s[0]-'a';
        int mask=1<<bit;
        tp.push_back(mask);
        for(int i=1;i<7;i++){
            int sz=tp.size();
            for(int j=0;j<sz;j++){
                mask=tp[j];
                bit=s[i]-'a';
                mask=mask | (1<<bit);
                tp.push_back(mask);
            }
        }
    }
	
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzz) {
        unordered_map<int,int> m;
        int n=words.size();
        for(int i=0;i<n;i++){
            int mask=0;
            for(char c:words[i]){
                int bit=c-'a';
                mask=mask | (1<<bit);
            }
            m[mask]++;
        }
		
        int psz=puzz.size();
        vector<int> ans(psz);
        for(int i=0;i<psz;i++){
            vector<int> tp;
            calcsubset(puzz[i],tp);
            int ct=0;
            for(int j=0;j<tp.size();j++){
                if(m.find(tp[j])!=m.end()) ct+=m[tp[j]];
            }
            ans[i]=ct;
        }
        return ans;
    }
};
