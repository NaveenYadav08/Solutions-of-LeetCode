// LEETCODE - https://leetcode.com/problems/number-of-matching-subsequences/

// CODE 

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        unordered_map<char,vector<int>> m;
        
        int N=s.size();
        
        for(int i=0;i<N;i++)
        {
            m[s[i]].push_back(i);
            //cout<<s[i]<<endl;
        }
        
        int n=words.size();
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {   
            int index=-1;
            
            string SS=words[i];
            
            bool flag=true;
            
            for(int j=0;j<SS.size();j++)
            {
                if(m.find(SS[j])==m.end())
                { flag=false; break;}
                
                else
                {
auto it= upper_bound(m[SS[j]].begin(),m[SS[j]].end(), index);
                    if(it==m[SS[j]].end())
                    {
                        flag=false;
                        break;
                    }
                    
                    int kk=it-m[SS[j]].begin();
                    
                         
                        index=m[SS[j]][kk];
                    
                    
                }
            }
            
           if(flag==true)
             count++;
        }
        
        
        
        return count;
        
    }
};
