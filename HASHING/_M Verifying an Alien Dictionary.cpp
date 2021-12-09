// LEETCODE https://leetcode.com/problems/verifying-an-alien-dictionary/

// WAY 1 , relative order and copy array and check if sorted and original array equal or not 
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        vector<string> W = words;
        
        unordered_map<char,char> m;
        unordered_map<char,char> M;
        for(int i=0;i<26;i++)
        {
            m[order[i]] = 'a'+i;   
        }
        
        for(int i=0;i<26;i++)
        {
            M['a'+i] = order[i];   
        }
        
    
        
        for(auto &x:W)
        {   cout<<x<<endl;
            for(int i=0;i<x.size();i++)
            {
                char y = x[i];
                x[i]=m[y];
                cout<<y<<" "<<m[y]<<endl;
            }
            cout<<x<<endl;
        }
        

        
        sort(W.begin(),W.end());
        
        for(auto &x:W)
        {
            for(int i=0;i<x.size();i++)
            {
                char y = x[i];
                x[i]=M[y];
                cout<<y<<" "<<M[y]<<endl;
            }
            cout<<x<<endl;
        }
        

        
        if(W==words)
            return true;
        else
            return false;
        
        
    }
};



// WAY 2 
// BETTER WAY 

// We will store the relative ranking of the letters in the array rank using the string order.
// Lower the rank the better it is for that letter.
// Next we compare the adjacent words to see if they violate the new ranking system or not.
// Once we find a wrong ordering, we return false or return true.

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank (26,0);
        for(int i=0;i<order.size();i++)
        {
            rank[order[i]-'a']=i;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            int j=0,k=0; bool flag=false;
            for(;j<words[i].size() && k<words[i+1].size();j++,k++)
            {
                if(rank[words[i][j] -'a'] < rank[words[i+1][k] -'a'])
                {
                    flag=true;
                    break;
                }
                else if(rank[words[i][j] -'a'] > rank[words[i+1][k] -'a'])
                    return false;
            }
            if(!flag && words[i].size() > words[i+1].size())
                return false;
        }
        return true;
    }
};
