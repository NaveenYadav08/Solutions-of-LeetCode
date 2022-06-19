https://leetcode.com/problems/ipo/



#define pp pair<int, int>
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pp, vector<pp>, greater<pp>> minCapital; 
        //  minheap for capital 
        priority_queue<pp> maxProfit;
        //  maxheap for profit 
        
        
        for(int i=0;i<profits.size();i++)  minCapital.push({capital[i], profits[i]});
        
        for(int i=0;i<k;i++)
        {
            while(!minCapital.empty() && minCapital.top().first <= w)
            {
                pp t = minCapital.top();
                minCapital.pop();
                maxProfit.push({t.second, t.first});
            }
            
            if(maxProfit.empty()) return w;
            
            w +=  maxProfit.top().first;
            maxProfit.pop();
        }
		
        return w;
    }
};
