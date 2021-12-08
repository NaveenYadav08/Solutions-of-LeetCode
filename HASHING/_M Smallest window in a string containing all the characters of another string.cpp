// GFG --  https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

// HASHING AND SLIDING WINDOW


// CODE 
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
   string smallestWindow (string s, string p)
    {
        // Your code here
        string ans ="";
        map<char,int> p1;
        for(int i=0;i<p.size();i++)
        {
            p1[p[i]]++;
        }
        
        int mct = 0;
        int dmct = p.size();
        
        map<char,int> s1;
        int i=-1;
        int j=-1;
        while(true)
        {   cout<<"jojo"<<endl;
            bool flag1=false;
            bool flag2=false;
            cout<<i<<"  "<<(s.size()-1)<<"  "<<mct<<" "<<dmct<<endl;
            int tt = (s.size()-1);
            while(i<(tt) && mct<dmct)
            {   cout<<"jojo"<<endl;
                i++;
                char ch = s[i];
                s1[ch]++;
                
                if(s1[ch]<=p1[ch])
                {
                    mct++;
                }
                flag1 = true;
            }
            
            while(j<i && mct == dmct)
            {
                string pans = s.substr(j+1,i);
                if(ans.size()==0 || pans.size()<ans.size())
                {
                    ans = pans;
                }
                j++;
                if(s1[s[j]]==1)
                {
                    s1.erase(s[j]);
                }
                else
                {
                    s1[s[j]]--;
                }
                
                if(s1[s[j]]<p1[s[j]])
                {
                    mct--;
                }
                flag2 = true;
            }
            if(flag1 == false && flag2==false)
            {
                break;
            }
        }
        cout<<endl<<ans<<endl;
        return ans;
    }
};
