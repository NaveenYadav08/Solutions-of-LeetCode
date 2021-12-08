// leetcpde - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// BINARY SEARCH


// CODE 

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start=0, end=0;
        
        for(int i=0; i<weights.size(); i++)
            end += weights[i];
        while(start<end)
        {
            int mid = start + (end-start)/2;
            if(check(weights, days, mid))
                end = mid;
            else
                start = mid+1;
        }
        return end;
    }
    
    bool check(vector<int>& w, int days, int mid)
    {
        int i=0, one=0, day=1;
        while(i<w.size())
        {
            if(one+w[i]<=mid)
                one += w[i++];
            else
            {
                one = 0;
                day++;
            }
            if(day>days)
                return false;
        }
        return true;
    }
};
