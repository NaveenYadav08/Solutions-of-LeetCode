https://leetcode.com/problems/reorganize-string/
https://practice.geeksforgeeks.org/contest/coding-try-outs-amazon/problems



class Solution {
public:
     string reorganizeString(string s) {
        map<char,int>mp;
        for(int i=0; i<s.size(); i++)
            mp[s[i]]++;
        priority_queue<pair<int,char>>pq;
        for(auto x :mp)
            pq.push({x.second,x.first});
       
        string res="";
        while(pq.size()>1)
        {
            auto p=pq.top();
            pq.pop();
            auto q=pq.top();
                pq.pop();
                res+=p.second;
                res+=q.second;
                p.first--;
                q.first--;
                if(p.first>0)
                    pq.push(p);
                if(q.first>0)
                    pq.push(q);
        }
        if(!pq.empty()) {
            if(pq.top().first==1) res+=pq.top().second;
            else
                return "";
        }
          return res;  
        
    }
};
