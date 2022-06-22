https://leetcode.com/problems/letter-tile-possibilities/


class Solution {
    int ans=0;
public:
    
int numTilePossibilities(string tiles) {
        for(int i=1;i<=tiles.size();++i)
        { // FOR all possible lengths
            unordered_set<string> s;
            vector<bool> v(tiles.size(),0); // used or not
            string temp;
            solve(s,i,v,tiles,temp);
            ans+=s.size();
        }
        return ans;
    }
    

void solve(unordered_set<string> &s,int n,vector<bool> &v,string &tiles,string &temp)
    {
        if(n==0)
        {
            s.insert(temp);
            return;
        }
        for(int i=0;i<tiles.size();++i)
        {
            if(v[i]) continue;
            else
            {
                v[i]=1;
                temp+=tiles[i];
                solve(s,n-1,v,tiles,temp);
                temp.pop_back();
                v[i]=0;
            }
        }
    }
};
