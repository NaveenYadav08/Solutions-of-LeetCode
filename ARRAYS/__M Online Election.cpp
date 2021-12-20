//leetcode - https://leetcode.com/problems/online-election/

//Online Election

class TopVotedCandidate {
public:
    vector<int> time;
    vector<int> res;
    
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    time = times;
        vector<int> pers = persons;
        unordered_map<int,int> m;
        int maxvote=0;
        int per ;
        for(int i=0; i<persons.size(); i++)
        {
            int x = ++m[pers[i]];
            if(x>=maxvote)
            {
                maxvote=x;
                per=persons[i];
            }
            
            res.push_back(per);
        }
    
        
    }
    
    int q(int t) {
        
        int k = lower_bound(time.begin(),time.end(),t)-time.begin();
        if(t<=0 or k==0)
            return 0;
        else if(k==res.size())
            return res[k-1];
        
        if(time[k]!=t)
            k--;
        
        return res[k];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(tv);
 */
