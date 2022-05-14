// LINK 
// CODE 

class Solution {
public:
    void solve(string &s,int l,int r)
    {
        if(s[l]=='L'&&s[r]=='R')
        {
        }
        else if(s[l]=='L'&&s[r]=='L')
        {
            for(int i=l+1;i<r;i++)
            {
                s[i]='L';
            }
        }
        else if(s[l]=='R'&&s[r]=='R')
        {
            for(int i=l+1;i<r;i++)
            {
                s[i]='R';
            }
        }
        
        
        else if(s[l]=='R'&&s[r]=='L')
        {
            int diff=(l-r);
            int mid=(l+r)/2;
            if(diff%2==0)
            {
                for(int i=l+1;i<mid;i++)
                {
                    s[i]='R';
                }
                for(int i=mid+1;i<r;i++)
                {
                    s[i]='L';
                }
            }
            else
            {
                for(int i=l+1;i<=mid;i++)
                {
                    s[i]='R';
                }
                for(int i=mid+1;i<r;i++)
                {
                    s[i]='L';
                }
            }
        }

    }
    
    
    string pushDominoes(string s) 
    {
        s='L'+s+'R';
        int n=s.size();
        int j=0;
        for(int i=0;i<n;)
        {
            while(s[i]=='.')
            {
                i++;
            }
            if(i-j>1)
            solve(s,j,i);
            j=i;
            i++;
        }
        return s.substr(1,s.size()-2);
    }
};
